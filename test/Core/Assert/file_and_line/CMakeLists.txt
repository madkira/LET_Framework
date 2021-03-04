cmake_minimum_required(VERSION 3.10)


##################################
## begin VARIABLE configuration ##
##################################
set(PROJECT_TEST_NAME "LET_FRAMEWORK_assert_junit_test")
set(TEST_FOLDER "${CMAKE_CURRENT_LIST_DIR}")
set(ROOT_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../../../..)
set(TEST_UTIL_FOLDER ${ROOT_FOLDER}/src/Data_Format/util)
set(CORE_FOLDER ${ROOT_FOLDER}/src/Core)
##################################
## end VARIABLE configuration   ##
##################################

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLET_FILE_AND_LINE")
set(INCLUDE_FOLDER ${ROOT_FOLDER}/include ${TEST_UTIL_FOLDER} ${CORE_FOLDER})

include_directories(${INCLUDE_FOLDER})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs")

add_executable(${PROJECT_TEST_NAME} core.test.c
                ${CORE_FOLDER}/LET_Framework_Assert.c)