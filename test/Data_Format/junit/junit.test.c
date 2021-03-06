#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "LET_Framework.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"
#include "LET_Framework_Result.h"

#define TEST_MAX_BUFFER_SIZE 128

#define TEST_NUM_BUFF 20


uint8_t LET_Framework_printer_stub_num;
char LET_Framework_printer_buffer[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];

const char cleaner[TEST_MAX_BUFFER_SIZE] = {0};

uint8_t LET_uint_to_decimal_printer_stub_num;
uint64_t LET_uint_to_decimal_printer_stub_value[TEST_NUM_BUFF];

uint8_t LET_xml_open_balise_stub_num;
char LET_xml_open_balise_balise_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
uint8_t LET_xml_open_balise_new_line[TEST_NUM_BUFF];
uint8_t LET_xml_open_balise_tabulation[TEST_NUM_BUFF];
uint8_t LET_xml_open_balise_close[TEST_NUM_BUFF];

uint8_t LET_xml_close_balise_stub_num;
uint8_t LET_xml_close_balise_standalone[TEST_NUM_BUFF];

uint8_t LET_xml_add_str_parameter_stub_num;
char LET_xml_add_str_parameter_parameter_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
char LET_xml_add_str_parameter_value[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];


uint8_t LET_int_to_base_string_stub_num;
int64_t LET_int_to_base_string_num[TEST_NUM_BUFF];

uint8_t LET_uint_to_base_printer_stub_num;
uint64_t LET_uint_to_base_printer_num[TEST_NUM_BUFF];
LET_ASSERT_REPRESENT LET_uint_to_base_printer_format[TEST_NUM_BUFF];
LET_ASSERT_PRECISION LET_uint_to_base_printer_bytes[TEST_NUM_BUFF];

