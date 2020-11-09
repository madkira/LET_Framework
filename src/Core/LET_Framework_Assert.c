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

// +----------------------------------------------------+
// | LET_Framework_Assert macros                        |
// +----------------------------------------------------+
/*Not Used*/

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
ASSERT_RESULT ASSERT_uint(ASSERT_TYPE assertion, uint64_t obtained, uint64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name){
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
  assert_printer(name);
  return result;
}

ASSERT_RESULT ASSERT_int(ASSERT_TYPE assertion, int64_t obtained, int64_t expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name){
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
  assert_printer(name);
  return result;
}

ASSERT_RESULT ASSERT_float(ASSERT_TYPE assertion, float obtained, float expected, float delta, uint8_t precision, ASSERT_REPRESENT format, char* name){
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

  return KO;
}

ASSERT_RESULT ASSERT_double(ASSERT_TYPE assertion, double obtained, double expected, double delta, uint8_t precision, ASSERT_REPRESENT format, char* name){
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

  return KO;
}

ASSERT_RESULT ASSERT_str(ASSERT_TYPE assertion, uint8_t* obtained, uint8_t* expected, ASSERT_PRECISION precision, ASSERT_REPRESENT format, char* name){
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

  return KO;
}
