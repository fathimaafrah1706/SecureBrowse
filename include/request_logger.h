
#ifndef REQUEST_LOGGER_H
#define REQUEST_LOGGER_H

#include <string>
#include <sqlite3.h>

class RequestLogger {
private:
    sqlite3* database = nullptr;

public:
    explicit RequestLogger(const std::string& databasePath);

    ~RequestLogger();

    RequestLogger(const RequestLogger&) = delete;
    RequestLogger& operator=(const RequestLogger&) = delete;

    bool isReady() const;

    bool logRequest(
        const std::string& url,
        long statusCode,
        const std::string& outcome
    );
};

#endif
