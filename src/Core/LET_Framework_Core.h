/*******************************************************************************
 ** File Name : LET_Framework_Core.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_LET_Framework_CORE_H_
#define D_LET_Framework_CORE_H_
// +-----------------------------------------+
// | LET_Framework_Core Includes             |
// +-----------------------------------------+
#include "stdint.h"
#include "LET_Framework.h"

// // +-----------------------------------------+
// // | LET_Framework_Core Macros               |
// // +-----------------------------------------+
// #define MAX_TESTS 10

// // +-----------------------------------------+
// // | LET_Framework_Core Types                |
// // +-----------------------------------------+
// typedef enum{
//   CORE_OK
//   ,CORE_KO
// }CORE_EXCEPTION;

// // +-----------------------------------------+
// // | LET_Framework_Core Structures           |
// // +-----------------------------------------+
// typedef struct LET_Framework_Test {
//   char * test_name;
//   void (*main_func)(void);
// }Test;

// typedef struct LET_Framework_Service {
//   char* suite_name;
//   void (*init_func)(void);
//   uint8_t test_num;
//   Test test_list[MAX_TESTS];
// }Service;

// // +-----------------------------------------+
// // | LET_Framework_Core Variables            |
// // +-----------------------------------------+
// /*Not Used*/

// // +-----------------------------------------+
// // | LET_Framework_Core Functions Definition |
// // +-----------------------------------------+
// Service service_init(char* name, void (*func)(void));
// CORE_EXCEPTION test_register(Service *service, char * name, void (*func)(void));
// void service_runner(Service *service);
#endif //D_LET_Framework_CORE_H_
