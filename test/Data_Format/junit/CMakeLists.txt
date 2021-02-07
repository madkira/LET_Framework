cmake_minimum_required(VERSION 3.10)


##################################
## begin VARIABLE configuration ##
##################################
set(PROJECT_TEST_NAME "LET_FRAMEWORK_junit_test")
set(TEST_FOLDER "${CMAKE_CURRENT_LIST_DIR}")
set(SRC_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../../../src)
set(TEST_UTIL_FOLDER ${SRC_FOLDER}/Data_Format/util)
set(TEST_JUNIT_FOLDER ${SRC_FOLDER}/Data_Format/junit)
##################################
## end VARIABLE configuration   ##
##################################

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -DLET_JUNIT -DLET_FILE_AND_LINE")
set(INCLUDE_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../../../include ${SRC_FOLDER}/Core ${TEST_UTIL_FOLDER})

include_directories(${INCLUDE_FOLDER})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs")

add_executable(${PROJECT_TEST_NAME} junit.test.c
				${TEST_JUNIT_FOLDER}/LET_junit_format.c)