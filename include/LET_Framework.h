/*******************************************************************************
 ** File Name : LET_Framework.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_LET_Framework_H_
#define D_LET_Framework_H_

#ifdef __cplusplus
extern "C" {
#endif

// +------------------------------------+
// | LET_Framework Includes             |
// +------------------------------------+

// +------------------------------------+
// | LET_Framework Macros               |
// +------------------------------------+
#ifndef LET_MAX_TESTS
#define LET_MAX_TESTS 10
#endif

#define LET_UNUSED(x) (void)(x)
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
  LET_BYTE    =1u
  ,LET_WORD   =2u
  ,LET_DWORD  =4u
  ,LET_QWORD  =8u
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
  const char * test_name;
  void (*main_func)(struct LET_Framework_Test*);
  LET_ASSERT_RESULT result;
}LET_Test;


typedef struct LET_Framework_Service {
  const char *suite_name;
  void (*init_func)(void);
  uint8_t test_num;
  uint8_t test_ignored;
  LET_Test test_list[LET_MAX_TESTS];
}LET_Service;

// +------------------------------------+
// | LET_Framework Variables            |
// +------------------------------------+
/*Not Used*/

// +------------------------------------+
// | LET_Framework Functions Definition |
// +------------------------------------+
#define LET_EXPAND(...) __VA_ARGS__

#ifdef LET_AUTO_DECLARE
#define LET_TEST(function_name) static void function_name(LET_Test *itself); static void function_name(LET_Test *itself)
#define LET_INIT_TEST(function_name) static void function_name(void); static void function_name(void)
#else
#define LET_TEST(function_name)  static void function_name(LET_Test *itself)
#define LET_INIT_TEST(function_name) static  void function_name(void)
#endif
#define LET_CALL_WRAP(expression) LET_init_call_wrapper();expression;LET_end_call_wrapper();

#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_UINT_CALL(...) if(LET_KO==LET_ASSERT_uint(__VA_ARGS__))return
#else
#define LET_ASSERT_UINT_CALL(...) LET_ASSERT_uint(__VA_ARGS__)
#endif
#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_UINT6(...) LET_EXPAND(LET_ASSERT_UINT_CALL(__VA_ARGS__, itself, (const char *const)__FILE__, __LINE__))
#else
#define LET_ASSERT_UINT6(...) LET_EXPAND(LET_ASSERT_UINT_CALL(__VA_ARGS__, itself))
#endif
#define LET_ASSERT_UINT5(a, b, ...)  LET_EXPAND(LET_ASSERT_UINT6(a, b, __VA_ARGS__, (const char *const)#b))
#define LET_ASSERT_UINT4(...) LET_EXPAND(LET_ASSERT_UINT5(__VA_ARGS__, LET_DECIMAL))
#define LET_ASSERT_UINT3(...) LET_EXPAND(LET_ASSERT_UINT4(__VA_ARGS__, LET_DWORD))
#define LET_ASSERT_UINT_FUNC(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define LET_ASSERT_UINT(...) LET_EXPAND(LET_ASSERT_UINT_FUNC(__VA_ARGS__, LET_ASSERT_UINT6, LET_ASSERT_UINT5, LET_ASSERT_UINT4, LET_ASSERT_UINT3, ...)(__VA_ARGS__))



#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_INT_CALL(...) if(LET_KO==LET_ASSERT_int(__VA_ARGS__))return
#else
#define LET_ASSERT_INT_CALL(...) LET_ASSERT_int(__VA_ARGS__)
#endif
#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_INT4(...) LET_ASSERT_INT_CALL(__VA_ARGS__, itself, (const char *const)__FILE__, __LINE__)
#else
#define LET_ASSERT_INT4(...) LET_ASSERT_int(__VA_ARGS__, itself)
#endif
#define LET_ASSERT_INT3(a, b, ...) LET_EXPAND(LET_ASSERT_INT4(a, b, __VA_ARGS__, (const char *const)#b))
#define LET_ASSERT_INT_FUNC(_1, _2, _3, _4, NAME, ...) NAME
#define LET_ASSERT_INT(...) LET_EXPAND(LET_ASSERT_INT_FUNC(__VA_ARGS__, LET_ASSERT_INT4, LET_ASSERT_INT3, ...)(__VA_ARGS__))


