cmake_minimum_required(VERSION 3.10)


# project name
project(LET_FRAMEWORK
    LANGUAGES C
    VERSION 0.1
    DESCRIPTION "Light Embedded Testing Framework")

###############################
## begin FLAGS configuration ##
###############################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(GENERATED_COVERAGE_DIR "${CMAKE_BINARY_DIR}/src/CMakeFiles/${CMAKE_PROJECT_NAME}.dir/Core")
    set(CMAKE_C_FLAGS "-std=c99 -pedantic -O0 -g -Wall -Werror -Wno-pointer-sign -ffunction-sections -fdata-sections")
endif()

if(FILE_AND_LINE)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DFILE_AND_LINE")
endif()

if((FORMAT STREQUAL JUNIT) OR ONLY_FAILED_ASSERT)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DONLY_FAILED_ASSERT")
endif()

if((FORMAT STREQUAL JUNIT) OR STOP_TEST_ON_FAILED)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DSTOP_TEST_ON_FAILED")
endif()

if(MAX_TESTS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DMAX_TESTS=${MAX_TESTS}")
endif()

###############################
## end FLAGS configuration   ##
###############################

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
      add_custom_target(cleanrun
        COMMAND rm -f ${GENERATED_COVERAGE_DIR}/*.c.gcda
        COMMAND rm -f ${CMAKE_BINARY_DIR}/*.c.gcov
    )
    add_custom_target(cleangcov
        COMMAND rm -f ${GENERATED_COVERAGE_DIR}/*.c.gcno
        COMMAND ${CMAKE_MAKE_PROGRAM} cleanrun
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    add_custom_target(cleanall
        COMMAND ${CMAKE_MAKE_PROGRAM} clean
        COMMAND ${CMAKE_MAKE_PROGRAM} cleangcov
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
    )
    add_custom_target(gcov
        COMMAND gcov ${CMAKE_CURRENT_LIST_DIR}/src/*.c -o ${GENERATED_COVERAGE_DIR}/*.c.gcno -o ${GENERATED_COVERAGE_DIR}/*.c.gcda)
    add_subdirectory(test)
endif()
