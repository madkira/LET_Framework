/*******************************************************************************
 ** File Name : LET_Framework_Result.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_LET_Framework_RESULT_H_
#define D_LET_Framework_RESULT_H_
// +-------------------------------------------+
// | LET_Framework_Result Includes             |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Types                |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Structures           |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Macros               |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Variables            |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Functions Definition |
// +-------------------------------------------+
void service_init_printer(char* name, uint8_t test_number);
void service_end_printer(char* name);
void assert_printer(char* name);
void test_init_printer(char* name);
void test_end_printer(char* name);
#endif //D_LET_Framework_RESULT_H_