#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_STR_CALL(...) if(LET_KO==LET_ASSERT_str(__VA_ARGS__))return
#else
#define LET_ASSERT_STR_CALL(...) LET_ASSERT_str(__VA_ARGS__)
#endif
#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_STR4(...) LET_ASSERT_STR_CALL(__VA_ARGS__, itself, (const char *const)__FILE__, __LINE__)
#else
#define LET_ASSERT_STR4(...) LET_ASSERT_STR_CALL(__VA_ARGS__, itself)
#endif
#define LET_ASSERT_STR3(a, b, ...) LET_EXPAND(LET_ASSERT_STR4(a, b, __VA_ARGS__, (const char *const)#b))
#define LET_ASSERT_STR_FUNC(_1, _2, _3, _4, NAME, ...) NAME
#define LET_ASSERT_STR(...) LET_EXPAND(LET_ASSERT_STR_FUNC(__VA_ARGS__, LET_ASSERT_STR4, LET_ASSERT_STR3, ...)(__VA_ARGS__))


#ifdef LET_STOP_TEST_ON_FAILED
#define LET_ASSERT_ARRAY_CALL(...) if(LET_KO==LET_ASSERT_array(__VA_ARGS__))return
#else
#define LET_ASSERT_ARRAY_CALL(...) LET_ASSERT_array(__VA_ARGS__)
#endif
#ifdef LET_FILE_AND_LINE
#define LET_ASSERT_ARRAY7(...) LET_ASSERT_ARRAY_CALL(__VA_ARGS__, itself, (const char *const)__FILE__, __LINE__)
#else
#define LET_ASSERT_ARRAY7(...) LET_ASSERT_ARRAY_CALL(__VA_ARGS__, itself)
#endif
#define LET_ASSERT_ARRAY6(a, b, ...) LET_EXPAND(LET_ASSERT_ARRAY7(a, b, __VA_ARGS__, (const char *const)#b))
#define LET_ASSERT_ARRAY5(...) LET_EXPAND(LET_ASSERT_ARRAY6(__VA_ARGS__, LET_DECIMAL))
#define LET_ASSERT_ARRAY4(...) LET_EXPAND(LET_ASSERT_ARRAY5(__VA_ARGS__, LET_DWORD))
#define LET_ASSERT_ARRAY_FUNC(_1, _2, _3, _4, _5, _6, _7, NAME, ...) NAME
#define LET_ASSERT_ARRAY(...) LET_EXPAND(LET_ASSERT_ARRAY_FUNC(__VA_ARGS__, LET_ASSERT_ARRAY7, LET_ASSERT_ARRAY6, LET_ASSERT_ARRAY5, LET_ASSERT_ARRAY4, ...)(__VA_ARGS__))




LET_ASSERT_RESULT LET_ASSERT_uint(LET_ASSERT_COMPARE LET_assertion,
                          uint64_t obtained,
                          uint64_t expected,
                          LET_ASSERT_PRECISION precision,
                          LET_ASSERT_REPRESENT format,
                          const char *const  name,
                          LET_Test *itself
#ifdef LET_FILE_AND_LINE
                          ,const char *const file
                          ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_int(LET_ASSERT_COMPARE LET_assertion,
                        int64_t obtained,
                        int64_t expected,
                        const char *const  name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,const char *const file
                        ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_float(LET_ASSERT_COMPARE LET_assertion,
                          float obtained,
                          float expected,
                          float delta,
                          uint8_t precision,
                          LET_ASSERT_REPRESENT format,
                          const char *const  name,
                          LET_Test *itself
#ifdef LET_FILE_AND_LINE
                          ,const char *const file
                          ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_double(LET_ASSERT_COMPARE LET_assertion,
                            double obtained,
                            double expected,
                            double delta,
                            uint8_t precision,
                            LET_ASSERT_REPRESENT format,
                            const char *const  name,
                            LET_Test *itself
#ifdef LET_FILE_AND_LINE
                            ,const char *const file
                            ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_str(LET_ASSERT_COMPARE LET_assertion,
                        const char *const obtained,
                        const char *const expected,
                        const char *const  name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,const char *const file
                        ,uint32_t line
#endif
);

LET_ASSERT_RESULT LET_ASSERT_array(LET_ASSERT_COMPARE LET_assertion,
                        const char *const obtained,
                        const char *const expected,
                        uint32_t size,
                        LET_ASSERT_PRECISION whitespace,
                        LET_ASSERT_REPRESENT format,
                        const char *const  name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,const char *const file
                        ,uint32_t line
#endif
);

void LET_init(void);
void LET_end(void);

LET_Service LET_service_init(const char *const name, void (*func)(void));
LET_CORE_EXCEPTION LET_test_register(LET_Service *const service, const char *const name, void (*func)(LET_Test *));
void LET_service_runner(LET_Service *const service);
void LET_init_call_wrapper(void);
void LET_end_call_wrapper(void);

extern void LET_Framework_printer (const char * data);

#ifdef __cplusplus
}                                                               /* End of 'extern'al C lang linkage.  */
#endif

#endif //D_LET_Framework_H_
