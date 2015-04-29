find_package(Boost COMPONENTS unit_test_framework REQUIRED)
link_directories(${Boost_LIBRARY_DIRS})
add_definitions(-DBOOST_TEST_DYN_LINK)

find_package(DCMTK REQUIRED)
find_path(DCMTK_ROOT_INCLUDE_DIR "dcmtk/config/osconfig.h" PATHS ${DCMTK_INCLUDE_DIRS})

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

add_definitions("-D HAVE_CONFIG_H")

file(GLOB_RECURSE tests *.cpp)
foreach(test_file ${tests})
    get_filename_component(test ${test_file} NAME_WE)
    add_executable(${test} ${test_file})
    target_link_libraries(${test} dcmtkpp ${Boost_LIBRARIES})
    target_include_directories(${test} SYSTEM PRIVATE ${DCMTK_ROOT_INCLUDE_DIR} ${Boost_INCLUDE_DIR})
    file(READ ${test_file} content)

    set(pattern "BOOST_(AUTO|FIXTURE)_TEST_CASE\\(([^),]+)")

    string(REGEX MATCHALL ${pattern} cases ${content})

    foreach(case ${cases})
        string(REGEX REPLACE ${pattern} "\\2" case ${case})
        add_test("${test}_${case}" "${test}" "--run_test=${case}")
    endforeach()
endforeach()
