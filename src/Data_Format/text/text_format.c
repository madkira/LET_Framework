/*******************************************************************************
 ** File Name : text_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +-------------------------------------------+
// | text_format includes                      |
// +-------------------------------------------+
#include "stdint.h"

#include "LET_Framework_Result.h"
#include "format_string.h"

// +-------------------------------------------+
// | text_format macros                        |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | text_format types                         |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | text_format variables                     |
// +-------------------------------------------+
/*Not Used*/



// +-------------------------------------------+
// | text_format extern functions definition   |
// +-------------------------------------------+
extern void LET_Framework_printer(const char * data);

// +-------------------------------------------+
// | text_format private functions definition  |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | text_format private functions declaration |
// +-------------------------------------------+
/*Not Used*/


// +-------------------------------------------+
// | text_format public functions declaration  |
// +-------------------------------------------+
void LET_init_printer(void){;}
void LET_end_printer(void){;}

void service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\n'};
  uint_to_decimal_string(number, test_number);
  LET_Framework_printer("Service Begin \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" with ");
  LET_Framework_printer(number);
  LET_Framework_printer((test_number>1)?" tests :":" test :");
}

void service_end_printer(char* name){
  LET_Framework_printer("\nService End \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\"\n");
}

void test_init_printer(char* name){
  LET_Framework_printer("\n| Test Begin \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\"");
}

void test_end_printer(char* name, ASSERT_RESULT result){
  LET_Framework_printer("\n| Test End \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" : ");
  LET_Framework_printer((OK==result)?"PASSED":"FAILED");
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
  LET_Framework_printer("\n| | Assertion ");
 #ifdef FILE_AND_LINE
  LET_Framework_printer("[");
  LET_Framework_printer(file);
  LET_Framework_printer("{l.");
  LET_Framework_printer(line);
  LET_Framework_printer("}]");
 #endif
  LET_Framework_printer(" \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" : Expected ");
  LET_Framework_printer(ASSERT_TYPE_STRING[type]);
  LET_Framework_printer(" ");
  LET_Framework_printer(ASSERT_COMPARE_STRING[compare]);
  LET_Framework_printer(" [");
  LET_Framework_printer(expected);
  LET_Framework_printer("] Obtained [");
  LET_Framework_printer(obtained);
  LET_Framework_printer("] --> ");
  LET_Framework_printer(ASSERT_RESULT_STRING[result]);
}
