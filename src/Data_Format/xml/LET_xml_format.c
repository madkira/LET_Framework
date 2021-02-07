/*******************************************************************************
 ** File Name : xml_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +------------------------------------------+
// | xml_format includes                      |
// +------------------------------------------+
#include "stdint.h"

#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

// +------------------------------------------+
// | xml_format macros                        |
// +------------------------------------------+
#define LET_BALISE_LET_RUN "LET_RUN"

#define LET_BALISE_SERVICE "SERVICE"
#define LET_NAME_PARAMETER_SERVICE "S_NAME"
#define LET_NB_TEST_PARAMETER_SERVICE "NB_TEST"

#define LET_BALISE_TEST "TEST"
#define LET_NAME_PARAMETER_TEST "T_NAME"

#define LET_BALISE_RESULT "RESULT"
#define LET_RESULT_OK "PASSED"
#define LET_RESULT_KO "FAILED"

#define LET_BALISE_ASSERT "ASSERT"
#define LET_NAME_PARAMETER_ASSERT "A_NAME"
#define LET_FILE_PARAMETER_ASSERT "FILE"
#define LET_LINE_PARAMETER_ASSERT "LINE"
#define LET_TYPE_PARAMETER_ASSERT "TYPE"
#define LET_COMPARE_PARAMETER_ASSERT "COMPARE"
#define LET_EXPECTED_PARAMETER_ASSERT "EXPECTED"
#define LET_OBTAINED_PARAMETER_ASSERT "OBTAINED"
#define LET_VALID_PARAMETER_ASSERT "VALID"



#define LET_BALISE_ANNOTATION "NOTE"
#define LET_BALISE_ERROR "ERROR"


// +------------------------------------------+
// | xml_format types                         |
// +------------------------------------------+
/*Not Used*/

// +------------------------------------------+
// | xml_format variables                     |
// +------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | xml_format extern functions               |
// +-------------------------------------------+
extern void LET_Framework_printer(const char * data);

// +------------------------------------------+
// | xml_format private functions declaration |
// +------------------------------------------+
/*Not Used*/

// +------------------------------------------+
// | xml_format private functions definition  |
// +------------------------------------------+
/*Not Used*/

// +-----------------------------------------+
// | xml_format public functions definition  |
// +-----------------------------------------+
void LET_init_printer(void){
  LET_xml_open_balise(LET_BALISE_LET_RUN, 0, 0, 0);
  LET_xml_close_balise(0);
}

void LET_end_printer(void){
  LET_xml_open_balise(LET_BALISE_LET_RUN, 1, 0, 1);
  LET_xml_close_balise(0);
  LET_Framework_printer("\n");
}

void LET_service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\0'};
  LET_uint_to_decimal_string(number, test_number);
  LET_xml_open_balise(LET_BALISE_SERVICE, 1, 1, 0);
  LET_xml_add_parameter(LET_NAME_PARAMETER_SERVICE, name);
  LET_xml_add_parameter(LET_NB_TEST_PARAMETER_SERVICE, number);
  LET_xml_close_balise(0);
}

void LET_service_end_printer(void){
  LET_xml_open_balise(LET_BALISE_SERVICE, 1, 1, 1);
  LET_xml_close_balise(0);
}

void LET_test_init_printer(char* name){
  LET_xml_open_balise(LET_BALISE_TEST, 1, 2, 0);
  LET_xml_add_parameter(LET_NAME_PARAMETER_TEST, name);
  LET_xml_close_balise(0);
}

void LET_test_end_printer(LET_ASSERT_RESULT result){
  LET_xml_open_balise(LET_BALISE_RESULT, 1, 3, 0);
  LET_xml_close_balise(0);
  LET_Framework_printer((LET_OK==result)?LET_RESULT_OK:LET_RESULT_KO);
  LET_xml_open_balise(LET_BALISE_RESULT, 0, 0, 1);
  LET_xml_close_balise(0);
  LET_xml_open_balise(LET_BALISE_TEST, 1, 2, 1);
  LET_xml_close_balise(0);
}

void LET_assert_printer(char *name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained,
                  LET_ASSERT_RESULT result
 #ifdef LET_FILE_AND_LINE
                  ,char *file
                  ,uint32_t line
 #endif
){
 #ifdef LET_FILE_AND_LINE
  char str_line[25];
  LET_uint_to_decimal_string(str_line, line);
 #endif
  LET_xml_open_balise(LET_BALISE_ASSERT, 1, 3, 0);
 #ifdef LET_FILE_AND_LINE
  LET_xml_add_parameter(FILE_PARAMETER_ASSERT, file);
  LET_xml_add_parameter(LINE_PARAMETER_ASSERT, str_line);
 #endif
  LET_xml_add_parameter(LET_NAME_PARAMETER_ASSERT, name);
  LET_xml_add_parameter(LET_TYPE_PARAMETER_ASSERT, LET_ASSERT_TYPE_STRING[type]);
  LET_xml_add_parameter(LET_COMPARE_PARAMETER_ASSERT, LET_ASSERT_COMPARE_STRING[compare]);
  LET_xml_add_parameter(LET_EXPECTED_PARAMETER_ASSERT, expected);
  LET_xml_add_parameter(LET_OBTAINED_PARAMETER_ASSERT, obtained);
  LET_xml_add_parameter(LET_VALID_PARAMETER_ASSERT, LET_ASSERT_RESULT_STRING[result]);
  LET_xml_close_balise(1);
}
