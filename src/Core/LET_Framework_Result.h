/*******************************************************************************
 ** File Name : LET_Framework_Result.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_LET_Framework_RESULT_H_
#define D_LET_Framework_RESULT_H_
// +-------------------------------------------+
// | LET_Framework_Result Includes             |
// +-------------------------------------------+
#include "LET_Framework.h"

// +-------------------------------------------+
// | LET_Framework_Result Types                |
// +-------------------------------------------+

#define LET_FOREACH_TYPE(LET_TYPE) \
        LET_TYPE(UINT) \
        LET_TYPE(INT) \
        LET_TYPE(FLOAT) \
        LET_TYPE(DOUBLE) \
        LET_TYPE(STR)

typedef enum {
    LET_FOREACH_TYPE(LET_GENERATE_ENUM)
}LET_ASSERT_TYPE;


// +-------------------------------------------+
// | LET_Framework_Result Structures           |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Macros               |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Variables            |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Functions Definition |
// +-------------------------------------------+
void LET_init_printer(void);
void LET_end_printer(void);
void LET_service_init_printer(char *name, uint8_t test_number);
void LET_service_end_printer(void);
void LET_test_init_printer(char *name
 #ifdef LET_JUNIT
                            ,char *service_name
 #endif
);
void LET_test_end_printer(
 #ifndef LET_JUNIT
                        LET_ASSERT_RESULT result
 #else
                        void
 #endif
    );
void LET_assert_printer(char *name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained
 #ifndef LET_JUNIT
                  ,LET_ASSERT_RESULT result
 #endif
 #ifdef LET_FILE_AND_LINE
                  ,char *file
                  ,uint32_t line
 #endif
);


#endif //D_LET_Framework_RESULT_H_
