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
#define LET_TESTSUITE_BALISE              "testsuite"
#define LET_TESTSUITES_BALISE              LET_TESTSUITE_BALISE "s"
#define LET_TESTSUITE_TESTNB_PARAMETER    "tests"
#define LET_TESTSUITE_NAME_PARAMETER      "name"

#define LET_TESTCASE_BALISE               "testcase"
#define LET_TESTCASE_NAME_PARAMETER       "name"
#define LET_TESTCASE_CLASSNAME_PARAMETER  "classname"

#define LET_FAILURE_BALISE                "failure"
#define LET_FAILURE_TYPE_PARAMETER        "type"
#define LET_FAILURE_MESSAGE_PARAMETER     "message"
#define LET_FAILURE_DATA_NEWLINE          "\n\t\t\t\t"
#define LET_FILE_PARAMETER_ASSERT         LET_FAILURE_DATA_NEWLINE "FILE : "
#define LET_LINE_PARAMETER_ASSERT         LET_FAILURE_DATA_NEWLINE "LINE : "
#define LET_COMPARE_PARAMETER_ASSERT      LET_FAILURE_DATA_NEWLINE "COMPARE : "
#define LET_EXPECTED_PARAMETER_ASSERT     LET_FAILURE_DATA_NEWLINE "EXPECTED : "
#define LET_OBTAINED_PARAMETER_ASSERT     LET_FAILURE_DATA_NEWLINE "OBTAINED : "
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
  LET_xml_open_balise(LET_TESTSUITES_BALISE, 1, 0, 0);
  LET_xml_close_balise(0);
}

void LET_end_printer(void){
  LET_xml_open_balise(LET_TESTSUITES_BALISE, 1, 0, 1);
  LET_xml_close_balise(0);
  LET_Framework_printer("\n");
}

void LET_service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\0'};
  LET_uint_to_decimal_string(number, test_number);
  LET_xml_open_balise(LET_TESTSUITE_BALISE, 1, 1, 0);
  LET_xml_add_parameter(LET_TESTSUITE_NAME_PARAMETER, name);
  LET_xml_add_parameter(LET_TESTSUITE_TESTNB_PARAMETER, number);
  LET_xml_close_balise(0);
}

void LET_service_end_printer(void){
  LET_xml_open_balise(LET_TESTSUITE_BALISE, 1, 1, 1);
  LET_xml_close_balise(0);
}

void LET_test_init_printer(char* name, char *service_name){
  LET_xml_open_balise(LET_TESTCASE_BALISE, 1, 2, 0);
  LET_xml_add_parameter(LET_TESTCASE_NAME_PARAMETER, name);
  LET_xml_add_parameter(LET_TESTCASE_CLASSNAME_PARAMETER, service_name);
  LET_xml_close_balise(0);
}

void LET_test_end_printer(void){
  LET_xml_open_balise(LET_TESTCASE_BALISE, 1, 2, 1);
  LET_xml_close_balise(0);
}

void LET_assert_printer(char *name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained
 #ifdef LET_FILE_AND_LINE
                  ,char *file
                  ,uint32_t line
 #endif
){
 #ifdef LET_FILE_AND_LINE
  char str_line[25] = {'\0'};
  LET_uint_to_decimal_string(str_line, line);
 #endif
  LET_xml_open_balise(LET_FAILURE_BALISE, 1, 3, 0);
  LET_xml_add_parameter(LET_FAILURE_MESSAGE_PARAMETER, name);
  LET_xml_add_parameter(LET_FAILURE_TYPE_PARAMETER, LET_ASSERT_TYPE_STRING[type]);
  LET_xml_close_balise(0);
 #ifdef LET_FILE_AND_LINE
  LET_Framework_printer(LET_FILE_PARAMETER_ASSERT);
  LET_Framework_printer(file);

  LET_Framework_printer(LET_LINE_PARAMETER_ASSERT);
  LET_Framework_printer(str_line);

 #endif

  LET_Framework_printer(LET_COMPARE_PARAMETER_ASSERT);
  LET_Framework_printer(LET_ASSERT_COMPARE_STRING[compare]);

  LET_Framework_printer(LET_EXPECTED_PARAMETER_ASSERT);
  LET_Framework_printer(expected);

  LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
  LET_Framework_printer(obtained);

  LET_xml_open_balise(LET_FAILURE_BALISE, 1, 3, 1);
  LET_xml_close_balise(0);
}
