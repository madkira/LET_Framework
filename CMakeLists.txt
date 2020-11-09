cmake_minimum_required(VERSION 3.10)


# project name
project(LET_FRAMEWORK
    LANGUAGES C
    VERSION 0.1
    DESCRIPTION "to be announced")

###############################
## begin FLAGS configuration ##
###############################
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set(CMAKE_C_FLAGS "-std=c11 -pedantic -O0 -g -Wall -Werror -Wno-pointer-sign -ffunction-sections -fdata-sections")
endif()

###############################
## end FLAGS configuration   ##
###############################

add_subdirectory(src)

if((CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME OR MODERN_CMAKE_BUILD_TESTING) AND BUILD_TESTING)
    add_subdirectory(test)
endif()
