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

// +------------------------------------+
// | LET_Framework Types                |
// +------------------------------------+
typedef enum{
  CORE_OK
  ,CORE_KO
}CORE_EXCEPTION;

typedef enum{
  OK = 1
  ,KO = 0
}ASSERT_RESULT;

typedef enum{
  EQUAL
  ,NOT_EQUAL
  ,HIGHER_THAN
  ,LOWER_THAN
  ,HIGHER_OR_EQUAL
  ,LOWER_OR_EQUAL
}ASSERT_TYPE;

typedef enum{
  BYTE    =1
  ,WORD   =2
  ,DWORD  =4
  ,QWORD  =8
}ASSERT_PRECISION;

typedef enum{
  DECIMAL
  ,HEXADECIMAL
  ,BINARY
  ,SCIENTIST
  ,STRING
}ASSERT_REPRESENT;

// +------------------------------------+
// | LET_Framework Structures           |
// +------------------------------------+
typedef struct LET_Framework_Test {
  char * test_name;
  void (*main_func)(void);
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

#define ASSERT_UINT5(a, b, ...) ASSERT_uint(a, b, __VA_ARGS__, #b) // <== New function added
#define ASSERT_UINT4(a, b, ...) ASSERT_UINT5(a, b, __VA_ARGS__, DECIMAL) // <== New function added
#define ASSERT_UINT3(a, b, ...) ASSERT_UINT4(a, b, __VA_ARGS__, DWORD)
#define ASSERT_UINT2(a,b, ...)  ASSERT_UINT3(a, b, __VA_ARGS__)
#define ASSERT_UINT_FUNC(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define ASSERT_UINT(...) ASSERT_UINT_FUNC(__VA_ARGS__, ASSERT_uint,  ASSERT_UINT5, ASSERT_UINT4, ASSERT_UINT3, ASSERT_UINT2)(__VA_ARGS__)

#define ASSERT_INT5(a, b, ...) ASSERT_int(a, b, __VA_ARGS__, #b) // <== New function added
#define ASSERT_INT4(a, b, ...) ASSERT_INT5(a, b, __VA_ARGS__, DECIMAL) // <== New function added
#define ASSERT_INT3(a, b, ...) ASSERT_INT4(a, b, __VA_ARGS__, DWORD)
#define ASSERT_INT_FUNC(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define ASSERT_INT(...) ASSERT_INT_FUNC(__VA_ARGS__, ASSERT_int,  ASSERT_INT5, ASSERT_INT4, ASSERT_INT3, ASSERT_INT2)(__VA_ARGS__)

#define ASSERT_FLOAT6(a, b, ...) ASSERT_float(a, b, __VA_ARGS__, #b) // <== New function added
#define ASSERT_FLOAT5(a, b, ...) ASSERT_FLOAT6(a, b, __VA_ARGS__, DECIMAL) // <== New function added
#define ASSERT_FLOAT4(a, b, ...) ASSERT_FLOAT5(a, b, __VA_ARGS__, 6)
#define ASSERT_FLOAT3(a, b, ...) ASSERT_FLOAT4(a, b, __VA_ARGS__, 0.1)
#define ASSERT_FLOAT_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define ASSERT_FLOAT(...) ASSERT_FLOAT_FUNC(__VA_ARGS__, ASSERT_float, ASSERT_FLOAT6, ASSERT_FLOAT5, ASSERT_FLOAT4, ASSERT_FLOAT3, ASSERT_FLOAT2)(__VA_ARGS__)

#define ASSERT_DOUBLE6(a, b, ...) ASSERT_double(a, b, __VA_ARGS__, #b) // <== New function added
#define ASSERT_DOUBLE5(a, b, ...) ASSERT_DOUBLE6(a, b, __VA_ARGS__, DECIMAL) // <== New function added
#define ASSERT_DOUBLE4(a, b, ...) ASSERT_DOUBLE5(a, b, __VA_ARGS__, 10)
#define ASSERT_DOUBLE3(a, b, ...) ASSERT_DOUBLE4(a, b, __VA_ARGS__, 0.1)
#define ASSERT_DOUBLE_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define ASSERT_DOUBLE(...) ASSERT_DOUBLE_FUNC(__VA_ARGS__, ASSERT_double, ASSERT_DOUBLE6, ASSERT_DOUBLE5, ASSERT_DOUBLE4, ASSERT_DOUBLE3, ASSERT_DOUBLE2)(__VA_ARGS__)


ASSERT_RESULT ASSERT_uint(ASSERT_TYPE assertion, uint64_t obtained, uint64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name);
ASSERT_RESULT ASSERT_int(ASSERT_TYPE assertion, int64_t obtained, int64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name);
ASSERT_RESULT ASSERT_float(ASSERT_TYPE assertion, float obtained, float expected, float delta, uint8_t precision, ASSERT_REPRESENT format, char* name);
ASSERT_RESULT ASSERT_double(ASSERT_TYPE assertion, double obtained, double expected, double delta, uint8_t precision, ASSERT_REPRESENT format, char* name);
ASSERT_RESULT ASSERT_str(ASSERT_TYPE assertion, uint8_t* obtained, uint8_t* expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name);

Service service_init(char* name, void (*func)(void));
CORE_EXCEPTION test_register(Service *service, char * name, void (*func)(void));
void service_runner(Service *service);

#endif //D_LET_Framework_H_
