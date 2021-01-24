/*******************************************************************************
 ** File Name : junit_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +---------------------------------------------+
// | junit_format includes                       |
// +---------------------------------------------+
#include "stdint.h"

#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

// +---------------------------------------------+
// | junit_format macros                         |
// +---------------------------------------------+
#define TESTSUITE_BALISE              "testsuite"
#define TESTSUITE_TESTNB_PARAMETER    "tests"
#define TESTSUITE_NAME_PARAMETER      "name"

#define TESTCASE_BALISE               "testcase"
#define TESTCASE_NAME_PARAMETER       "name"
#define TESTCASE_CLASSNAME_PARAMETER  "classname"

#define FAILURE_BALISE                "failure"
#define FAILURE_TYPE_PARAMETER        "type"
#define FAILURE_MESSAGE_PARAMETER     "message"
#define FAILURE_DATA_NEWLINE          "\n\t\t\t\t"
#define FILE_PARAMETER_ASSERT         "FILE : "
#define LINE_PARAMETER_ASSERT         "LINE : "
#define TYPE_PARAMETER_ASSERT         "TYPE : "
#define COMPARE_PARAMETER_ASSERT      "COMPARE : "
#define EXPECTED_PARAMETER_ASSERT     "EXPECTED : "
#define OBTAINED_PARAMETER_ASSERT     "OBTAINED : "
#define VALID_PARAMETER_ASSERT        "VALID : "
// +---------------------------------------------+
// | junit_format types                          |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format variables                      |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format extern  functions definition   |
// +---------------------------------------------+
extern void LET_Framework_printer (const char * data);

// +---------------------------------------------+
// | junit_format private  functions declaration |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format private  functions definition  |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format public  functions definition   |
// +---------------------------------------------+
void LET_init_printer(void){
  LET_Framework_printer("\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
  open_balise(TESTSUITE_BALISE, 1, 0, 0);
  LET_Framework_printer("s");
  close_balise(0);
}

void LET_end_printer(void){
  open_balise(TESTSUITE_BALISE, 1, 0, 1);
  LET_Framework_printer("s");
  close_balise(0);
  LET_Framework_printer("\n");
}

void service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\0'};
  uint_to_decimal_string(number, test_number);
  open_balise(TESTSUITE_BALISE, 1, 1, 0);
  add_parameter(TESTSUITE_NAME_PARAMETER, name);
  add_parameter(TESTSUITE_TESTNB_PARAMETER, number);
  close_balise(0);
}

void service_end_printer(void){
  open_balise(TESTSUITE_BALISE, 1, 1, 1);
  close_balise(0);
}

void test_init_printer(char* name, char *service_name){
  open_balise(TESTCASE_BALISE, 1, 2, 0);
  add_parameter(TESTCASE_NAME_PARAMETER, name);
  add_parameter(TESTCASE_CLASSNAME_PARAMETER, service_name);
  close_balise(0);
}

void test_end_printer(ASSERT_RESULT result){
  open_balise(TESTCASE_BALISE, 1, 2, 1);
  close_balise(0);
}

void assert_printer(char *name,
                  ASSERT_TYPE type,
                  ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained,
                  ASSERT_RESULT result
 #ifdef FILE_AND_LINE
                  ,char *file
                  ,char *line
 #endif
){
  open_balise(FAILURE_BALISE, 1, 3, 0);
  add_parameter(FAILURE_MESSAGE_PARAMETER, name);
  add_parameter(FAILURE_TYPE_PARAMETER, ASSERT_TYPE_STRING[type]);
  close_balise(0);
  #ifdef FILE_AND_LINE
    LET_Framework_printer(FAILURE_DATA_NEWLINE);
    LET_Framework_printer(FILE_PARAMETER_ASSERT);
    LET_Framework_printer(file);

    LET_Framework_printer(FAILURE_DATA_NEWLINE);
    LET_Framework_printer(LINE_PARAMETER_ASSERT);
    LET_Framework_printer(line);

  #endif

  LET_Framework_printer(FAILURE_DATA_NEWLINE);
  LET_Framework_printer(COMPARE_PARAMETER_ASSERT);
  LET_Framework_printer(ASSERT_COMPARE_STRING[compare]);

  LET_Framework_printer(FAILURE_DATA_NEWLINE);
  LET_Framework_printer(EXPECTED_PARAMETER_ASSERT);
  LET_Framework_printer(expected);

  LET_Framework_printer(FAILURE_DATA_NEWLINE);
  LET_Framework_printer(OBTAINED_PARAMETER_ASSERT);
  LET_Framework_printer(obtained);

  LET_Framework_printer(FAILURE_DATA_NEWLINE);
  LET_Framework_printer(VALID_PARAMETER_ASSERT);
  LET_Framework_printer(ASSERT_RESULT_STRING[result]);

  open_balise(FAILURE_BALISE, 1, 3, 1);
  close_balise(0);
}
