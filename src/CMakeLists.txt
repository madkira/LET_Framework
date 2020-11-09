cmake_minimum_required(VERSION 3.10)

# project name
set(PROJECT_NAME "LET_FRAMEWORK")

set(INCLUDE_FOLDER "${CMAKE_CURRENT_LIST_DIR}/../include")


include_directories(${INCLUDE_FOLDER} ${CMAKE_CURRENT_LIST_DIR}/Core ${CMAKE_CURRENT_LIST_DIR}/Data_Format/text ${CMAKE_CURRENT_LIST_DIR}/Data_Format/util)

add_library(${PROJECT_NAME} STATIC
            ${CMAKE_CURRENT_LIST_DIR}/Core/LET_Framework_Assert.c
            ${CMAKE_CURRENT_LIST_DIR}/Core/LET_Framework_Core.c
            ${CMAKE_CURRENT_LIST_DIR}/Data_Format/text/text_format.c
            ${CMAKE_CURRENT_LIST_DIR}/Data_Format/util/format_string.c
        )

set_target_properties(${PROJECT_NAME} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
            POSITION_INDEPENDENT_CODE ON
            COMPILE_FLAGS ${CMAKE_C_FLAGS}
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_FOLDER})
