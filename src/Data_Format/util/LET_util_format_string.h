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
#define LET_GENERATE_STRING(LET_STRING) #LET_STRING,



// +-------------------------------------------+
// | LET_Framework_Result Variables            |
// +-------------------------------------------+
extern const char *LET_ASSERT_COMPARE_STRING[];
extern const char *LET_ASSERT_TYPE_STRING[];
extern const char *LET_ASSERT_RESULT_STRING[];

// +-------------------------------------------+
// | LET_Framework_Result Functions Definition |
// +-------------------------------------------+
void LET_uint_to_decimal_string(char str[], uint64_t num);
void LET_uint_to_base_string(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes);
void LET_int_to_string(char str[], int64_t num);
int8_t LET_compare_str(const char * a, const char * b);
// uint32_t LET_str_size(const char *const a);
void LET_array_convert(char dest[], const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace);


void LET_uint_to_decimal_printer(uint64_t num);
void LET_int_printer(int64_t num);
void LET_uint_to_base_printer(uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes);
void LET_array_printer(const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace);

#endif //D_UTIL_FORMAT_H_
