/*******************************************************************************
 ** File Name : LET_Framework_Assert.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +----------------------------------------------------+
// | LET_Framework_Assert includes                      |
// +----------------------------------------------------+
#include "LET_Framework.h"
#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"

// +----------------------------------------------------+
// | LET_Framework_Assert macros                        |
// +----------------------------------------------------+
#define LET_BYTE_MASK  0xFF
#define LET_WORD_MASK  0xFFFF
#define LET_DWORD_MASK 0xFFFFFFFF
#define LET_QWORD_MASK 0xFFFFFFFFFFFFFFFF

#define LET_BYTE_DIGIT 8
#define LET_HEXA_DIGIT 2

// +----------------------------------------------------+
// | LET_Framework_Assert types                         |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Assert variables                     |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Assert private functions declaration |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Assert private functions definition  |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Assert public functions definition   |
// +----------------------------------------------------+
LET_ASSERT_RESULT LET_ASSERT_uint(LET_ASSERT_COMPARE assertion,
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
){
  obtained = obtained&((LET_BYTE == precision)?LET_BYTE_MASK:(LET_WORD == precision)?LET_WORD_MASK:(LET_DWORD == precision)?LET_DWORD_MASK:LET_QWORD_MASK);
  expected = expected&((LET_BYTE == precision)?LET_BYTE_MASK:(LET_WORD == precision)?LET_WORD_MASK:(LET_DWORD == precision)?LET_DWORD_MASK:LET_QWORD_MASK);
  LET_ASSERT_RESULT result = LET_KO;
  switch (assertion) {
    case LET_EQUAL:
      if(expected == obtained) result = LET_OK;
      break;
    case LET_NOT_EQUAL:
      if(expected != obtained) result = LET_OK;
      break;
    case LET_HIGHER_THAN:
      if(expected < obtained) result = LET_OK;
      break;
    case LET_HIGHER_OR_EQUAL:
      if(expected <= obtained) result = LET_OK;
      break;
    case LET_LOWER_THAN:
      if(expected > obtained) result = LET_OK;
      break;
    case LET_LOWER_OR_EQUAL:
      if(expected >= obtained) result = LET_OK;
      break;
    case LET_FLAG_SET:
      if((expected & obtained) == expected) result = LET_OK;
      break;
    case LET_NOT_FLAG_SET:
      if (0 == (expected & obtained)) result = LET_OK;
    default:
      break;
  }

  if(LET_KO == result){
    itself->result = LET_KO;
 #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    char str_expected[70];
    char str_obtained[70];

    switch (format){
      case LET_HEXADECIMAL:
      case LET_OCTAL:
      case LET_BINARY:
        LET_uint_to_base_string(str_expected, expected, format, precision);
        LET_uint_to_base_string(str_obtained, obtained, format, precision);
        break;

      case LET_DECIMAL:
      default:
        LET_uint_to_decimal_string(str_expected, expected);
        LET_uint_to_decimal_string(str_obtained, obtained);
        break;
    }
    LET_assert_printer(name, LET_UINT, assertion, str_expected, str_obtained
   #ifndef LET_JUNIT
    , result
   #endif
   #ifdef LET_FILE_AND_LINE
                  ,file, line
   #endif
    );
 #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


LET_ASSERT_RESULT LET_ASSERT_int(LET_ASSERT_COMPARE assertion,
                        int64_t obtained,
                        int64_t expected,
                        char* name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
){
  LET_ASSERT_RESULT result = LET_KO;
  switch (assertion) {
    case LET_EQUAL:
      if(expected == obtained) result = LET_OK;
      break;
    case LET_NOT_EQUAL:
      if(expected != obtained) result = LET_OK;
      break;
    case LET_HIGHER_THAN:
      if(expected < obtained) result = LET_OK;
      break;
    case LET_HIGHER_OR_EQUAL:
      if(expected <= obtained) result = LET_OK;
      break;
    case LET_LOWER_THAN:
      if(expected > obtained) result = LET_OK;
      break;
    case LET_LOWER_OR_EQUAL:
      if(expected >= obtained) result = LET_OK;
      break;
    default:
      break;
  }

  if(LET_KO == result){
    itself->result = LET_KO;
 #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    char str_expected[25];
    char str_obtained[25];

    LET_int_to_string(str_expected, expected);
    LET_int_to_string(str_obtained, obtained);
    LET_assert_printer(name, LET_INT, assertion, str_expected, str_obtained
   #ifndef LET_JUNIT
    , result
   #endif
   #ifdef LET_FILE_AND_LINE
                  ,file, line
   #endif
    );
 #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


LET_ASSERT_RESULT LET_ASSERT_float(LET_ASSERT_COMPARE assertion,
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
){
  LET_ASSERT_RESULT result = LET_KO;
  switch (assertion) {
    case LET_EQUAL:
      break;
    case LET_NOT_EQUAL:
      break;
    case LET_HIGHER_THAN:
      break;
    case LET_HIGHER_OR_EQUAL:
      break;
    case LET_LOWER_THAN:
      break;
    case LET_LOWER_OR_EQUAL:
      break;
    default:
      break;
  }

  if(LET_KO == result){
    itself->result = LET_KO;
 #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif
    // LET_assert_printer(name);
 #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


LET_ASSERT_RESULT LET_ASSERT_double(LET_ASSERT_COMPARE assertion,
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
){
  LET_ASSERT_RESULT result = LET_KO;
  switch (assertion) {
    case LET_EQUAL:
      break;
    case LET_NOT_EQUAL:
      break;
    case LET_HIGHER_THAN:
      break;
    case LET_HIGHER_OR_EQUAL:
      break;
    case LET_LOWER_THAN:
      break;
    case LET_LOWER_OR_EQUAL:
      break;
    default:
      break;
  }

  if(LET_KO == result){
    itself->result = LET_KO;
 #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif
    // LET_assert_printer(name);
 #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


LET_ASSERT_RESULT LET_ASSERT_str(LET_ASSERT_COMPARE assertion,
                        char* obtained,
                        char* expected,
                        LET_ASSERT_PRECISION whitespace,
                        LET_ASSERT_REPRESENT format,
                        char* name,
                        LET_Test *itself
#ifdef LET_FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
){
  LET_ASSERT_RESULT result = LET_KO;
  switch (assertion) {
    case LET_EQUAL:
      if(!LET_compare_str(expected,obtained))result = LET_OK;
      break;
    case LET_NOT_EQUAL:
      if(LET_compare_str(expected,obtained))result = LET_OK;
      break;
    default:
      break;
  }

  if(LET_KO == result){
    itself->result = LET_KO;
 #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    /* LET_OCTAL NOT SUPPORTED YET*/
    if(LET_OCTAL == format){
      format = LET_HEXADECIMAL;
    }

    if(LET_HEXADECIMAL == format || LET_BINARY == format){
      uint16_t expected_size = (uint16_t)LET_str_size(expected);
      uint16_t obtained_size = (uint16_t)LET_str_size(obtained);
      expected_size = (uint16_t)(expected_size/whitespace) + expected_size*((LET_BINARY==format)?LET_BYTE_DIGIT : LET_HEXA_DIGIT);
      obtained_size = (uint16_t)(obtained_size/whitespace) + obtained_size*((LET_BINARY==format)?LET_BYTE_DIGIT : LET_HEXA_DIGIT);
      if(expected_size < 2048 && obtained_size < 2048){
        char convert_expected[2048];
        char convert_obtained[2048];
        LET_str_convert(convert_expected, expected, format, whitespace);
        LET_str_convert(convert_obtained, obtained, format, whitespace);

        LET_assert_printer(name, LET_STR, assertion, convert_expected, convert_obtained
       #ifndef LET_JUNIT
                          ,result
       #endif
       #ifdef LET_FILE_AND_LINE
                          ,file, line
      #endif
        );
      }
    }else{

      LET_assert_printer(name, LET_STR, assertion, expected, obtained
     #ifndef LET_JUNIT
      , result
     #endif
     #ifdef LET_FILE_AND_LINE
                    ,file, line
     #endif
        );
    }
 #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}
