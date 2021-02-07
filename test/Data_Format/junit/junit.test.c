#include "stdio.h"
#include "string.h"

#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"
#include "LET_Framework_Result.h"

#define TEST_MAX_BUFFER_SIZE 128

#define TEST_NUM_BUFF 10


uint8_t LET_Framework_printer_stub_num;
char LET_Framework_printer_buffer[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];

const char cleaner[TEST_MAX_BUFFER_SIZE] = {0};

uint8_t LET_uint_to_decimal_string_stub_num;
uint64_t LET_uint_to_decimal_string_stub_value[TEST_NUM_BUFF];

uint8_t LET_xml_open_balise_stub_num;
char LET_xml_open_balise_balise_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
uint8_t LET_xml_open_balise_new_line[TEST_NUM_BUFF];
uint8_t LET_xml_open_balise_tabulation[TEST_NUM_BUFF];
uint8_t LET_xml_open_balise_close[TEST_NUM_BUFF];

uint8_t LET_xml_close_balise_stub_num;
uint8_t LET_xml_close_balise_standalone[TEST_NUM_BUFF];

uint8_t LET_xml_add_parameter_stub_num;
char LET_xml_add_parameter_parameter_name[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];
char LET_xml_add_parameter_value[TEST_NUM_BUFF][TEST_MAX_BUFFER_SIZE];


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
    LET_uint_to_decimal_string_stub_num = 0;
    LET_xml_open_balise_stub_num = 0;
    LET_xml_close_balise_stub_num = 0;
    LET_xml_add_parameter_stub_num = 0;
    for(uint8_t i = 0; i<TEST_NUM_BUFF; i++){
        clean_data(LET_Framework_printer_buffer[i]);
        LET_uint_to_decimal_string_stub_value[i] = 0;
        clean_data(LET_xml_open_balise_balise_name[i]);
        LET_xml_open_balise_new_line[i] = 0;
        LET_xml_open_balise_tabulation[i] = 0;
        LET_xml_open_balise_close[i] = 0;
        LET_xml_close_balise_standalone[i] = 0;
        clean_data(LET_xml_add_parameter_parameter_name[i]);
        clean_data(LET_xml_add_parameter_value[i]);
    }
}

//Stub
void LET_uint_to_decimal_string(char str[], uint64_t num){
    LET_uint_to_decimal_string_stub_value[LET_uint_to_decimal_string_stub_num++] = num;
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
void LET_xml_add_parameter(const char *parameter_name, const char* value){
    copy(LET_xml_add_parameter_parameter_name[LET_xml_add_parameter_stub_num], parameter_name);
    copy(LET_xml_add_parameter_value[LET_xml_add_parameter_stub_num++], value);
}




void test_LET_init_printer(void){
    Reset_env();
    LET_init_printer();
    if(!strcmp(LET_Framework_printer_buffer[0], "\n<?xml version=\"1.0\" encoding=\"UTF-8\"?>")){
        printf("OK\n");
    }else{
        printf("XML DEFINITION  KO\n");
    }

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuites")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES STANDALONE ISSUE  KO\n");
    }
}

void test_LET_end_printer(void){
    Reset_env();
    LET_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuites")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITES STANDALONE ISSUE  KO\n");
    }

    if(!strcmp(LET_Framework_printer_buffer[0], "\n")){
        printf("OK\n");
    }else{
        printf("XML DEFINITION  KO\n");
    }

}

void test_LET_service_init_printer(void){
    Reset_env();

    LET_service_init_printer("Lambda", 23);

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuite")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE STANDALONE ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_parameter_name[0], "name")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[0], "Lambda")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_parameter_name[1], "tests")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[1], "")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n");
    }


    if(LET_uint_to_decimal_string_stub_value[0] ==  23){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n");
    }


}

void test_LET_service_end_printer(void){
    Reset_env();

    LET_service_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testsuite")){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE STANDALONE ISSUE  KO\n");
    }


}

void test_LET_test_init_printer(void){
    Reset_env();

    LET_test_init_printer("Alpha", "Beta");


    if(!strcmp(LET_xml_open_balise_balise_name[0], "testcase")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 2){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE STANDALONE ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_parameter_name[0], "name")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[0], "Alpha")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_parameter_name[1], "classname")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[1], "Beta")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }

}

void test_LET_test_end_printer(void){
    Reset_env();

    LET_test_end_printer();

    if(!strcmp(LET_xml_open_balise_balise_name[0], "testcase")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 2){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE STANDALONE ISSUE  KO\n");
    }


}

void test_LET_assert_printer(void){
    Reset_env();

    LET_assert_printer("Omega", LET_UINT, LET_EQUAL, "dataexp", "dataopt", "filename", 123);




    if(LET_uint_to_decimal_string_stub_value[0] ==  123){
        printf("OK\n");
    }else{
        printf("BALISE TESTSUITE PARAMETER VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_xml_open_balise_balise_name[0], "failure")){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[0] == 1){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[0] == 3){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[0] == 0){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE STANDALONE ISSUE  KO\n");
    }


    if(!strcmp(LET_xml_open_balise_balise_name[1], "failure")){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE NAME ISSUE  KO\n");
    }

    if(LET_xml_open_balise_new_line[1] == 1){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE NEWLINE ISSUE  KO\n");
    }

    if(LET_xml_open_balise_tabulation[1] == 3){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE TABULATION ISSUE  KO\n");
    }

    if(LET_xml_open_balise_close[1] == 1){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE CLOSING ISSUE  KO\n");
    }

    if(LET_xml_close_balise_standalone[1] == 0){
        printf("OK\n");
    }else{
        printf("BALISE FAILURE STANDALONE ISSUE  KO\n");
    }




    if(!strcmp(LET_xml_add_parameter_parameter_name[0], "message")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[0], "Omega")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER NAME ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_parameter_name[1], "type")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }

    if(!strcmp(LET_xml_add_parameter_value[1], "UINT")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_Framework_printer_buffer[0], "\n\t\t\t\tFILE : ")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
    if(!strcmp(LET_Framework_printer_buffer[1], "filename")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_Framework_printer_buffer[2], "\n\t\t\t\tLINE : ")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
    if(!strcmp(LET_Framework_printer_buffer[3], "\0")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE Sqsdqd VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_Framework_printer_buffer[4], "\n\t\t\t\tCOMPARE : ")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
    if(!strcmp(LET_Framework_printer_buffer[5], "EQUAL")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_Framework_printer_buffer[6], "\n\t\t\t\tEXPECTED : ")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
    if(!strcmp(LET_Framework_printer_buffer[7], "dataexp")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }


    if(!strcmp(LET_Framework_printer_buffer[8], "\n\t\t\t\tOBTAINED : ")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
    if(!strcmp(LET_Framework_printer_buffer[9], "dataopt")){
        printf("OK\n");
    }else{
        printf("BALISE TESTCASE PARAMETER VALUE ISSUE  KO\n");
    }
}




int main (){
    test_LET_init_printer();
    test_LET_end_printer();
    test_LET_service_init_printer();
    test_LET_service_end_printer();
    test_LET_test_init_printer();
    test_LET_test_end_printer();
    test_LET_assert_printer();

    return 0;
}
