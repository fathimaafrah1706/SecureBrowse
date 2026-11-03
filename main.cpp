
#include <iostream>
#include <string>

#include "url_validator.h"
#include "domain_blocker.h"
#include "http_client.h"
#include "request_logger.h"

int main() {

    std::cout << "================================\n";
    std::cout << "       SECUREBROWSE ENGINE      \n";
    std::cout << "================================\n";

    // Initialize SQLite logger.
    RequestLogger logger("database/securebrowse.db");

    if (!logger.isReady()) {
        std::cerr << "[ERROR] Database initialization failed.\n";
        return 1;
    }

    // Load blocked domains.
    DomainBlocker blocker;

    if (!blocker.loadFromFile("config/blocked_domains.txt")) {
        std::cerr << "[ERROR] Could not load domain configuration.\n";
        return 1;
    }

    std::cout << "[INFO] Loaded "
              << blocker.size()
              << " blocked domains.\n";

    HttpClient client(blocker);

    std::string url;

    std::cout << "\nEnter URL: ";
    std::getline(std::cin, url);

    // URL validation.
    if (!URLValidator::isValid(url)) {

        std::cout << "\n[BLOCKED] Invalid URL format.\n";

        logger.logRequest(url, 0, "INVALID_URL");

        return 1;
    }

    std::cout << "\n[VALID] URL accepted.\n";
    std::cout << "[INFO] Checking domain policy...\n";

    // Perform request.
    HttpResponse response = client.get(url);

    if (response.success) {

        std::cout << "\n[REQUEST SUCCESSFUL]\n";

        std::cout << "HTTP Status: "
                  << response.statusCode << "\n";

        std::cout << "\nResponse preview:\n";

        std::cout << response.body.substr(0, 1000)
                  << "\n";

        logger.logRequest(
            url,
            response.statusCode,
            "SUCCESS"
        );

    } else {

        std::cout << "\n[REQUEST BLOCKED / FAILED]\n";

        std::cout << "Reason: "
                  << response.error << "\n";

        const std::string outcome =
            response.error.find("blocked") != std::string::npos
                ? "BLOCKED"
                : "FAILED";

        logger.logRequest(url, 0, outcome);
    }

    std::cout << "\n[DATABASE] Request log saved.\n";

    std::cout << "\n================================\n";
    std::cout << "       SECUREBROWSE END         \n";
    std::cout << "================================\n";

    return 0;
}
