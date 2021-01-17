cmake_minimum_required(VERSION 3.10)

# project name
set(PROJECT_NAME "LET_FRAMEWORK")

###############################
## begin CONST configuration ##
###############################
set(TEXT_FORMAT "TEXT_FORMAT")
set(JSON_FORMAT "JSON_FORMAT")
set(XML_FORMAT "XML_FORMAT")
set(CUSTOM_FORMAT "CUSTOM_FORMAT")

###############################
## end CONST configuration   ##
###############################


if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -coverage")
endif()


set(INCLUDE_FOLDER "${CMAKE_CURRENT_LIST_DIR}/../include")


if(FORMAT STREQUAL XML)
    set(FORMAT "xml")
elseif(FORMAT STREQUAL CUSTOM)
    set(FORMAT "custom")
else()
    if(NOT FORMAT STREQUAL TEXT)
        message("warning : FORMAT not specified or eronated default set to TEXT. Allowed value [JSON/XML/TEXT/CUSTOM] ")
    endif()
    set(FORMAT "text")
endif()

set(FORMAT_SOURCE_FOLDER "${CMAKE_CURRENT_LIST_DIR}/Data_Format/${FORMAT}/${FORMAT}_format.c")

include_directories(${INCLUDE_FOLDER}
                    ${CMAKE_CURRENT_LIST_DIR}/Core
                    ${CMAKE_CURRENT_LIST_DIR}/Data_Format/util
                    ${FORMAT_INCLUDE_FOLDER}
                )

add_library(${PROJECT_NAME} STATIC
            ${CMAKE_CURRENT_LIST_DIR}/Core/LET_Framework_Assert.c
            ${CMAKE_CURRENT_LIST_DIR}/Core/LET_Framework_Core.c
            ${CMAKE_CURRENT_LIST_DIR}/Data_Format/util/format_string.c
            ${FORMAT_SOURCE_FOLDER}
        )

set_target_properties(${PROJECT_NAME} PROPERTIES
            ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
            POSITION_INDEPENDENT_CODE ON
            COMPILE_FLAGS ${CMAKE_C_FLAGS}
        )

target_include_directories(${PROJECT_NAME} PUBLIC ${INCLUDE_FOLDER})
