cmake_minimum_required(VERSION 2.8)
project("dcmtkpp")

include(CTest)

add_subdirectory("src")

option(BUILD_EXAMPLES "Build dcmtkpp examples." OFF)
option(BUILD_TESTING "Build dcmtkpp tests." OFF)

if(BUILD_EXAMPLES)
    add_subdirectory("examples")
endif()

if(BUILD_TESTING)
    add_subdirectory("tests")
endif()
