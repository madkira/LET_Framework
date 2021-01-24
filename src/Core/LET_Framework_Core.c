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

Service service_init(char* name, void (*func)(void)){
  Service new_service;
  new_service.suite_name = name;
  new_service.init_func = func;
  new_service.test_num = 0;
  return new_service;
}

CORE_EXCEPTION test_register(Service *service, char * name, void (*func)(Test *)){
  Test new_test;
  new_test.test_name = name;
  new_test.main_func = func;
  new_test.result = OK;
  if(service->test_num >= MAX_TESTS) return CORE_KO;
  service->test_list[service->test_num++] = new_test;
  return CORE_OK;
}

void service_runner(Service *service){
  Test * current_test;
  service_init_printer(service->suite_name, service->test_num);
  for(uint8_t  i = 0; i < service->test_num; i++){
    current_test = &service->test_list[i];
    #ifdef JUNIT
    test_init_printer(current_test->test_name, service->suite_name);
    #else
    test_init_printer(current_test->test_name);
    #endif
    service->init_func();
    current_test->main_func(current_test);
    test_end_printer(current_test->result);
  }
  service_end_printer();
}
