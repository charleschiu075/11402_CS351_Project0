cmake_minimum_required(VERSION 3.16)
project(two_sum CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang|AppleClang")
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(two_sum_lib
    src/two_sum_array.cpp
    src/two_sum_hash.cpp
)
target_include_directories(two_sum_lib PUBLIC src)

add_executable(two_sum src/main.cpp)
target_link_libraries(two_sum PRIVATE two_sum_lib)

option(TWO_SUM_BUILD_TESTS "Build unit tests" ON)
if(TWO_SUM_BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
