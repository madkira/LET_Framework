/*******************************************************************************
 ** File Name : LET_Framework.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_LET_Framework_H_
#define D_LET_Framework_H_
// +------------------------------------+
// | LET_Framework Includes             |
// +------------------------------------+
// Temporary Shared library Might be removed for no dependency purpose
#include "stdint.h"

// +------------------------------------+
// | LET_Framework Macros               |
// +------------------------------------+
#define MAX_TESTS 10
#define GENERATE_ENUM(ENUM) ENUM,

// +------------------------------------+
// | LET_Framework Types                |
// +------------------------------------+
typedef enum{
  CORE_OK
  ,CORE_KO
}CORE_EXCEPTION;



#define FOREACH_RESULT(RESULT) \
        RESULT(OK) \
        RESULT(KO)

typedef enum {
  FOREACH_RESULT(GENERATE_ENUM)
}ASSERT_RESULT;

#define FOREACH_COMPARE(COMPARE) \
        COMPARE(EQUAL) \
        COMPARE(NOT_EQUAL) \
        COMPARE(HIGHER_THAN) \
        COMPARE(LOWER_THAN) \
        COMPARE(HIGHER_OR_EQUAL) \
        COMPARE(LOWER_OR_EQUAL) \
        COMPARE(FLAG_SET) \
        COMPARE(NOT_FLAG_SET)


typedef enum {
  FOREACH_COMPARE(GENERATE_ENUM)
}ASSERT_COMPARE;


typedef enum{
  BYTE    =1
  ,WORD   =2
  ,DWORD  =4
  ,QWORD  =8
}ASSERT_PRECISION;

typedef enum{
  DECIMAL
  ,HEXADECIMAL
  ,OCTAL
  ,BINARY
  ,SCIENTIST
  ,STRING
}ASSERT_REPRESENT;

// +------------------------------------+
// | LET_Framework Structures           |
// +------------------------------------+
typedef struct LET_Framework_Test {
  char * test_name;
  void (*main_func)(struct LET_Framework_Test*);
  ASSERT_RESULT result;
}Test;


typedef struct LET_Framework_Service {
  char* suite_name;
  void (*init_func)(void);
  uint8_t test_num;
  Test test_list[MAX_TESTS];
}Service;

// +------------------------------------+
// | LET_Framework Variables            |
// +------------------------------------+
/*Not Used*/

// +------------------------------------+
// | LET_Framework Functions Definition |
// +------------------------------------+
#define ASSERT_UINT_CALL(...) ASSERT_uint(__VA_ARGS__, itself)
#define ASSERT_UINT5(a, b, ...) ASSERT_UINT_CALL(a, b, __VA_ARGS__, #b)
#define ASSERT_UINT4(...) ASSERT_UINT5(__VA_ARGS__, DECIMAL)
#define ASSERT_UINT3(...) ASSERT_UINT4(__VA_ARGS__, DWORD)
#define ASSERT_UINT_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define ASSERT_UINT(...) ASSERT_UINT_FUNC(__VA_ARGS__, ASSERT_uint, ASSERT_UINT_CALL, ASSERT_UINT5, ASSERT_UINT4, ASSERT_UINT3, ...)(__VA_ARGS__)



#define ASSERT_INT_CALL(...) ASSERT_int(__VA_ARGS__, itself)
#define ASSERT_INT3(a, b, ...) ASSERT_INT_CALL(a, b, __VA_ARGS__, #b)
#define ASSERT_INT_FUNC(_1, _2, _3, _4, _5, NAME, ...) NAME
#define ASSERT_INT(...) ASSERT_INT_FUNC(__VA_ARGS__, ASSERT_int, ASSERT_INT_CALL, ASSERT_INT3, ...)(__VA_ARGS__)



#define ASSERT_FLOAT_CALL(...) ASSERT_int(__VA_ARGS__, itself)
#define ASSERT_FLOAT6(a, b, ...) ASSERT_FLOAT_CALL(a, b, __VA_ARGS__, #b)
#define ASSERT_FLOAT5(...) ASSERT_FLOAT6(__VA_ARGS__, DECIMAL)
#define ASSERT_FLOAT4(...) ASSERT_FLOAT5(__VA_ARGS__, 6)
#define ASSERT_FLOAT3(...) ASSERT_FLOAT4(__VA_ARGS__, 0.1)
#define ASSERT_FLOAT_FUNC(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define ASSERT_FLOAT(...) ASSERT_FLOAT_FUNC(__VA_ARGS__, ASSERT_float, ASSERT_FLOAT_CALL, ASSERT_FLOAT6, ASSERT_FLOAT5, ASSERT_FLOAT4, ASSERT_FLOAT3, ...)(__VA_ARGS__)



#define ASSERT_DOUBLE_CALL(...) ASSERT_int(__VA_ARGS__, itself)
#define ASSERT_DOUBLE6(a, b, ...) ASSERT_DOUBLE_CALL(a, b, __VA_ARGS__, #b)
#define ASSERT_DOUBLE5(...) ASSERT_DOUBLE6(__VA_ARGS__, DECIMAL)
#define ASSERT_DOUBLE4(...) ASSERT_DOUBLE5(__VA_ARGS__, 10)
#define ASSERT_DOUBLE3(...) ASSERT_DOUBLE4(__VA_ARGS__, 0.1)
#define ASSERT_DOUBLE_FUNC(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define ASSERT_DOUBLE(...) ASSERT_DOUBLE_FUNC(__VA_ARGS__, ASSERT_double, ASSERT_DOUBLE_CALL, ASSERT_DOUBLE6, ASSERT_DOUBLE5, ASSERT_DOUBLE4, ASSERT_DOUBLE3, ...)(__VA_ARGS__)



#define ASSERT_STR_CALL(...) ASSERT_str(__VA_ARGS__, itself)
#define ASSERT_STR5(a, b, ...) ASSERT_STR_CALL(a, b, __VA_ARGS__, #b)
#define ASSERT_STR4(...) ASSERT_STR5(__VA_ARGS__, STRING)
#define ASSERT_STR3(...) ASSERT_STR4(__VA_ARGS__, DWORD)
#define ASSERT_STR_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define ASSERT_STR(...) ASSERT_STR_FUNC(__VA_ARGS__, ASSERT_str, ASSERT_STR_CALL, ASSERT_STR5, ASSERT_STR4, ASSERT_STR3, ...)(__VA_ARGS__)




ASSERT_RESULT ASSERT_uint(ASSERT_COMPARE assertion, uint64_t obtained, uint64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name, Test *itself);
ASSERT_RESULT ASSERT_int(ASSERT_COMPARE assertion, int64_t obtained, int64_t expected, char* name, Test *itself);
ASSERT_RESULT ASSERT_float(ASSERT_COMPARE assertion, float obtained, float expected, float delta, uint8_t precision, ASSERT_REPRESENT format, char* name, Test *itself);
ASSERT_RESULT ASSERT_double(ASSERT_COMPARE assertion, double obtained, double expected, double delta, uint8_t precision, ASSERT_REPRESENT format, char* name, Test *itself);
ASSERT_RESULT ASSERT_str(ASSERT_COMPARE assertion, uint8_t* obtained, uint8_t* expected, ASSERT_PRECISION whitespace, ASSERT_REPRESENT format, char* name, Test *itself);

Service service_init(char* name, void (*func)(void));
CORE_EXCEPTION test_register(Service *service, char * name, void (*func)(Test *));
void service_runner(Service *service);

#endif //D_LET_Framework_H_
