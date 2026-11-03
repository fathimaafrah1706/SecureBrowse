
#include "url_validator.h"
#include <gtest/gtest.h>

TEST(URLValidatorTest, AcceptsValidHTTPS) {
    EXPECT_TRUE(URLValidator::isValid("https://google.com"));
}

TEST(URLValidatorTest, AcceptsValidHTTP) {
    EXPECT_TRUE(URLValidator::isValid("http://example.com"));
}

TEST(URLValidatorTest, RejectsUnsupportedProtocol) {
    EXPECT_FALSE(URLValidator::isValid("ftp://example.com"));
}

TEST(URLValidatorTest, RejectsInvalidPort) {
    EXPECT_FALSE(URLValidator::isValid("https://example.com:99999"));
}

TEST(URLValidatorTest, RejectsTrailingDot) {
    EXPECT_FALSE(URLValidator::isValid("https://google.com."));
}

TEST(URLValidatorTest, RejectsEmptyURL) {
    EXPECT_FALSE(URLValidator::isValid(""));
}

TEST(URLValidatorTest, RejectsMalformedHostname) {
    EXPECT_FALSE(URLValidator::isValid("https://-invalid.com"));
}
