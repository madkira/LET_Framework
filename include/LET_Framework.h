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
#include "stdint.h"

// +------------------------------------+
// | LET_Framework Macros               |
// +------------------------------------+
#ifndef LET_MAX_TESTS
#define LET_MAX_TESTS 10
#endif

#define LET_GENERATE_ENUM(ENUM) LET_ ## ENUM,

// +------------------------------------+
// | LET_Framework Types                |
// +------------------------------------+
typedef enum{
  LET_CORE_OK
  ,LET_CORE_KO
}LET_CORE_EXCEPTION;



#define LET_FOREACH_RESULT(LET_RESULT) \
        LET_RESULT(OK) \
        LET_RESULT(KO)

typedef enum {
  LET_FOREACH_RESULT(LET_GENERATE_ENUM)
}LET_ASSERT_RESULT;

#define LET_FOREACH_COMPARE(LET_COMPARE) \
        LET_COMPARE(EQUAL) \
        LET_COMPARE(NOT_EQUAL) \
        LET_COMPARE(HIGHER_THAN) \
        LET_COMPARE(LOWER_THAN) \
        LET_COMPARE(HIGHER_OR_EQUAL) \
        LET_COMPARE(LOWER_OR_EQUAL) \
        LET_COMPARE(FLAG_SET) \
        LET_COMPARE(NOT_FLAG_SET)


typedef enum {
  LET_FOREACH_COMPARE(LET_GENERATE_ENUM)
}LET_ASSERT_COMPARE;


typedef enum{
  LET_BYTE    =1
  ,LET_WORD   =2
  ,LET_DWORD  =4
  ,LET_QWORD  =8
}LET_ASSERT_PRECISION;

typedef enum{
  LET_DECIMAL
  ,LET_HEXADECIMAL
  ,LET_OCTAL
  ,LET_BINARY
  ,LET_SCIENTIST
  ,LET_STRING
}LET_ASSERT_REPRESENT;

// +------------------------------------+
// | LET_Framework Structures           |
// +------------------------------------+
typedef struct LET_Framework_Test {
  char * test_name;
  void (*main_func)(struct LET_Framework_Test*);
  LET_ASSERT_RESULT result;
}LET_Test;


typedef struct LET_Framework_Service {
  char* suite_name;
  void (*init_func)(void);
  uint8_t test_num;
  LET_Test test_list[LET_MAX_TESTS];
}LET_Service;

// +------------------------------------+
// | LET_Framework Variables            |
// +------------------------------------+
/*Not Used*/

// +------------------------------------+
// | LET_Framework Functions Definition |
// +------------------------------------+
#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_UINT_CALL(...) LET_ASSERT_uint(__VA_ARGS__, itself, __FILE__, __LINE__)
#else
#define LET_ASSERT_UINT_CALL(...) LET_ASSERT_uint(__VA_ARGS__, itself)
#endif
#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_UINT5(a, b, ...) if(LET_KO==LET_ASSERT_UINT_CALL(a, b, __VA_ARGS__, #b))return
#else
#define LET_ASSERT_UINT5(a, b, ...) LET_ASSERT_UINT_CALL(a, b, __VA_ARGS__, #b)
#endif
#define LET_ASSERT_UINT4(...) LET_ASSERT_UINT5(__VA_ARGS__, LET_DECIMAL)
#define LET_ASSERT_UINT3(...) LET_ASSERT_UINT4(__VA_ARGS__, LET_DWORD)
#define LET_ASSERT_UINT_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define LET_ASSERT_UINT(...) LET_ASSERT_UINT_FUNC(__VA_ARGS__, LET_ASSERT_uint, LET_ASSERT_UINT_CALL, LET_ASSERT_UINT5, LET_ASSERT_UINT4, LET_ASSERT_UINT3, ...)(__VA_ARGS__)



#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_INT_CALL(...) LET_ASSERT_int(__VA_ARGS__, itself, __FILE__, __LINE__)
#else
#define LET_ASSERT_INT_CALL(...) LET_ASSERT_int(__VA_ARGS__, itself)
#endif
#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_INT3(a, b, ...) if(LET_KO==LET_ASSERT_INT_CALL(a, b, __VA_ARGS__, #b))return
#else
#define LET_ASSERT_INT3(a, b, ...) LET_ASSERT_INT_CALL(a, b, __VA_ARGS__, #b)
#endif
#define LET_ASSERT_INT_FUNC(_1, _2, _3, _4, _5, NAME, ...) NAME
#define LET_ASSERT_INT(...) LET_ASSERT_INT_FUNC(__VA_ARGS__, LET_ASSERT_int, LET_ASSERT_INT_CALL, LET_ASSERT_INT3, ...)(__VA_ARGS__)