uint8_t LET_str_convert_stub_num;
char LET_str_convert_src[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
uint32_t LET_str_convert_size[TEST_NUM_BUFF];
LET_ASSERT_REPRESENT LET_str_convert_format[TEST_NUM_BUFF];
LET_ASSERT_PRECISION LET_str_convert_whitespace[TEST_NUM_BUFF];

const char *LET_ASSERT_COMPARE_STRING[] = {
  LET_FOREACH_COMPARE(LET_GENERATE_STRING)
};

const char *LET_ASSERT_TYPE_STRING[] = {
  LET_FOREACH_TYPE(LET_GENERATE_STRING)
};

const char *LET_ASSERT_RESULT_STRING[] = {
  LET_FOREACH_RESULT(LET_GENERATE_STRING)
};


void LET_Framework_printer (const char * data){
    for(uint32_t i = 0; data[i] != '\0'; i++){
        LET_Framework_printer_buffer[LET_Framework_printer_stub_num][i] = data[i];
    }
    LET_Framework_printer_stub_num++;
}

void clean_data(char *to_clean){
    for(uint16_t i = 0; i < TEST_MAX_BUFFER_SIZE; i++){
        to_clean[i] = '\0';
    }
}

void copy(char dest[], const char src[]){
    for(uint16_t i = 0; src[i] != '\0'; i++){
        dest[i] = src[i];
    }
}

void Reset_env(void){
    LET_Framework_printer_stub_num = 0;
    LET_uint_to_decimal_printer_stub_num = 0;
    LET_xml_open_balise_stub_num = 0;
    LET_xml_close_balise_stub_num = 0;
    LET_xml_add_str_parameter_stub_num = 0;
    LET_str_convert_stub_num = 0;
    LET_int_to_base_string_stub_num = 0;
    LET_uint_to_base_printer_stub_num = 0;
    for(uint8_t i = 0; i<TEST_NUM_BUFF; i++){
        clean_data(LET_Framework_printer_buffer[i]);
        LET_uint_to_decimal_printer_stub_value[i] = 0;
        clean_data(LET_xml_open_balise_balise_name[i]);
        LET_xml_open_balise_new_line[i] = 0;
        LET_xml_open_balise_tabulation[i] = 0;
        LET_xml_open_balise_close[i] = 0;
        LET_xml_close_balise_standalone[i] = 0;

        LET_int_to_base_string_num[i] = 0;

        LET_uint_to_base_printer_num[i] = 0;
        LET_uint_to_base_printer_format[i] = 0;
        LET_uint_to_base_printer_bytes[i] = 0;

        clean_data(LET_xml_add_str_parameter_parameter_name[i]);
        clean_data(LET_xml_add_str_parameter_value[i]);
    }
}

//Stub
void LET_uint_to_decimal_printer(uint64_t num){
    LET_uint_to_decimal_printer_stub_value[LET_uint_to_decimal_printer_stub_num++] = num;
}

//Stub
void LET_xml_open_balise(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close){
    copy(LET_xml_open_balise_balise_name[LET_xml_open_balise_stub_num], balise_name);
    LET_xml_open_balise_new_line[LET_xml_open_balise_stub_num] = new_line;
    LET_xml_open_balise_tabulation[LET_xml_open_balise_stub_num] = tabulation;
    LET_xml_open_balise_close[LET_xml_open_balise_stub_num++] = close;

}

//Stub
void LET_xml_close_balise(uint8_t standalone){
    LET_xml_close_balise_standalone[LET_xml_close_balise_stub_num++] = standalone;
}

//Stub
void LET_xml_add_str_parameter(const char *parameter_name, const char* value){
    copy(LET_xml_add_str_parameter_parameter_name[LET_xml_add_str_parameter_stub_num], parameter_name);
    copy(LET_xml_add_str_parameter_value[LET_xml_add_str_parameter_stub_num++], value);
}

uint8_t LET_xml_add_uint_parameter_stub_num;
char LET_xml_add_uint_parameter_parameter_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
uint64_t LET_xml_add_uint_parameter_num[TEST_NUM_BUFF];
LET_ASSERT_REPRESENT LET_xml_add_uint_parameter_format[TEST_NUM_BUFF];
LET_ASSERT_PRECISION LET_xml_add_uint_parameter_bytes[TEST_NUM_BUFF];
//Stub
void LET_xml_add_uint_parameter(const char *parameter_name, uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
    copy(LET_xml_add_uint_parameter_parameter_name[LET_xml_add_uint_parameter_stub_num], parameter_name);
    LET_xml_add_uint_parameter_num[LET_xml_add_uint_parameter_stub_num] = num;
    LET_xml_add_uint_parameter_format[LET_xml_add_uint_parameter_stub_num] = format;
    LET_xml_add_uint_parameter_bytes[LET_xml_add_uint_parameter_stub_num++] = bytes;
}

uint8_t LET_xml_add_int_parameter_stub_num;
char LET_xml_add_int_parameter_parameter_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
int64_t test_LET_xml_add_int_parameter_num[TEST_NUM_BUFF];
//Stub
void LET_xml_add_int_parameter(const char *parameter_name, int64_t num){
    copy(LET_xml_add_int_parameter_parameter_name[LET_xml_add_int_parameter_stub_num], parameter_name);
    test_LET_xml_add_int_parameter_num[LET_xml_add_int_parameter_stub_num++] = num;
}

//Stub
void LET_uint_to_base_printer(uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
    LET_uint_to_base_printer_num[LET_uint_to_base_printer_stub_num] = num;
    LET_uint_to_base_printer_format[LET_uint_to_base_printer_stub_num] = format;
    LET_uint_to_base_printer_bytes[LET_uint_to_base_printer_stub_num] = bytes;
    LET_uint_to_base_printer_stub_num++;
}

//Stub
void LET_int_printer(int64_t num){
    LET_int_to_base_string_num[LET_int_to_base_string_stub_num] = num;
    LET_int_to_base_string_stub_num++;
}


//Stub
void LET_array_printer(const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace){
    copy(LET_str_convert_src[LET_str_convert_stub_num], src);
    LET_str_convert_size[LET_str_convert_stub_num] = size;
    LET_str_convert_format[LET_str_convert_stub_num] = format;
    LET_str_convert_whitespace[LET_str_convert_stub_num] = whitespace;
    LET_str_convert_stub_num++;
}

//Stub
void LET_array_convert(char dest[], const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace){
    dest[0] = 'O';
    dest[1] = 'K';
    dest[2] = '\n';
    dest[3] = '\0';
    copy(LET_str_convert_src[LET_str_convert_stub_num], src);
    LET_str_convert_size[LET_str_convert_stub_num] = size;
    LET_str_convert_format[LET_str_convert_stub_num] = format;
    LET_str_convert_whitespace[LET_str_convert_stub_num] = whitespace;
    LET_str_convert_stub_num++;
}



void test_LET_init_printer(void){
    Reset_env();
    LET_init_printer();
    if(!strcmp(LET_Framework_printer_buffer[0], "\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>")){
        printf("OK\n");
    }else{
        printf("%u : XML DEFINITION  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuites")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES STANDALONE ISSUE  KO\n", __LINE__);
    }
}

void test_LET_end_printer(void){
    Reset_env();
    LET_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuites")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITES STANDALONE ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_Framework_printer_buffer[0], "\n")){
        printf("OK\n");
    }else{
        printf("%u : XML DEFINITION  KO\n", __LINE__);
    }

}

