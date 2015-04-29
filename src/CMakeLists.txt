find_package(DCMTK REQUIRED)

file(GLOB_RECURSE SOURCE_FILES *.cpp)
file(GLOB_RECURSE HEADER_FILES *.h *.txx)

source_group("Header Files" FILES ${HEADER_FILES})
source_group("Source Files" FILES ${SOURCE_FILES})

include_directories(
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_definitions("-D HAVE_CONFIG_H")

add_library(dcmtkpp SHARED ${SOURCE_FILES} ${HEADER_FILES})
find_path(DCMTK_ROOT_INCLUDE_DIR dcmtk/config/osconfig.h PATHS
    ${DCMTK_DIR}/config/include
    ${DCMTK_DIR}/include
)
target_include_directories(dcmtkpp SYSTEM PRIVATE ${DCMTK_ROOT_INCLUDE_DIR})

target_link_libraries(dcmtkpp
    ${DCMTK_config_LIBRARY}
    ${DCMTK_dcmnet_LIBRARY}
    ${DCMTK_dcmdata_LIBRARY}
    ${DCMTK_ofstd_LIBRARY}
)

if(WIN32)
  target_link_libraries(dcmtkpp wsock32 ws2_32)
endif()


include(GenerateExportHeader)
set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_VISIBILITY_INLINES_HIDDEN 1)
generate_export_header(dcmtkpp)


install(TARGETS dcmtkpp DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
install(FILES ${HEADER_FILES} ${CMAKE_CURRENT_BINARY_DIR}/dcmtkpp_export.h 
        DESTINATION ${CMAKE_INSTALL_PREFIX}/include
)
