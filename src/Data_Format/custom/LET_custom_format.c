/*******************************************************************************
 ** File Name : custom_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +---------------------------------------------+
// | custom_format includes                      |
// +---------------------------------------------+
#include "stdint.h"

#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"

// +---------------------------------------------+
// | custom_format macros                        |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | custom_format types                         |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | custom_format variables                     |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | custom_format extern functions definition   |
// +---------------------------------------------+
extern void LET_Framework_printer (const char * data);

// +---------------------------------------------+
// | custom_format private functions definition  |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | custom_format private functions declaration |
// +---------------------------------------------+
/*Not Used*/


// +---------------------------------------------+
// | custom_format public functions declaration  |
// +---------------------------------------------+
void LET_init_printer(void){
  /*TODO*/
}

void LET_end_printer(void){
  /*TODO*/
}

void LET_service_init_printer(char* name, uint8_t test_number){
  /*TODO*/
}

void LET_service_end_printer(char* name){
  /*TODO*/
}

void LET_test_init_printer(char* name){
  /*TODO*/
}

void LET_test_end_printer(char* name, LET_ASSERT_RESULT result){
  /*TODO*/
}

void LET_assert_printer(char *name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained,
                  LET_ASSERT_RESULT result
 #ifdef FILE_AND_LINE
                  ,char *file
                  ,uint32_t line
 #endif
){
  /*TODO*/
}
