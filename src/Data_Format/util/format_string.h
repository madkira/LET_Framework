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

#define BALISE_LET_RUN "LET_RUN"

#define BALISE_SERVICE "SERVICE"
#define NAME_PARAMETER_SERVICE "S_NAME"
#define NB_TEST_PARAMETER_SERVICE "NB_TEST"

#define BALISE_TEST "TEST"
#define NAME_PARAMETER_TEST "T_NAME"

#define BALISE_RESULT "RESULT"
#define RESULT_OK "PASSED"
#define RESULT_KO "FAILED"

#define BALISE_ASSERT "ASSERT"
#define NAME_PARAMETER_ASSERT "A_NAME"
#define FILE_PARAMETER_ASSERT "FILE"
#define LINE_PARAMETER_ASSERT "LINE"
#define TYPE_PARAMETER_ASSERT "TYPE"
#define COMPARE_PARAMETER_ASSERT "COMPARE"
#define EXPECTED_PARAMETER_ASSERT "EXPECTED"
#define OBTAINED_PARAMETER_ASSERT "OBTAINED"
#define VALID_PARAMETER_ASSERT "VALID"



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
uint8_t compare_str(char *a, char *b);
uint16_t str_size(char *a);
void str_convert(char dest[], char *src, ASSERT_REPRESENT format, ASSERT_PRECISION whitespace);

#endif //D_UTIL_FORMAT_H_
