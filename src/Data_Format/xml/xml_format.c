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
#include "format_string.h"

// +------------------------------------------+
// | xml_format macros                        |
// +------------------------------------------+
/*Not Used*/

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
void open_balise(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close){
  if(new_line) LET_Framework_printer("\n");
  for(uint8_t i = 0; i<tabulation; i++){
    LET_Framework_printer("\t");
  }
  LET_Framework_printer("<");
  if(close) LET_Framework_printer("/");
  LET_Framework_printer(balise_name);
}

void close_balise(uint8_t standalone){
  if(standalone) LET_Framework_printer("/");
  LET_Framework_printer(">");
}

void add_parameter(const char *parameter_name, const char* value){
  LET_Framework_printer(" ");
  LET_Framework_printer(parameter_name);
  LET_Framework_printer("=\"");
  LET_Framework_printer(value);
  LET_Framework_printer("\"");
}

// +------------------------------------------+
// | xml_format private functions definition  |
// +------------------------------------------+
/*Not Used*/

// +-----------------------------------------+
// | xml_format public functions definition  |
// +-----------------------------------------+
void LET_init_printer(void){
  open_balise(BALISE_LET_RUN, 0, 0, 0);
  close_balise(0);
}

void LET_end_printer(void){
  open_balise(BALISE_LET_RUN, 1, 0, 1);
  close_balise(0);
  LET_Framework_printer("\n");
}

void service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\n'};
  uint_to_decimal_string(number, test_number);
  open_balise(BALISE_SERVICE, 1, 1, 0);
  add_parameter(NAME_PARAMETER_SERVICE, name);
  add_parameter(NB_TEST_PARAMETER_SERVICE, number);
  close_balise(0);
}

void service_end_printer(char* name){
  open_balise(BALISE_SERVICE, 1, 1, 1);
  close_balise(0);
}

void test_init_printer(char* name){
  open_balise(BALISE_TEST, 1, 2, 0);
  add_parameter(NAME_PARAMETER_TEST, name);
  close_balise(0);
}

void test_end_printer(char* name, ASSERT_RESULT result){
  open_balise(BALISE_RESULT, 1, 3, 0);
  close_balise(0);
  LET_Framework_printer((OK==result)?RESULT_OK:RESULT_KO);
  open_balise(BALISE_RESULT, 0, 0, 1);
  close_balise(0);
  open_balise(BALISE_TEST, 1, 2, 1);
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
  open_balise(BALISE_ASSERT, 1, 3, 0);
 #ifdef FILE_AND_LINE
  add_parameter(FILE_PARAMETER_ASSERT, file);
  add_parameter(LINE_PARAMETER_ASSERT, line);
 #endif
  add_parameter(NAME_PARAMETER_ASSERT, name);
  add_parameter(TYPE_PARAMETER_ASSERT, ASSERT_TYPE_STRING[type]);
  add_parameter(COMPARE_PARAMETER_ASSERT, ASSERT_COMPARE_STRING[compare]);
  add_parameter(EXPECTED_PARAMETER_ASSERT, expected);
  add_parameter(OBTAINED_PARAMETER_ASSERT, obtained);
  add_parameter(VALID_PARAMETER_ASSERT, ASSERT_RESULT_STRING[result]);
  close_balise(1);
}