void test_LET_service_init_printer(void){
    Reset_env();
    LET_Service service;
    service.suite_name = "Lambda";
    service.test_num = 23;
    LET_service_init_printer(&service);

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuite")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE STANDALONE ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "name")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Lambda")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_uint_parameter_parameter_name[0], "tests")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_add_uint_parameter_num[0] == 23){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


}

void test_LET_service_end_printer(void){
    Reset_env();

    LET_service_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuite")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE STANDALONE ISSUE  KO\n", __LINE__);
    }


}

void test_LET_test_init_printer(void){
    Reset_env();

    LET_test_init_printer("Alpha", "Beta");


    if(!strcmp(LET_xml_open_balise_balise_name[0], "testcase")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 2){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE STANDALONE ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "name")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Alpha")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[1], "classname")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_parameter_name[1]);
    }
    if(!strcmp(LET_xml_add_str_parameter_value[1], "Beta")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_value[1]);
    }

}

void test_LET_test_end_printer(void){
    Reset_env();

    LET_test_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testcase")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 2){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE STANDALONE ISSUE  KO\n", __LINE__);
    }


}

void test_LET_assert_str_printer(void){
    Reset_env();

    LET_assert_str_printer("Omega", LET_EQUAL, "dataexp", "dataopt", "filename", 123);




    if(LET_uint_to_decimal_printer_stub_value[0] ==  123){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[0], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[1], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[1] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[1] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }




    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "message")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Omega")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[1], "type")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_parameter_name[1]);
    }
    if(!strcmp(LET_xml_add_str_parameter_value[1], "STR")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_value[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[0], "\n\t\t\t\tFILE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[1], "filename")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[2], "\n\t\t\t\tLINE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[3], "\n\t\t\t\tCOMPARE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[4], "EQUAL")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[5], "\n\t\t\t\tEXPECTED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[6], "dataexp")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[7], "\n\t\t\t\tOBTAINED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[8], "dataopt")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
}



