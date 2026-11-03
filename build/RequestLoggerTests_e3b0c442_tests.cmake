add_test([=[RequestLoggerTest.InitializesDatabase]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/RequestLoggerTests.exe [==[--gtest_filter=RequestLoggerTest.InitializesDatabase]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RequestLoggerTest.InitializesDatabase]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\request_logger_test.cpp:6]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[RequestLoggerTest.SavesSuccessfulRequest]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/RequestLoggerTests.exe [==[--gtest_filter=RequestLoggerTest.SavesSuccessfulRequest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RequestLoggerTest.SavesSuccessfulRequest]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\request_logger_test.cpp:11]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[RequestLoggerTest.SavesBlockedRequest]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/RequestLoggerTests.exe [==[--gtest_filter=RequestLoggerTest.SavesBlockedRequest]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[RequestLoggerTest.SavesBlockedRequest]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\request_logger_test.cpp:40]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(RequestLoggerTests_TESTS [==[RequestLoggerTest.InitializesDatabase]==] [==[RequestLoggerTest.SavesSuccessfulRequest]==] [==[RequestLoggerTest.SavesBlockedRequest]==])
