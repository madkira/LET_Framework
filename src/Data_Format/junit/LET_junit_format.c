/*******************************************************************************
 ** File Name : junit_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +---------------------------------------------+
// | junit_format includes                       |
// +---------------------------------------------+
#include <stdint.h>

#include "LET_Framework.h"
#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

// +---------------------------------------------+
// | junit_format macros                         |
// +---------------------------------------------+
#define LET_STDOUT_BALISE                   "system-out"

#define LET_TESTSUITE_BALISE                "testsuite"
#define LET_TESTSUITES_BALISE               LET_TESTSUITE_BALISE "s"
#define LET_TESTSUITE_TEST_NB_PARAMETER     "tests"
#define LET_TESTSUITE_DISABLED_NB_PARAMETER "disabled"
#define LET_TESTSUITE_NAME_PARAMETER        "name"

#define LET_TESTCASE_BALISE                 "testcase"
#define LET_TESTCASE_NAME_PARAMETER         "name"
#define LET_TESTCASE_CLASSNAME_PARAMETER    "classname"

#define LET_FAILURE_BALISE                  "failure"
#define LET_FAILURE_TYPE_PARAMETER          "type"
#define LET_FAILURE_MESSAGE_PARAMETER       "message"
#define LET_FAILURE_DATA_NEWLINE            "\n\t\t\t\t"
#define LET_FILE_PARAMETER_ASSERT           LET_FAILURE_DATA_NEWLINE "FILE : "
#define LET_LINE_PARAMETER_ASSERT           LET_FAILURE_DATA_NEWLINE "LINE : "
#define LET_COMPARE_PARAMETER_ASSERT        LET_FAILURE_DATA_NEWLINE "COMPARE : "
#define LET_EXPECTED_PARAMETER_ASSERT       LET_FAILURE_DATA_NEWLINE "EXPECTED : "
#define LET_OBTAINED_PARAMETER_ASSERT       LET_FAILURE_DATA_NEWLINE "OBTAINED : "
// +---------------------------------------------+
// | junit_format types                          |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format variables                      |
// +---------------------------------------------+
/*Not Used*/

// +---------------------------------------------+
// | junit_format extern  functions definition   |
// +---------------------------------------------+
extern void LET_Framework_printer (const char *const data);

// +---------------------------------------------+
// | junit_format private  functions declaration |
// +---------------------------------------------+
void LET_assert_begin_printer(const char *const name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
);
void LET_assert_end_printer(void);

// +---------------------------------------------+
// | junit_format private  functions definition  |
// +---------------------------------------------+
void LET_assert_begin_printer(const char *const name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
  LET_xml_open_balise(LET_FAILURE_BALISE, 1, 3, 0);
  LET_xml_add_str_parameter(LET_FAILURE_MESSAGE_PARAMETER, name);
  LET_xml_add_str_parameter(LET_FAILURE_TYPE_PARAMETER, LET_ASSERT_TYPE_STRING[type]);
  LET_xml_close_balise(0);
 #ifdef LET_FILE_AND_LINE
  LET_Framework_printer(LET_FILE_PARAMETER_ASSERT);
  LET_Framework_printer(file);

  LET_Framework_printer(LET_LINE_PARAMETER_ASSERT);
  LET_uint_to_decimal_printer(line);

 #endif

  LET_Framework_printer(LET_COMPARE_PARAMETER_ASSERT);
  LET_Framework_printer(LET_ASSERT_COMPARE_STRING[compare]);


}

void LET_assert_end_printer(void){
  LET_xml_open_balise(LET_FAILURE_BALISE, 1, 3, 1);
  LET_xml_close_balise(0);
}