void test_LET_assert_int_printer(void){
    Reset_env();

    LET_assert_int_printer("Omega", LET_EQUAL, 321, -246, "filename", 123);
    if(LET_int_to_base_string_num[0] == 321){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(LET_int_to_base_string_num[1] == -246){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }

    if(LET_uint_to_decimal_printer_stub_value[0] ==  123){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[0], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[1], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[1] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[1] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }




    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "message")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Omega")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[1], "type")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_parameter_name[1]);
    }
    if(!strcmp(LET_xml_add_str_parameter_value[1], "INT")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_value[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[0], "\n\t\t\t\tFILE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[0]);
    }
    if(!strcmp(LET_Framework_printer_buffer[1], "filename")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[2], "\n\t\t\t\tLINE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[2]);
    }


    if(!strcmp(LET_Framework_printer_buffer[3], "\n\t\t\t\tCOMPARE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[4]);
    }
    if(!strcmp(LET_Framework_printer_buffer[4], "EQUAL")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[5]);
    }


    if(!strcmp(LET_Framework_printer_buffer[5], "\n\t\t\t\tEXPECTED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[6]);
    }

    if(!strcmp(LET_Framework_printer_buffer[6], "\n\t\t\t\tOBTAINED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[6]);
    }
}





void test_LET_assert_uint_printer(void){
    Reset_env();
    LET_assert_uint_printer("Omega", LET_EQUAL, 321, 246, LET_DWORD, LET_DECIMAL, "filename", 123);
    if(LET_uint_to_decimal_printer_stub_value[1] == 321){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE KO\n", __LINE__);
    }
    if(LET_uint_to_decimal_printer_stub_value[2] == 246){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }

    if(LET_uint_to_decimal_printer_stub_value[0] ==  123){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[0], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[1], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[1] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[1] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }




    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "message")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Omega")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[1], "type")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_parameter_name[1]);
    }
    if(!strcmp(LET_xml_add_str_parameter_value[1], "UINT")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_value[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[0], "\n\t\t\t\tFILE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[0]);
    }
    if(!strcmp(LET_Framework_printer_buffer[1], "filename")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[2], "\n\t\t\t\tLINE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[2]);
    }
    if(!strcmp(LET_Framework_printer_buffer[3], "\n\t\t\t\tCOMPARE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[3]);
    }
    if(!strcmp(LET_Framework_printer_buffer[4], "EQUAL")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[4]);
    }


    if(!strcmp(LET_Framework_printer_buffer[5], "\n\t\t\t\tEXPECTED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[5]);
    }

    if(!strcmp(LET_Framework_printer_buffer[6], "\n\t\t\t\tOBTAINED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_Framework_printer_buffer[6]);
    }
}







void test_LET_assert_array_printer(void){
    Reset_env();

    LET_assert_array_printer("Omega", LET_EQUAL, LET_BYTE, LET_HEXADECIMAL, "dataexp", "dataopt", 8, "filename", 123);


    if(LET_uint_to_decimal_printer_stub_value[0] ==  123){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[0], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }


    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[0] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_xml_open_balise_balise_name[1], "failure")){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NAME ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_new_line[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE NEWLINE ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_tabulation[1] == 3){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE TABULATION ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_open_balise_close[1] == 1){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE CLOSING ISSUE  KO\n", __LINE__);
    }

    if(LET_xml_close_balise_standalone[1] == 0){
        printf("OK\n");
    }else{
        printf("%u : BALISE FAILURE STANDALONE ISSUE  KO\n", __LINE__);
    }




    if(!strcmp(LET_xml_add_str_parameter_parameter_name[0], "message")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_value[0], "Omega")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER NAME ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_xml_add_str_parameter_parameter_name[1], "type")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n" , __LINE__,LET_xml_add_str_parameter_parameter_name[1]);
    }
    if(!strcmp(LET_xml_add_str_parameter_value[1], "ARRAY")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__,LET_xml_add_str_parameter_value[1]);
    }


    if(!strcmp(LET_Framework_printer_buffer[0], "\n\t\t\t\tFILE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[1], "filename")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[2], "\n\t\t\t\tLINE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }

    if(!strcmp(LET_Framework_printer_buffer[3], "\n\t\t\t\tCOMPARE : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }
    if(!strcmp(LET_Framework_printer_buffer[4], "EQUAL")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }


    if(!strcmp(LET_Framework_printer_buffer[5], "\n\t\t\t\tEXPECTED : ")){
        printf("OK\n");
    }else{
        printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n", __LINE__);
    }

    // if(!strcmp(LET_Framework_printer_buffer[6], "\n\t\t\t\tOBTAINED : ")){
    //     printf("OK\n");
    // }else{
    //     printf("%u : BALISE TESTCASE PARAMETER VALUE ISSUE %s KO\n", __LINE__, LET_Framework_printer_buffer[6]);
    // }
}




int main (){
    test_LET_init_printer();
    test_LET_end_printer();
    test_LET_service_init_printer();
    test_LET_service_end_printer();
    test_LET_test_init_printer();
    test_LET_test_end_printer();
    test_LET_assert_str_printer();
    test_LET_assert_int_printer();
    test_LET_assert_uint_printer();
    test_LET_assert_array_printer();

    return 0;
}
