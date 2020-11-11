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
#include "LET_Framework_Assert.h"
#include "LET_Framework_Result.h"
#include "format_string.h"

// +----------------------------------------------------+
// | LET_Framework_Assert macros                        |
// +----------------------------------------------------+
#define BYTE_MASK  0xFF
#define WORD_MASK  0xFFFF
#define DWORD_MASK 0xFFFFFFFF
#define QWORD_MASK 0xFFFFFFFFFFFFFFFF

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
ASSERT_RESULT ASSERT_uint(ASSERT_COMPARE assertion, uint64_t obtained, uint64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name){
  char str_expected[70];
  char str_obtained[70];
  obtained = (BYTE == precision)?obtained&BYTE_MASK : (WORD == precision)?obtained&WORD_MASK : (DWORD == precision)? obtained&DWORD_MASK : obtained&QWORD_MASK;
  expected = (BYTE == precision)?expected&BYTE_MASK : (WORD == precision)?expected&WORD_MASK : (DWORD == precision)? expected&DWORD_MASK : expected&QWORD_MASK;
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
  switch (format)
  {
  case DECIMAL:
    uint_to_decimal_string(str_expected, expected);
    uint_to_decimal_string(str_obtained, obtained);
    break;
  case HEXADECIMAL:
  case OCTAL:
  case BINARY:
    uint_to_base_string(str_expected, expected, format, precision);
    uint_to_base_string(str_obtained, obtained, format, precision);
    break;
  default:
    break;
  }

  assert_printer(name, UINT, assertion, str_expected, str_obtained, result);
  return result;
}

ASSERT_RESULT ASSERT_int(ASSERT_COMPARE assertion, int64_t obtained, int64_t expected, char* name){
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

  int_to_string(str_expected, expected);
  int_to_string(str_obtained, obtained);
  assert_printer(name, INT, assertion, str_expected, str_obtained, result);
  return result;
}

ASSERT_RESULT ASSERT_float(ASSERT_COMPARE assertion, float obtained, float expected, float delta, uint8_t precision, ASSERT_REPRESENT format, char* name){
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
//  assert_printer(name);
  return result;
}

ASSERT_RESULT ASSERT_double(ASSERT_COMPARE assertion, double obtained, double expected, double delta, uint8_t precision, ASSERT_REPRESENT format, char* name){
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
//  assert_printer(name);
  return result;
}

ASSERT_RESULT ASSERT_str(ASSERT_COMPARE assertion, uint8_t* obtained, uint8_t* expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name){
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
//  assert_printer(name);
  return result;
}
