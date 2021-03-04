/*******************************************************************************
 ** File Name : LET_Framework_Core.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +--------------------------------------------------+
// | LET_Framework_Core includes                      |
// +--------------------------------------------------+
#include <stdint.h>
#include "LET_Framework.h"
#include "LET_Framework_Result.h"

// +--------------------------------------------------+
// | LET_Framework_Core macros                        |
// +--------------------------------------------------+
/*Not Used*/

// +--------------------------------------------------+
// | LET_Framework_Core types                         |
// +--------------------------------------------------+
/*Not Used*/

// +--------------------------------------------------+
// | LET_Framework_Core variables                     |
// +--------------------------------------------------+
/*Not Used*/

// +--------------------------------------------------+
// | LET_Framework_Core private functions definition  |
// +--------------------------------------------------+
/*Not Used*/

// +--------------------------------------------------+
// | LET_Framework_Core private functions declaration |
// +--------------------------------------------------+
/*Not Used*/

// +--------------------------------------------------+
// | LET_Framework_Core public functions declaration  |
// +--------------------------------------------------+
void LET_init(void){
  LET_init_printer();
}
void LET_end(void){
  LET_end_printer();
}

LET_Service LET_service_init(const char *const name, void (*func)(void)){
  LET_Service new_service;
  new_service.suite_name = name;
  new_service.init_func = func;
  new_service.test_num = 0;
  new_service.test_ignored = 0;
  return new_service;
}

LET_CORE_EXCEPTION LET_test_register(LET_Service *const service, const char *const name, void (*func)(LET_Test *)){
  LET_CORE_EXCEPTION result = LET_CORE_KO;
  if(service->test_num < LET_MAX_TESTS){
    LET_Test new_test;
    new_test.test_name = name;
    new_test.main_func = func;
    new_test.result = LET_OK;
    service->test_list[service->test_num++] = new_test;
    result =  LET_CORE_OK;
  }else{
    service->test_ignored++;
  }
  return result;
}

void LET_service_runner(LET_Service *const service){
  LET_Test * current_test;
  LET_service_init_printer(service);
  for(uint8_t  i = 0; i < service->test_num; i++){
    current_test = &service->test_list[i];
    LET_test_init_printer(current_test->test_name
      #ifdef LET_JUNIT
                          ,service->suite_name
      #endif
     );
    service->init_func();
    current_test->main_func(current_test);
    LET_test_end_printer(
      #ifndef LET_JUNIT
                        current_test->result
      #endif
     );
  }
  LET_service_end_printer();
}
