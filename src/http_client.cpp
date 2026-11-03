
#include "http_client.h"
#include "url_validator.h"

#include <curl/curl.h>

#include <mutex>
#include <string>

namespace {

std::once_flag curlInitFlag;
CURLcode curlInitResult = CURLE_FAILED_INIT;

constexpr std::size_t MAX_RESPONSE_SIZE = 1024 * 1024; // 1 MB

struct WriteContext {
    std::string body;
    bool sizeExceeded = false;
};

void initializeCurl() {
    curlInitResult = curl_global_init(CURL_GLOBAL_DEFAULT);
}

std::string extractHostname(const std::string& url) {

    const std::size_t schemeEnd = url.find("://");

    if (schemeEnd == std::string::npos) {
        return "";
    }

    const std::size_t start = schemeEnd + 3;

    const std::size_t end = url.find_first_of("/?#", start);

    std::string authority = url.substr(start, end - start);

    const std::size_t colon = authority.find(':');

    return authority.substr(0, colon);
}

size_t writeCallback(
    char* data,
    size_t size,
    size_t count,
    void* userData
) {

    if (size != 0 && count > static_cast<size_t>(-1) / size) {
        return 0;
    }

    const size_t total = size * count;

    auto* context = static_cast<WriteContext*>(userData);

    if (total > MAX_RESPONSE_SIZE - context->body.size()) {
        context->sizeExceeded = true;
        return 0;
    }

    context->body.append(data, total);

    return total;
}

} // namespace

HttpClient::HttpClient(const DomainBlocker& domainBlocker)
    : blocker(domainBlocker) {
}

HttpResponse HttpClient::get(const std::string& url) {

    HttpResponse response;

    // Step 1: Validate URL.
    if (!URLValidator::isValid(url)) {
        response.error = "Invalid URL format";
        return response;
    }

    // Step 2: Extract hostname.
    const std::string hostname = extractHostname(url);

    if (hostname.empty()) {
        response.error = "Unable to extract hostname";
        return response;
    }

    // Step 3: Check domain blocking policy.
    if (blocker.isBlocked(hostname)) {
        response.error = "Domain blocked by SecureBrowse policy";
        return response;
    }

    // Step 4: Initialize libcurl once.
    std::call_once(curlInitFlag, initializeCurl);

    if (curlInitResult != CURLE_OK) {
        response.error = "Failed to initialize libcurl";
        return response;
    }

    CURL* curl = curl_easy_init();

    if (!curl) {
        response.error = "Failed to create HTTP client";
        return response;
    }

    WriteContext context;

    char errorBuffer[CURL_ERROR_SIZE] = {};

    // Request configuration.
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &context);

    // TLS certificate verification.
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2L);

    // Restrict protocols.
    curl_easy_setopt(curl, CURLOPT_PROTOCOLS_STR, "http,https");

    // Connection and total timeouts.
    curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 20L);

    // Prevent signal-related behavior.
    curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

    // Do not automatically follow redirects.
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 0L);

    // Identify the application.
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "SecureBrowse/1.0");

    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);

    // Step 5: Perform request.
    const CURLcode result = curl_easy_perform(curl);

    if (result == CURLE_OK) {

        curl_easy_getinfo(
            curl,
            CURLINFO_RESPONSE_CODE,
            &response.statusCode
        );

        response.body = context.body;
        response.success = true;

    } else {

        if (context.sizeExceeded) {
            response.error = "Response exceeded 1 MB limit";
        }
        else {
            response.error = errorBuffer[0]
                ? errorBuffer
                : curl_easy_strerror(result);
        }
    }

    curl_easy_cleanup(curl);

    return response;
}
