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
#define LET_BYTE_MASK  0xFFu
#define LET_WORD_MASK  0xFFFFu
#define LET_DWORD_MASK 0xFFFFFFFFu
#define LET_QWORD_MASK 0xFFFFFFFFFFFFFFFFu


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


    LET_assert_uint_printer(name, assertion, expected, obtained, precision, format
   #ifndef LET_JUNIT
    ,result
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

    LET_assert_int_printer(name, assertion, expected, obtained
   #ifndef LET_JUNIT
                      ,result
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


LET_ASSERT_RESULT LET_ASSERT_str(LET_ASSERT_COMPARE assertion,
                        char* obtained,
                        char* expected,
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

    LET_assert_str_printer(name, assertion, expected, obtained
     #ifndef LET_JUNIT
                    ,result
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



LET_ASSERT_RESULT LET_ASSERT_array(LET_ASSERT_COMPARE assertion,
                        char* obtained,
                        char* expected,
                        uint32_t size,
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
      result = LET_OK;
      for(uint64_t i = 0; i < size; i++ ){
        if(expected[i] != obtained[i]){
          result = LET_KO;
          break;
        }
      }
      break;
    case LET_NOT_EQUAL:
      for(uint64_t i = 0; i < size; i++ ){
        if(expected[i] != obtained[i]){
          result = LET_OK;
          break;
        }
      }
      break;
    default:
      break;
  }
  if(LET_KO == result){
    itself->result = LET_KO;
   #ifndef LET_ONLY_FAILED_ASSERT // Compilation parameter to print not only failed assertion
    }
   #endif
    LET_assert_array_printer(name,assertion,whitespace,format,expected,obtained,size
     #ifndef LET_JUNIT
                            ,result
     #endif
     #ifdef LET_FILE_AND_LINE
                          ,file ,line
     #endif
    );

   #ifdef LET_ONLY_FAILED_ASSERT // Compilation parameter to print only failed assertion
  }
 #endif
  return result;
}
