#include "request_logger.h"
#include <gtest/gtest.h>

TEST(RequestLoggerTest, InitializesDatabase) {
    RequestLogger logger("test_logger.db");
    EXPECT_TRUE(logger.isReady());
}