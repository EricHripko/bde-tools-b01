cmake_minimum_required(VERSION 3.8)
project(bde-tools-windows)

configure_file(CMakeLists.txt.in bde-tools-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bde-tools-download)
if(result)
    message(FATAL_ERROR "CMake step for bde-tools failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
        RESULT_VARIABLE result
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/bde-tools-download)
if(result)
    message(FATAL_ERROR "Build step for bde-tools failed: ${result}")
endif()
list(APPEND CMAKE_MODULE_PATH  "${CMAKE_BINARY_DIR}/bde-tools/cmake/")

include_directories(${DISTRIBUTION_REFROOT}/opt/bb/include)

include(bde_workspace)

bde_process_workspace(
    ${CMAKE_CURRENT_LIST_DIR}
)

