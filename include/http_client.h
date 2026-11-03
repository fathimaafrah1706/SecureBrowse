
#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include "domain_blocker.h"

struct HttpResponse {
    long statusCode = 0;
    std::string body;
    std::string error;
    bool success = false;
};

class HttpClient {
private:
    const DomainBlocker& blocker;

public:
    explicit HttpClient(const DomainBlocker& domainBlocker);

    HttpResponse get(const std::string& url);
};

#endif
