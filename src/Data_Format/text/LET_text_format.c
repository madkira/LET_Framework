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
#include <stdint.h>

#include "LET_Framework.h"
#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"

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
extern void LET_Framework_printer(const char *const  data);

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

void LET_service_init_printer(LET_Service *service){
  char number[5] = {'\n'};
  LET_uint_to_decimal_string(number, service->test_num);
  LET_Framework_printer("Service Begin \"");
  LET_Framework_printer(service->suite_name);
  LET_Framework_printer("\" with ");
  LET_Framework_printer(number);
  LET_Framework_printer((service->test_num>1)?" tests :":" test :");
}

void LET_service_end_printer(void){
  LET_Framework_printer("\nService End\n");
}

void LET_test_init_printer(const char *const name){
  LET_Framework_printer("\n| Test Begin \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\"");
}

void LET_test_end_printer(LET_ASSERT_RESULT result){
  LET_Framework_printer("\n| Test End : ");
  LET_Framework_printer((LET_OK==result)?"PASSED":"FAILED");
}

void LET_assert_printer(const char *const name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  const char *const expected,
                  const char *const obtained,
                  LET_ASSERT_RESULT result
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
 #ifdef LET_FILE_AND_LINE
  char str_line[25];
  LET_uint_to_decimal_string(str_line, line);
 #endif
  LET_Framework_printer("\n| | Assertion ");
 #ifdef LET_FILE_AND_LINE
  LET_Framework_printer("[");
  LET_Framework_printer(file);
  LET_Framework_printer("{l.");
  LET_Framework_printer(str_line);
  LET_Framework_printer("}]");
 #endif
  LET_Framework_printer(" \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" : Expected ");
  LET_Framework_printer(LET_ASSERT_TYPE_STRING[type]);
  LET_Framework_printer(" ");
  LET_Framework_printer(LET_ASSERT_COMPARE_STRING[compare]);
  LET_Framework_printer(" [");
  LET_Framework_printer(expected);
  LET_Framework_printer("] Obtained [");
  LET_Framework_printer(obtained);
  LET_Framework_printer("] --> ");
  LET_Framework_printer(LET_ASSERT_RESULT_STRING[result]);
}
