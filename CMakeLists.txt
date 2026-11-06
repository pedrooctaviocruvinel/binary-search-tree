cmake_minimum_required(VERSION 3.20)

project(BinarySearchTree VERSION 1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

file(GLOB_RECURSE PROJECT_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/src/*.c"
)

list(FILTER PROJECT_SOURCES EXCLUDE REGEX ".*/main\\.c$")

add_executable(binary-search-tree
    src/main.c
    ${PROJECT_SOURCES}
)

target_include_directories(binary-search-tree 
    PRIVATE include
)

include(FetchContent)

FetchContent_Declare(Unity
    GIT_REPOSITORY https://github.com/ThrowTheSwitch/Unity.git
    GIT_TAG v2.7.0
)

FetchContent_MakeAvailable(Unity)

file(GLOB_RECURSE TEST_SOURCES CONFIGURE_DEPENDS
    "${CMAKE_CURRENT_SOURCE_DIR}/tests/*.c"
)

add_executable(test_binary_search_tree
    ${TEST_SOURCES}
    ${PROJECT_SOURCES}
)

target_include_directories(test_binary_search_tree
    PRIVATE include
)

target_link_libraries(test_binary_search_tree
    PRIVATE unity
)

enable_testing()

add_test(
    NAME BinarySearchTreeTests
    COMMAND test_binary_search_tree
)

add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} --output-on-failure
    DEPENDS test_binary_search_tree
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)
