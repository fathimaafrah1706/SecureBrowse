
#include "request_logger.h"

#include <iostream>

RequestLogger::RequestLogger(const std::string& databasePath) {

    int result = sqlite3_open(databasePath.c_str(), &database);

    if (result != SQLITE_OK) {
        std::cerr << "[DATABASE ERROR] "
                  << (database ? sqlite3_errmsg(database) : "Unable to open database")
                  << "\n";

        if (database) {
            sqlite3_close(database);
            database = nullptr;
        }

        return;
    }

    const char* createTable = R"(
        CREATE TABLE IF NOT EXISTS request_logs (
            id INTEGER PRIMARY KEY AUTOINCREMENT,
            timestamp TEXT DEFAULT CURRENT_TIMESTAMP,
            domain TEXT NOT NULL,
            status_code INTEGER,
            outcome TEXT NOT NULL
        );
    )";

    char* errorMessage = nullptr;

    result = sqlite3_exec(
        database,
        createTable,
        nullptr,
        nullptr,
        &errorMessage
    );

    if (result != SQLITE_OK) {
        std::cerr << "[DATABASE ERROR] "
                  << (errorMessage ? errorMessage : "Table creation failed")
                  << "\n";

        sqlite3_free(errorMessage);
        sqlite3_close(database);
        database = nullptr;
        return;
    }

    std::cout << "[DATABASE] Request logging initialized.\n";
}

RequestLogger::~RequestLogger() {

    if (database) {
        sqlite3_close(database);
        database = nullptr;
    }
}

bool RequestLogger::isReady() const {
    return database != nullptr;
}

bool RequestLogger::logRequest(
    const std::string& url,
    long statusCode,
    const std::string& outcome
) {

    if (!database) {
        return false;
    }

    // Extract hostname without logging URL credentials or paths.
    const std::size_t schemeEnd = url.find("://");

    if (schemeEnd == std::string::npos) {
        return false;
    }

    const std::size_t start = schemeEnd + 3;
    const std::size_t end = url.find_first_of("/?#", start);

    std::string authority = url.substr(start, end - start);

    const std::size_t colon = authority.find(':');

    std::string domain = authority.substr(0, colon);

    const char* insertSQL = R"(
        INSERT INTO request_logs
        (domain, status_code, outcome)
        VALUES (?, ?, ?);
    )";

    sqlite3_stmt* statement = nullptr;

    if (sqlite3_prepare_v2(
        database,
        insertSQL,
        -1,
        &statement,
        nullptr
    ) != SQLITE_OK) {
        return false;
    }

    sqlite3_bind_text(
        statement, 1, domain.c_str(), -1, SQLITE_TRANSIENT
    );

    sqlite3_bind_int64(statement, 2, statusCode);

    sqlite3_bind_text(
        statement, 3, outcome.c_str(), -1, SQLITE_TRANSIENT
    );

    const int result = sqlite3_step(statement);

    sqlite3_finalize(statement);

    return result == SQLITE_DONE;
}
