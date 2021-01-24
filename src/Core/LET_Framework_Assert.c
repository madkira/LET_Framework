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
#define BYTE_MASK  0xFF
#define WORD_MASK  0xFFFF
#define DWORD_MASK 0xFFFFFFFF
#define QWORD_MASK 0xFFFFFFFFFFFFFFFF

#define BYTE_DIGIT 8
#define HEXA_DIGIT 2

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
ASSERT_RESULT ASSERT_uint(ASSERT_COMPARE assertion,
                          uint64_t obtained,
                          uint64_t expected,
                          ASSERT_PRECISION precision,
                          ASSERT_REPRESENT format,
                          char* name,
                          Test *itself
 #ifdef FILE_AND_LINE
                          ,char *file
                          ,uint32_t line
 #endif
){
 #ifdef FILE_AND_LINE
  char str_line[25];
 #endif
  char str_expected[70];
  char str_obtained[70];
  obtained = obtained&((BYTE == precision)?BYTE_MASK:(WORD == precision)?WORD_MASK:(DWORD == precision)?DWORD_MASK:QWORD_MASK);
  expected = expected&((BYTE == precision)?BYTE_MASK:(WORD == precision)?WORD_MASK:(DWORD == precision)?DWORD_MASK:QWORD_MASK);
  ASSERT_RESULT result = KO;
  switch (assertion) {
    case EQUAL:
      if(expected == obtained) result = OK;
      break;
    case NOT_EQUAL:
      if(expected != obtained) result = OK;
      break;
    case HIGHER_THAN:
      if(expected < obtained) result = OK;
      break;
    case HIGHER_OR_EQUAL:
      if(expected <= obtained) result = OK;
      break;
    case LOWER_THAN:
      if(expected > obtained) result = OK;
      break;
    case LOWER_OR_EQUAL:
      if(expected >= obtained) result = OK;
      break;
    case FLAG_SET:
      if((expected & obtained) == expected) result = OK;
      break;
    case NOT_FLAG_SET:
      if (0 == (expected & obtained)) result = OK;
    default:
      break;
  }

  if(KO == result){
    itself->result = KO;
 #ifndef ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    switch (format){
      case HEXADECIMAL:
      case OCTAL:
      case BINARY:
        uint_to_base_string(str_expected, expected, format, precision);
        uint_to_base_string(str_obtained, obtained, format, precision);
        break;

      case DECIMAL:
      default:
        uint_to_decimal_string(str_expected, expected);
        uint_to_decimal_string(str_obtained, obtained);
        break;
    }
   #ifdef FILE_AND_LINE
    uint_to_decimal_string(str_line, line);
   #endif
    assert_printer(name, UINT, assertion, str_expected, str_obtained, result
   #ifdef FILE_AND_LINE
                  ,file, str_line
   #endif
    );
 #ifdef ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


ASSERT_RESULT ASSERT_int(ASSERT_COMPARE assertion,
                        int64_t obtained,
                        int64_t expected,
                        char* name,
                        Test *itself
#ifdef FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
){
 #ifdef FILE_AND_LINE
  char str_line[25];
 #endif
  char str_expected[25];
  char str_obtained[25];
  ASSERT_RESULT result = KO;
  switch (assertion) {
    case EQUAL:
      if(expected == obtained) result = OK;
      break;
    case NOT_EQUAL:
      if(expected != obtained) result = OK;
      break;
    case HIGHER_THAN:
      if(expected < obtained) result = OK;
      break;
    case HIGHER_OR_EQUAL:
      if(expected <= obtained) result = OK;
      break;
    case LOWER_THAN:
      if(expected > obtained) result = OK;
      break;
    case LOWER_OR_EQUAL:
      if(expected >= obtained) result = OK;
      break;
    default:
      break;
  }

  if(KO == result){
    itself->result = KO;
 #ifndef ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    int_to_string(str_expected, expected);
    int_to_string(str_obtained, obtained);
   #ifdef FILE_AND_LINE
    uint_to_decimal_string(str_line, line);
   #endif
    assert_printer(name, INT, assertion, str_expected, str_obtained, result
   #ifdef FILE_AND_LINE
                  ,file, str_line
   #endif
    );
 #ifdef ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


ASSERT_RESULT ASSERT_float(ASSERT_COMPARE assertion,
                          float obtained,
                          float expected,
                          float delta,
                          uint8_t precision,
                          ASSERT_REPRESENT format,
                          char* name,
                          Test *itself
#ifdef FILE_AND_LINE
                          ,char *file
                          ,uint32_t line
#endif
){
 #ifdef FILE_AND_LINE
  // char str_line[25];
 #endif
  ASSERT_RESULT result = KO;
  switch (assertion) {
    case EQUAL:
      break;
    case NOT_EQUAL:
      break;
    case HIGHER_THAN:
      break;
    case HIGHER_OR_EQUAL:
      break;
    case LOWER_THAN:
      break;
    case LOWER_OR_EQUAL:
      break;
    default:
      break;
  }

  if(KO == result){
    itself->result = KO;
 #ifndef ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif
    // assert_printer(name);
 #ifdef ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


ASSERT_RESULT ASSERT_double(ASSERT_COMPARE assertion,
                            double obtained,
                            double expected,
                            double delta,
                            uint8_t precision,
                            ASSERT_REPRESENT format,
                            char* name,
                            Test *itself
#ifdef FILE_AND_LINE
                            ,char *file
                            ,uint32_t line
#endif
){
 #ifdef FILE_AND_LINE
  // char str_line[25];
 #endif
  ASSERT_RESULT result = KO;
  switch (assertion) {
    case EQUAL:
      break;
    case NOT_EQUAL:
      break;
    case HIGHER_THAN:
      break;
    case HIGHER_OR_EQUAL:
      break;
    case LOWER_THAN:
      break;
    case LOWER_OR_EQUAL:
      break;
    default:
      break;
  }

  if(KO == result){
    itself->result = KO;
 #ifndef ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif
    // assert_printer(name);
 #ifdef ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}


ASSERT_RESULT ASSERT_str(ASSERT_COMPARE assertion,
                        uint8_t* obtained,
                        uint8_t* expected,
                        ASSERT_PRECISION whitespace,
                        ASSERT_REPRESENT format,
                        char* name,
                        Test *itself
#ifdef FILE_AND_LINE
                        ,char *file
                        ,uint32_t line
#endif
){
 #ifdef FILE_AND_LINE
  char str_line[25];
 #endif
  ASSERT_RESULT result = KO;
  switch (assertion) {
    case EQUAL:
      if(!compare_str(expected,obtained))result = OK;
      break;
    case NOT_EQUAL:
      if(compare_str(expected,obtained))result = OK;
      break;
    default:
      break;
  }

  if(KO == result){
    itself->result = KO;
 #ifndef ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
  }
 #endif

    /* OCTAL NOT SUPPORTED YET*/
    if(OCTAL == format){
      format = HEXADECIMAL;
    }

   #ifdef FILE_AND_LINE
    uint_to_decimal_string(str_line, line);
   #endif

    if(HEXADECIMAL == format || BINARY == format){
      uint16_t expected_size = str_size(expected);
      uint16_t obtained_size = str_size(obtained);
      expected_size = (expected_size/whitespace) + expected_size*((BINARY==format)?BYTE_DIGIT : HEXA_DIGIT);
      obtained_size = (obtained_size/whitespace) + obtained_size*((BINARY==format)?BYTE_DIGIT : HEXA_DIGIT);

      char convert_expected[expected_size];
      char convert_obtained[obtained_size];
      str_convert(convert_expected, expected, format, whitespace);
      str_convert(convert_obtained, obtained, format, whitespace);

      assert_printer(name, STR, assertion, convert_expected, convert_obtained, result
    #ifdef FILE_AND_LINE
                    ,file, str_line
    #endif
      );
    }else{

      assert_printer(name, STR, assertion, expected, obtained, result
    #ifdef FILE_AND_LINE
                    ,file, str_line
    #endif
        );
    }
 #ifdef ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}
