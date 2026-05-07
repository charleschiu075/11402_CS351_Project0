include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.tar.gz
    URL_HASH SHA256=8ad598c73ad796e0d8280b082cebd82a630d73e73cd3c70057938a6501bba5d7
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

add_executable(two_sum_tests test_two_sum.cpp)
target_link_libraries(two_sum_tests
    PRIVATE
        two_sum_lib
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(two_sum_tests)
