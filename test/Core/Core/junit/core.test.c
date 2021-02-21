#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "LET_Framework.h"
#include "LET_Framework_Result.h"

uint8_t count_call_a;
uint8_t count_call_b;
uint8_t count_LET_init_printer;
uint8_t count_LET_end_printer;
uint8_t count_LET_service_init_printer;
uint8_t count_LET_service_end_printer;
uint8_t count_LET_test_init_printer;
uint8_t count_LET_test_end_printer;


char null_char[] = "null\n";

char *LET_service_init_printer_expected_name[LET_MAX_TESTS];
uint8_t LET_service_init_printer_expected_test_number[LET_MAX_TESTS];
char *LET_test_init_printer_expected_name[LET_MAX_TESTS];
char *LET_test_init_printer_expected_classname[LET_MAX_TESTS];


void Reset_env(void){
  count_call_a = 0;
  count_call_b = 0;
  count_LET_init_printer = 0;
  count_LET_end_printer = 0;
  count_LET_service_init_printer = 0;
  count_LET_service_end_printer = 0;
  count_LET_test_init_printer = 0;
  count_LET_test_end_printer = 0;
;

  for(uint8_t i = 0; i<LET_MAX_TESTS; i++){
    LET_service_init_printer_expected_name[i] = null_char;
    LET_test_init_printer_expected_name[i] = null_char;
    LET_test_init_printer_expected_classname[i] = null_char;


    LET_service_init_printer_expected_test_number[i] = 0;

  }

}

/****************************************************************************************
 * BEGIN STUB
 ****************************************************************************************/
void LET_init_printer(void){
  count_LET_init_printer++;
}

void LET_end_printer(void){
  count_LET_end_printer++;
}

void LET_service_init_printer(char* name, uint8_t test_number){
  if(!strcmp(LET_service_init_printer_expected_name[count_LET_service_init_printer], name)){
    printf("OK\n");
  }else {
    printf("LET_service_init_printer name  KO\n");
  }
  if(LET_service_init_printer_expected_test_number[count_LET_service_init_printer] == test_number){
    printf("OK\n");
  }else {
    printf("LET_service_init_printer test_number  KO\n");
  }
  count_LET_service_init_printer++;
}

void LET_service_end_printer(void){
  count_LET_service_end_printer++;
}

void LET_test_init_printer(char* name, char *classname){
  if(!strcmp(LET_test_init_printer_expected_name[count_LET_test_init_printer], name)){
    printf("OK\n");
  }else {
    printf("LET_test_init_printer name KO\n");
  }
  if(!strcmp(LET_test_init_printer_expected_classname[count_LET_test_init_printer], classname)){
    printf("OK\n");
  }else {
    printf("LET_test_init_printer classname  KO\n");
  }
  count_LET_test_init_printer++;
}

void LET_test_end_printer(void){
  count_LET_test_end_printer++;
}

/****************************************************************************************
 * END STUB
 ****************************************************************************************/

void stub_call_a(void){
    count_call_a++;
}

void stub_call_b(LET_Test * itself){
    count_call_b++;
}

void test_LET_service_init(void){
    Reset_env();
    LET_Service service_test =  LET_service_init("alpha", stub_call_a);
    if(!strcmp(service_test.suite_name, "alpha")){
        printf("OK\n");
    }else {
        printf("service init name  KO\n");
    }
    service_test.init_func();
    if(1==count_call_a){
        printf("OK\n");
    }else{
        printf("service init function  KO\n");
    }
}

void test_LET_test_register(void){
    Reset_env();
    LET_Service service_test;
    LET_CORE_EXCEPTION result = LET_test_register(&service_test, "beta", stub_call_b);
    service_test.test_list[0].main_func(&(service_test.test_list[0]));
    if(LET_CORE_OK==result){
        printf("OK\n");
    }else{
        printf("test register return  KO\n");
    }
    if(1==service_test.test_num){
        printf("OK\n");
    }else{
        printf("test register number  KO\n");
    }
    if(!strcmp(service_test.test_list[0].test_name, "beta")){
        printf("OK\n");
    }else {
        printf("test register name  KO\n");
    }
    if(1==count_call_b){
        printf("OK\n");
    }else{
        printf("test main function  KO\n");
    }

    service_test.test_num=LET_MAX_TESTS;
    result = LET_test_register(&service_test, "beta", stub_call_b);
    if(LET_CORE_KO==result){
        printf("OK\n");
    }else{
        printf("test register return  KO\n");
    }
    if(LET_MAX_TESTS==service_test.test_num){
        printf("OK\n");
    }else{
        printf("test register number  KO\n");
    }
}

void test_LET_service_runner(void){
    Reset_env();
    char service_name[] = "alpha";
    char test_1_name[] = "alpha_test";
    char test_2_name[] = "beta_test";
    LET_service_init_printer_expected_name[0] = service_name;
    LET_Service service_test =  LET_service_init(service_name, stub_call_a);
    LET_service_runner(&service_test);
    if(0==count_call_a){
        printf("OK\n");
    }else{
        printf("run service init call  KO\n");
    }
    if(count_call_a==count_call_b){
        printf("OK\n");
    }else{
        printf("test function call  KO\n");
    }


    Reset_env();
    LET_service_init_printer_expected_name[0] = service_name;
    LET_service_init_printer_expected_test_number[0] = 1;
    LET_test_init_printer_expected_name[0] = test_1_name;
    LET_test_init_printer_expected_classname[0] = service_name;
    LET_test_register(&service_test, test_1_name, stub_call_b);

    LET_service_runner(&service_test);
    if(1==count_call_a){
        printf("OK\n");
    }else{
        printf("run service init call  KO\n");
    }
    if(count_call_a==count_call_b){
        printf("OK\n");
    }else{
        printf("test function call  KO\n");
    }


    Reset_env();
    LET_service_init_printer_expected_name[0] = service_name;
    LET_service_init_printer_expected_test_number[0] = 2;
    LET_test_init_printer_expected_name[0] = test_1_name;
    LET_test_init_printer_expected_name[1] = test_2_name;
    LET_test_init_printer_expected_classname[0] = service_name;
    LET_test_init_printer_expected_classname[1] = service_name;
    LET_test_register(&service_test, test_2_name, stub_call_b);

    LET_service_runner(&service_test);
    if(2==count_call_a){
        printf("OK\n");
    }else{
        printf("run service init call  KO\n");
    }
    if(count_call_a==count_call_b){
        printf("OK\n");
    }else{
        printf("test function call  KO\n");
    }


}


int main (){
  test_LET_service_init();
  test_LET_test_register();
  test_LET_service_runner();

  return 0;
}
