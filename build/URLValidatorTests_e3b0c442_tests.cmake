add_test([=[URLValidatorTest.AcceptsValidHTTPS]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.AcceptsValidHTTPS]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.AcceptsValidHTTPS]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:5]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.AcceptsValidHTTP]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.AcceptsValidHTTP]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.AcceptsValidHTTP]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:9]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.RejectsUnsupportedProtocol]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.RejectsUnsupportedProtocol]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.RejectsUnsupportedProtocol]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:13]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.RejectsInvalidPort]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.RejectsInvalidPort]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.RejectsInvalidPort]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:17]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.RejectsTrailingDot]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.RejectsTrailingDot]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.RejectsTrailingDot]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:21]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.RejectsEmptyURL]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.RejectsEmptyURL]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.RejectsEmptyURL]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:25]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[URLValidatorTest.RejectsMalformedHostname]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/URLValidatorTests.exe [==[--gtest_filter=URLValidatorTest.RejectsMalformedHostname]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[URLValidatorTest.RejectsMalformedHostname]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\url_validator_test.cpp:29]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(URLValidatorTests_TESTS [==[URLValidatorTest.AcceptsValidHTTPS]==] [==[URLValidatorTest.AcceptsValidHTTP]==] [==[URLValidatorTest.RejectsUnsupportedProtocol]==] [==[URLValidatorTest.RejectsInvalidPort]==] [==[URLValidatorTest.RejectsTrailingDot]==] [==[URLValidatorTest.RejectsEmptyURL]==] [==[URLValidatorTest.RejectsMalformedHostname]==])
