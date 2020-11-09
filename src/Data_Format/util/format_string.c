/*******************************************************************************
 ** File Name : LET_Framework_Result.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +----------------------------------------------------+
// | LET_Framework_Result includes                      |
// +----------------------------------------------------+
// Temporary Shared library Might be removed for no dependency purpose
#include "stdint.h"
#include "format_string.h"

// +----------------------------------------------------+
// | LET_Framework_Result macros                        |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result types                         |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result variables                     |
// +----------------------------------------------------+
/*Not Used*/


// +----------------------------------------------------+
// | LET_Framework_Result extern functions definition   |
// +----------------------------------------------------+
/*Not Used*/


// +----------------------------------------------------+
// | LET_Framework_Result private functions definition  |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result private functions declaration |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result public functions declaration  |
// +----------------------------------------------------+
void uint_to_string(char str[], uint64_t num){
  uint64_t i, rem, len = (num==0)?1:0, n = num;

  while (n != 0){
    len++;
    n /= 10;
  }
  for (i = 0; i < len; i++){
    rem = num % 10;
    num = num / 10;
    str[len - (i + 1)] = rem + '0';
  }
  str[len] = '\0';
}

void int_to_string(char str[], int64_t num){
    if(num < 0){
      str[0] = '-';
      uint_to_string(str+1, (uint64_t) - num);
    }else{
      uint_to_string(str, (uint64_t) num);
    }
}


