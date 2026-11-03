
#include "url_validator.h"

#include <cctype>
#include <string>

namespace {

bool isValidHostname(const std::string& host) {

    if (host.empty() || host.size() > 253) {
        return false;
    }

    if (host.front() == '.' || host.back() == '.') {
        return false;
    }

    std::string label;

    for (char ch : host) {

        if (ch == '.') {

            if (label.empty() || label.size() > 63 ||
                label.front() == '-' || label.back() == '-') {
                return false;
            }

            label.clear();
        }
        else if (std::isalnum(static_cast<unsigned char>(ch)) ||
                 ch == '-') {
            label += ch;
        }
        else {
            return false;
        }
    }

    return !label.empty() &&
           label.size() <= 63 &&
           label.front() != '-' &&
           label.back() != '-';
}

bool isValidPort(const std::string& port) {

    if (port.empty() || port.size() > 5) {
        return false;
    }

    int value = 0;

    for (char ch : port) {

        if (!std::isdigit(static_cast<unsigned char>(ch))) {
            return false;
        }

        value = value * 10 + (ch - '0');
    }

    return value >= 1 && value <= 65535;
}

} // namespace

bool URLValidator::isValid(const std::string& url) {

    if (url.empty()) {
        return false;
    }

    // Reject whitespace and control characters.
    for (unsigned char ch : url) {
        if (std::isspace(ch) || std::iscntrl(ch)) {
            return false;
        }
    }

    // Only HTTP and HTTPS are supported.
    std::string scheme;

    const std::size_t separator = url.find("://");

    if (separator == std::string::npos) {
        return false;
    }

    scheme = url.substr(0, separator);

    if (scheme != "http" && scheme != "https") {
        return false;
    }

    // Extract authority (hostname and optional port).
    const std::size_t authorityStart = separator + 3;

    const std::size_t authorityEnd =
        url.find_first_of("/?#", authorityStart);

    const std::string authority =
        url.substr(authorityStart, authorityEnd - authorityStart);

    if (authority.empty() || authority.find('@') != std::string::npos) {
        return false;
    }

    // Reject IPv6 literals in this initial implementation.
    if (authority.find('[') != std::string::npos ||
        authority.find(']') != std::string::npos) {
        return false;
    }

    const std::size_t colon = authority.find(':');

    const std::string hostname =
        authority.substr(0, colon);

    if (!isValidHostname(hostname)) {
        return false;
    }

    // Validate optional port.
    if (colon != std::string::npos) {

        if (authority.find(':', colon + 1) != std::string::npos) {
            return false;
        }

        const std::string port =
            authority.substr(colon + 1);

        if (!isValidPort(port)) {
            return false;
        }
    }

    return true;
}
