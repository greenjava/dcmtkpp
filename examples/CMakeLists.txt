find_package(DCMTK REQUIRED)
find_path(DCMTK_ROOT_INCLUDE_DIR "dcmtk/config/osconfig.h" PATHS ${DCMTK_INCLUDE_DIRS})

add_definitions("-D HAVE_CONFIG_H")

include_directories(
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_BINARY_DIR}/src
)

set(examples find get move store)

foreach(example ${examples})
    add_executable(${example} ${example}.cpp)
    target_link_libraries(${example} dcmtkpp ${DCMTK_dcmdata_LIBRARY})
    if(WIN32)
        target_link_libraries(${example} wsock32 ws2_32)
    endif()
    target_include_directories(${example} SYSTEM PRIVATE ${DCMTK_ROOT_INCLUDE_DIR})
endforeach()
