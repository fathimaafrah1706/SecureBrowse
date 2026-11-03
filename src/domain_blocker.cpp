
#include "domain_blocker.h"

#include <algorithm>
#include <cctype>
#include <fstream>
#include <sstream>

std::string DomainBlocker::normalizeDomain(
    const std::string& domain
) {
    std::string normalized = domain;

    std::transform(
        normalized.begin(),
        normalized.end(),
        normalized.begin(),
        [](unsigned char ch) {
            return static_cast<char>(std::tolower(ch));
        }
    );

    while (!normalized.empty() && normalized.back() == '.') {
        normalized.pop_back();
    }

    return normalized;
}

bool DomainBlocker::isValidDomain(
    const std::string& domain
) {
    if (domain.empty() || domain.size() > 253) {
        return false;
    }

    std::stringstream stream(domain);
    std::string label;

    while (std::getline(stream, label, '.')) {

        if (label.empty() || label.size() > 63) {
            return false;
        }

        if (label.front() == '-' || label.back() == '-') {
            return false;
        }

        for (unsigned char ch : label) {
            if (!std::isalnum(ch) && ch != '-') {
                return false;
            }
        }
    }

    return domain.find('.') != std::string::npos;
}

DomainBlocker::DomainBlocker() = default;

bool DomainBlocker::loadFromFile(
    const std::string& filename
) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        return false;
    }

    blockedDomains.clear();

    std::string line;

    while (std::getline(file, line)) {

        // Remove comments.
        const std::size_t comment = line.find('#');

        if (comment != std::string::npos) {
            line.erase(comment);
        }

        // Trim whitespace.
        const auto first = line.find_first_not_of(" \t\r\n");

        if (first == std::string::npos) {
            continue;
        }

        const auto last = line.find_last_not_of(" \t\r\n");

        line = line.substr(first, last - first + 1);

        line = normalizeDomain(line);

        if (isValidDomain(line)) {
            blockedDomains.insert(line);
        }
    }

    return !file.bad();
}

void DomainBlocker::blockDomain(
    const std::string& domain
) {
    const std::string normalized = normalizeDomain(domain);

    if (isValidDomain(normalized)) {
        blockedDomains.insert(normalized);
    }
}

bool DomainBlocker::isBlocked(
    const std::string& domain
) const {
    const std::string normalized = normalizeDomain(domain);

    if (normalized.empty()) {
        return false;
    }

    for (const auto& blocked : blockedDomains) {

        if (normalized == blocked) {
            return true;
        }

        // Block subdomains too.
        if (normalized.size() > blocked.size() &&
            normalized.compare(
                normalized.size() - blocked.size(),
                blocked.size(),
                blocked
            ) == 0 &&
            normalized[normalized.size() - blocked.size() - 1] == '.') {
            return true;
        }
    }

    return false;
}

std::size_t DomainBlocker::size() const {
    return blockedDomains.size();
}
