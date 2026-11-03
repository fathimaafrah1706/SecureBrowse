
#ifndef DOMAIN_BLOCKER_H
#define DOMAIN_BLOCKER_H

#include <string>
#include <unordered_set>

class DomainBlocker {
private:
    std::unordered_set<std::string> blockedDomains;

    static std::string normalizeDomain(const std::string& domain);
    static bool isValidDomain(const std::string& domain);

public:
    DomainBlocker();

    bool loadFromFile(const std::string& filename);

    void blockDomain(const std::string& domain);

    bool isBlocked(const std::string& domain) const;

    std::size_t size() const;
};

#endif
