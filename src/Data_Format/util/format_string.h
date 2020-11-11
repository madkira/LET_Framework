/*******************************************************************************
 ** File Name : LET_Framework_Result.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_UTIL_FORMAT_H_
#define D_UTIL_FORMAT_H_
// +-------------------------------------------+
// | LET_Framework_Result Includes             |
// +-------------------------------------------+
#include "LET_Framework.h"

// +-------------------------------------------+
// | LET_Framework_Result Types                |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Structures           |
// +-------------------------------------------+

// +-------------------------------------------+
// | LET_Framework_Result Macros               |
// +-------------------------------------------+
#define GENERATE_STRING(STRING) #STRING,

#define BALISE_SERVICE "SERVICE"
#define BALISE_TEST "TEST"
#define BALISE_ASSERT "ASSERT"
#define BALISE_ANNOTATION "NOTE"
#define BALISE_ERROR "ERROR"



// +-------------------------------------------+
// | LET_Framework_Result Variables            |
// +-------------------------------------------+
extern const char *ASSERT_COMPARE_STRING[];
extern const char *ASSERT_TYPE_STRING[];
extern const char *ASSERT_RESULT_STRING[];

// +-------------------------------------------+
// | LET_Framework_Result Functions Definition |
// +-------------------------------------------+
void uint_to_decimal_string(char str[], uint64_t num);
void uint_to_base_string(char str[], uint64_t num, ASSERT_REPRESENT format, ASSERT_PRECISION bytes);
void int_to_string(char str[], int64_t num);


#endif //D_UTIL_FORMAT_H_
