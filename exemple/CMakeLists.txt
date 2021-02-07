cmake_minimum_required(VERSION 3.10)


##################################
## begin VARIABLE configuration ##
##################################
set(PROJECT_TEST_NAME "LET_FRAMEWORK_exemple")
set(TEST_FOLDER "${CMAKE_CURRENT_LIST_DIR}")
##################################
## end VARIABLE configuration   ##
##################################



set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -fprofile-arcs")

add_executable(${PROJECT_TEST_NAME} main_exemple.c)

target_link_libraries(${PROJECT_TEST_NAME} LET_FRAMEWORK)