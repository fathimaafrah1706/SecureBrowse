
cmake_minimum_required(VERSION 3.20)

project(SecureBrowse VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()

find_package(CURL REQUIRED)
find_package(GTest CONFIG REQUIRED)
find_package(SQLite3 REQUIRED)

# Main application
add_executable(SecureBrowse
    main.cpp
    src/url_validator.cpp
    src/http_client.cpp
    src/domain_blocker.cpp
    src/request_logger.cpp
)

target_include_directories(SecureBrowse PRIVATE include)

target_link_libraries(SecureBrowse PRIVATE
    CURL::libcurl
    SQLite3::SQLite3
)

# URL Validator tests
add_executable(URLValidatorTests
    tests/url_validator_test.cpp
    src/url_validator.cpp
)

target_include_directories(URLValidatorTests PRIVATE include)

target_link_libraries(URLValidatorTests PRIVATE
    GTest::gtest_main
)

# Domain Blocker tests
add_executable(DomainBlockerTests
    tests/domain_blocker_test.cpp
    src/domain_blocker.cpp
)

target_include_directories(DomainBlockerTests PRIVATE include)

target_link_libraries(DomainBlockerTests PRIVATE
    GTest::gtest_main
)

# SQLite Request Logger tests
add_executable(RequestLoggerTests
    tests/request_logger_test.cpp
    src/request_logger.cpp
)

target_include_directories(RequestLoggerTests PRIVATE include)

target_link_libraries(RequestLoggerTests PRIVATE
    GTest::gtest_main
    SQLite3::SQLite3
)

include(GoogleTest)

gtest_discover_tests(URLValidatorTests)
gtest_discover_tests(DomainBlockerTests)
gtest_discover_tests(RequestLoggerTests)
