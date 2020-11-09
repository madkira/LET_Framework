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
// Temporary Shared library Might be removed for no dependency purpose
#include "stdint.h"

#include "text_format.h"
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
extern void LET_Framework_printer(char * data);

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
void service_init_printer(char* name, uint8_t test_number){
  char number[5] = {'\n'};
  uint_to_string(number, test_number);
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
  LET_Framework_printer("\" :");
}

void test_end_printer(char* name){
  LET_Framework_printer("\n| Test End \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" :");
}

void assert_printer(char* name){
  LET_Framework_printer("\n|\tAssertion \"");
  LET_Framework_printer(name);
  LET_Framework_printer("\" :");
}