// +---------------------------------------------+
// | junit_format public  functions definition   |
// +---------------------------------------------+
void LET_init_printer(void){
  LET_Framework_printer("\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
  LET_xml_open_balise(LET_TESTSUITES_BALISE, 1, 0, 0);
  LET_xml_close_balise(0);
}

void LET_end_printer(void){
  LET_xml_open_balise(LET_TESTSUITES_BALISE, 1, 0, 1);
  LET_xml_close_balise(0);
  LET_Framework_printer("\n");
}

void LET_service_init_printer(LET_Service *const service){
  LET_xml_open_balise(LET_TESTSUITE_BALISE, 1, 1, 0);
  LET_xml_add_str_parameter(LET_TESTSUITE_NAME_PARAMETER, service->suite_name);
  LET_xml_add_uint_parameter(LET_TESTSUITE_TEST_NB_PARAMETER, service->test_num, LET_DECIMAL, LET_DWORD);
  if(0 < service->test_ignored){
    LET_xml_add_uint_parameter(LET_TESTSUITE_DISABLED_NB_PARAMETER, service->test_ignored, LET_DECIMAL, LET_DWORD);
  }
  LET_xml_close_balise(0);
}

void LET_service_end_printer(void){
  LET_xml_open_balise(LET_TESTSUITE_BALISE, 1, 1, 1);
  LET_xml_close_balise(0);
}

void LET_test_init_printer(const char *const name, const char *const service_name){
  LET_xml_open_balise(LET_TESTCASE_BALISE, 1, 2, 0);
  LET_xml_add_str_parameter(LET_TESTCASE_NAME_PARAMETER, name);
  LET_xml_add_str_parameter(LET_TESTCASE_CLASSNAME_PARAMETER, service_name);
  LET_xml_close_balise(0);
}

void LET_test_end_printer(void){
  LET_xml_open_balise(LET_TESTCASE_BALISE, 1, 2, 1);
  LET_xml_close_balise(0);
}


void LET_init_call_wrapper(void){
  LET_xml_open_balise(LET_STDOUT_BALISE, 1, 3, 1);
  LET_xml_close_balise(0);
  LET_Framework_printer("\n");
}

void LET_end_call_wrapper(void){
  LET_xml_open_balise(LET_STDOUT_BALISE, 1, 3, 1);
  LET_xml_close_balise(0);
}

void LET_assert_uint_printer(const char *const name,
                  LET_ASSERT_COMPARE compare,
                  uint64_t expected,
                  uint64_t obtained,
                  LET_ASSERT_PRECISION precision,
                  LET_ASSERT_REPRESENT format
 #ifndef LET_JUNIT
                  ,LET_ASSERT_RESULT result
 #endif
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
  LET_assert_begin_printer(name, LET_UINT, compare
   #ifdef LET_FILE_AND_LINE
                          ,file ,line
   #endif
  );

  LET_Framework_printer(LET_EXPECTED_PARAMETER_ASSERT);
  switch (format){
    case LET_HEXADECIMAL:
    case LET_OCTAL:
    case LET_BINARY:
      LET_uint_to_base_printer(expected, format, precision);
      LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
      LET_uint_to_base_printer(obtained, format, precision);
      break;

    case LET_DECIMAL:
    default:
      LET_uint_to_decimal_printer(expected);
      LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
      LET_uint_to_decimal_printer(obtained);
      break;
  }

  LET_assert_end_printer();
}



void LET_assert_int_printer(const char *const name,
                  LET_ASSERT_COMPARE compare,
                  int64_t expected,
                  int64_t obtained
 #ifndef LET_JUNIT
                  ,LET_ASSERT_RESULT result
 #endif
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
  LET_assert_begin_printer(name, LET_INT, compare
   #ifdef LET_FILE_AND_LINE
                          ,file ,line
   #endif
  );

  LET_Framework_printer(LET_EXPECTED_PARAMETER_ASSERT);
  LET_int_printer(expected);
  LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
  LET_int_printer(obtained);

  LET_assert_end_printer();

}





void LET_assert_str_printer(const char *const name,
                  LET_ASSERT_COMPARE compare,
                  const char *const expected,
                  const char *const obtained
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
  LET_assert_begin_printer(name, LET_STR, compare
   #ifdef LET_FILE_AND_LINE
                          ,file ,line
   #endif
  );

  LET_Framework_printer(LET_EXPECTED_PARAMETER_ASSERT);
  LET_Framework_printer(expected);
  LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
  LET_Framework_printer(obtained);


  LET_assert_end_printer();
}





void LET_assert_array_printer(const char *const name,
                  LET_ASSERT_COMPARE compare,
                  LET_ASSERT_PRECISION whitespace,
                  LET_ASSERT_REPRESENT format,
                  const char *const expected,
                  const char *const obtained,
                  uint32_t size
 #ifdef LET_FILE_AND_LINE
                  ,const char *const file
                  ,uint32_t line
 #endif
){
  if(LET_BINARY != format){
    format = LET_HEXADECIMAL;
  }
  LET_assert_begin_printer(name, LET_ARRAY, compare
   #ifdef LET_FILE_AND_LINE
                          ,file ,line
   #endif
  );

  LET_Framework_printer(LET_EXPECTED_PARAMETER_ASSERT);
  LET_array_printer(expected, size, format, whitespace);
  LET_Framework_printer(LET_OBTAINED_PARAMETER_ASSERT);
  LET_array_printer(obtained, size, format, whitespace);

  LET_assert_end_printer();
}
