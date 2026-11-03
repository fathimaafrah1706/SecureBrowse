
#include "domain_blocker.h"

#include <gtest/gtest.h>
#include <fstream>
#include <cstdio>

class DomainBlockerTest : public ::testing::Test {
protected:
    DomainBlocker blocker;

    void SetUp() override {
        std::ofstream file("test_blocked_domains.txt");
        file << "malicious.example\n";
        file << "tracker.example\n";
        file.close();

        ASSERT_TRUE(blocker.loadFromFile("test_blocked_domains.txt"));
    }

    void TearDown() override {
        std::remove("test_blocked_domains.txt");
    }
};

TEST_F(DomainBlockerTest, BlocksExactDomain) {
    EXPECT_TRUE(blocker.isBlocked("malicious.example"));
}

TEST_F(DomainBlockerTest, BlocksSubdomain) {
    EXPECT_TRUE(blocker.isBlocked("sub.malicious.example"));
}

TEST_F(DomainBlockerTest, AllowsUnblockedDomain) {
    EXPECT_FALSE(blocker.isBlocked("google.com"));
}

TEST_F(DomainBlockerTest, IgnoresCase) {
    EXPECT_TRUE(blocker.isBlocked("MALICIOUS.EXAMPLE"));
}

TEST_F(DomainBlockerTest, RejectsUnconfiguredDomain) {
    EXPECT_FALSE(blocker.isBlocked("example.com"));
}

TEST_F(DomainBlockerTest, LoadsCorrectDomainCount) {
    EXPECT_EQ(blocker.size(), 2);
}
