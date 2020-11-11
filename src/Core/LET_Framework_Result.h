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
#include "LET_Framework.h"

// +-------------------------------------------+
// | LET_Framework_Result Types                |
// +-------------------------------------------+

#define FOREACH_TYPE(TYPE) \
        TYPE(UINT) \
        TYPE(INT) \
        TYPE(FLOAT) \
        TYPE(DOUBLE) \
        TYPE(STR)

typedef enum {
    FOREACH_TYPE(GENERATE_ENUM)
}ASSERT_TYPE;


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
void service_init_printer(char *name, uint8_t test_number);
void service_end_printer(char *name);
void assert_printer(char *name, ASSERT_TYPE type, ASSERT_COMPARE compare, char *expected, char *obtained, ASSERT_RESULT result);
void test_init_printer(char *name);
void test_end_printer(char* name, ASSERT_RESULT result);
#endif //D_LET_Framework_RESULT_H_
