cmake_minimum_required(VERSION 3.10)


##################################
## begin VARIABLE configuration ##
##################################
set(PROJECT_TEST_NAME "LET_FRAMEWORK_test")
set(TEST_FOLDER "${CMAKE_CURRENT_LIST_DIR}")
##################################
## end VARIABLE configuration   ##
##################################


add_executable(${PROJECT_TEST_NAME} main_test.c)
target_link_libraries(${PROJECT_TEST_NAME} LET_FRAMEWORK)