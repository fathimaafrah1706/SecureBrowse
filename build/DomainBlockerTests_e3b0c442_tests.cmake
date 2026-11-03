add_test([=[DomainBlockerTest.BlocksExactDomain]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.BlocksExactDomain]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.BlocksExactDomain]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:26]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DomainBlockerTest.BlocksSubdomain]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.BlocksSubdomain]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.BlocksSubdomain]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:30]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DomainBlockerTest.AllowsUnblockedDomain]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.AllowsUnblockedDomain]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.AllowsUnblockedDomain]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:34]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DomainBlockerTest.IgnoresCase]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.IgnoresCase]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.IgnoresCase]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:38]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DomainBlockerTest.RejectsUnconfiguredDomain]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.RejectsUnconfiguredDomain]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.RejectsUnconfiguredDomain]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:42]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
add_test([=[DomainBlockerTest.LoadsCorrectDomainCount]=]  C:/Users/AFRAH/Downloads/SecureBrowse/build/DomainBlockerTests.exe [==[--gtest_filter=DomainBlockerTest.LoadsCorrectDomainCount]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[DomainBlockerTest.LoadsCorrectDomainCount]=]
  PROPERTIES
    
    DEF_SOURCE_LINE [==[C:\Users\AFRAH\Downloads\SecureBrowse\tests\domain_blocker_test.cpp:46]==]
    WORKING_DIRECTORY [==[C:/Users/AFRAH/Downloads/SecureBrowse/build]==]
    SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==]
    
)
set(DomainBlockerTests_TESTS [==[DomainBlockerTest.BlocksExactDomain]==] [==[DomainBlockerTest.BlocksSubdomain]==] [==[DomainBlockerTest.AllowsUnblockedDomain]==] [==[DomainBlockerTest.IgnoresCase]==] [==[DomainBlockerTest.RejectsUnconfiguredDomain]==] [==[DomainBlockerTest.LoadsCorrectDomainCount]==])