#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_FLOAT_CALL(...) LET_ASSERT_float(__VA_ARGS__, itself, __FILE__, __LINE__)
#else
#define LET_ASSERT_FLOAT_CALL(...) LET_ASSERT_float(__VA_ARGS__, itself)
#endif
#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_FLOAT6(a, b, ...) if(LET_KO==LET_ASSERT_FLOAT_CALL(a, b, __VA_ARGS__, #b))return
#else
#define LET_ASSERT_FLOAT6(a, b, ...) LET_ASSERT_FLOAT_CALL(a, b, __VA_ARGS__, #b)
#endif
#define LET_ASSERT_FLOAT5(...) LET_ASSERT_FLOAT6(__VA_ARGS__, LET_DECIMAL)
#define LET_ASSERT_FLOAT4(...) LET_ASSERT_FLOAT5(__VA_ARGS__, 6)
#define LET_ASSERT_FLOAT3(...) LET_ASSERT_FLOAT4(__VA_ARGS__, 0.1)
#define LET_ASSERT_FLOAT_FUNC(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define LET_ASSERT_FLOAT(...) LET_ASSERT_FLOAT_FUNC(__VA_ARGS__, LET_ASSERT_float, LET_ASSERT_FLOAT_CALL, LET_ASSERT_FLOAT6, LET_ASSERT_FLOAT5, LET_ASSERT_FLOAT4, LET_ASSERT_FLOAT3, ...)(__VA_ARGS__)



#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_DOUBLE_CALL(...) LET_ASSERT_double(__VA_ARGS__, itself, __FILE__, __LINE__)
#else
#define LET_ASSERT_DOUBLE_CALL(...) LET_ASSERT_double(__VA_ARGS__, itself)
#endif
#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_DOUBLE6(a, b, ...) if(LET_KO==LET_ASSERT_DOUBLE_CALL(a, b, __VA_ARGS__, #b))return
#else
#define LET_ASSERT_DOUBLE6(a, b, ...) LET_ASSERT_DOUBLE_CALL(a, b, __VA_ARGS__, #b)
#endif
#define LET_ASSERT_DOUBLE5(...) LET_ASSERT_DOUBLE6(__VA_ARGS__, LET_DECIMAL)
#define LET_ASSERT_DOUBLE4(...) LET_ASSERT_DOUBLE5(__VA_ARGS__, 10)
#define LET_ASSERT_DOUBLE3(...) LET_ASSERT_DOUBLE4(__VA_ARGS__, 0.1)
#define LET_ASSERT_DOUBLE_FUNC(_1, _2, _3, _4, _5, _6, _7, _8, NAME, ...) NAME
#define LET_ASSERT_DOUBLE(...) LET_ASSERT_DOUBLE_FUNC(__VA_ARGS__, LET_ASSERT_double, LET_ASSERT_DOUBLE_CALL, LET_ASSERT_DOUBLE6, LET_ASSERT_DOUBLE5, LET_ASSERT_DOUBLE4, LET_ASSERT_DOUBLE3, ...)(__VA_ARGS__)



#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_STR_CALL(...) LET_ASSERT_str(__VA_ARGS__, itself, __FILE__, __LINE__)
#else
#define LET_ASSERT_STR_CALL(...) LET_ASSERT_str(__VA_ARGS__, itself)
#endif
#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_STR5(a, b, ...) if(LET_KO==LET_ASSERT_STR_CALL(a, b, __VA_ARGS__, #b))return
#else
#define LET_ASSERT_STR5(a, b, ...) LET_ASSERT_STR_CALL(a, b, __VA_ARGS__, #b)
#endif
#define LET_ASSERT_STR4(...) LET_ASSERT_STR5(__VA_ARGS__, LET_STRING)
#define LET_ASSERT_STR3(...) LET_ASSERT_STR4(__VA_ARGS__, LET_DWORD)
#define LET_ASSERT_STR_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define LET_ASSERT_STR(...) LET_ASSERT_STR_FUNC(__VA_ARGS__, LET_ASSERT_str, LET_ASSERT_STR_CALL, LET_ASSERT_STR5, LET_ASSERT_STR4, LET_ASSERT_STR3, ...)(__VA_ARGS__)




LET_ASSERT_RESULT LET_ASSERT_uint(LET_ASSERT_COMPARE LET_assertion,
                          uint64_t obtained,
                          uint64_t expected,
                          LET_ASSERT_PRECISION precision,
                          LET_ASSERT_REPRESENT format,
                          char* name,
                          LET_Test *itself
#ifdef LET_FILE_AND_LINE
                          ,char *file
                          ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_int(LET_ASSERT_COMPARE LET_assertion,
                        int64_t obtained,
                        int64_t expected,
                        char* name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_float(LET_ASSERT_COMPARE LET_assertion,
                          float obtained,
                          float expected,
                          float delta,
                          uint8_t precision,
                          LET_ASSERT_REPRESENT format,
                          char* name,
                          LET_Test *itself
#ifdef LET_FILE_AND_LINE
                          ,char *file
                          ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_double(LET_ASSERT_COMPARE LET_assertion,
                            double obtained,
                            double expected,
                            double delta,
                            uint8_t precision,
                            LET_ASSERT_REPRESENT format,
                            char* name,
                            LET_Test *itself
#ifdef LET_FILE_AND_LINE
                            ,char *file
                            ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_str(LET_ASSERT_COMPARE LET_assertion,
                        uint8_t* obtained,
                        uint8_t* expected,
                        LET_ASSERT_PRECISION whitespace,
                        LET_ASSERT_REPRESENT format,
                        char* name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
);

void LET_init(void);
void LET_end(void);

LET_Service LET_service_init(char* name, void (*func)(void));
LET_CORE_EXCEPTION LET_test_register(LET_Service *service, char * name, void (*func)(LET_Test *));
void LET_service_runner(LET_Service *service);

#endif //D_LET_Framework_H_
