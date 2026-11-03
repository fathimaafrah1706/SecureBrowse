#include "request_logger.h"
#include <gtest/gtest.h>
#include <sqlite3.h>
#include <cstdio>

TEST(RequestLoggerTest, InitializesDatabase) {
    RequestLogger logger("test_logger.db");
    EXPECT_TRUE(logger.isReady());
}

TEST(RequestLoggerTest, SavesSuccessfulRequest) {
    const char* dbPath = "test_logger.db";

    {
        RequestLogger logger(dbPath);
        ASSERT_TRUE(logger.isReady());

        EXPECT_TRUE(logger.logRequest(
            "https://example.com", 200, "SUCCESS"
        ));
    }

    sqlite3* db = nullptr;
    ASSERT_EQ(sqlite3_open(dbPath, &db), SQLITE_OK);

    sqlite3_stmt* stmt = nullptr;
    ASSERT_EQ(sqlite3_prepare_v2(
        db, "SELECT COUNT(*) FROM request_logs;",
        -1, &stmt, nullptr
    ), SQLITE_OK);

    ASSERT_EQ(sqlite3_step(stmt), SQLITE_ROW);
    EXPECT_EQ(sqlite3_column_int(stmt, 0), 1);

    sqlite3_finalize(stmt);
    sqlite3_close(db);
    std::remove(dbPath);
}

TEST(RequestLoggerTest, SavesBlockedRequest) {
    RequestLogger logger("test_logger.db");

    ASSERT_TRUE(logger.isReady());

    EXPECT_TRUE(logger.logRequest(
        "https://malicious.example", 0, "BLOCKED"
    ));
}