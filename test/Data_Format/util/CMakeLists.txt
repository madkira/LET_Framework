cmake_minimum_required(VERSION 3.10)


##################################
## begin VARIABLE configuration ##
##################################
set(PROJECT_TEST_NAME "LET_FRAMEWORK_util_test")
set(TEST_FOLDER "${CMAKE_CURRENT_LIST_DIR}")
set(SRC_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../../../src)
set(TEST_UTIL_FOLDER ${SRC_FOLDER}/Data_Format/util)
##################################
## end VARIABLE configuration   ##
##################################


set(INCLUDE_FOLDER ${CMAKE_CURRENT_LIST_DIR}/../../../include ${SRC_FOLDER}/Core ${TEST_UTIL_FOLDER})

include_directories(${INCLUDE_FOLDER})

set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs")

add_executable(${PROJECT_TEST_NAME} util.test.c
				${TEST_UTIL_FOLDER}/LET_util_xml_format.c
				${TEST_UTIL_FOLDER}/LET_util_format_string.c
				${TEST_UTIL_FOLDER}/LET_util_json_format.c)