#include "stdio.h"
#include "string.h"

#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

#define TEST_MAX_BUFFER_SIZE 1024

uint32_t buffer_position;
uint8_t buffer[TEST_MAX_BUFFER_SIZE];
char lorem_ipsum[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.";
char *lorem_ipsum2 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!";


extern uint64_t LET_str_to_uint64(char*a, LET_ASSERT_PRECISION whitespace);
extern uint8_t LET_convert_uint_to_base(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION LET_bytes);


void LET_Framework_printer (const char * data){
    for(uint32_t i = 0; buffer_position<TEST_MAX_BUFFER_SIZE && data[i] != '\0'; i++){
        buffer[buffer_position] = data[i];
        buffer_position++;
    }
    if(TEST_MAX_BUFFER_SIZE == buffer_position) {
        printf("\n\n\nWARNING TEST BUFFER FULL\n\n\n");
    }
}

void Reset_env(void){
    for(buffer_position = 0; buffer_position < TEST_MAX_BUFFER_SIZE; buffer_position++) buffer[buffer_position] = '\0';
    buffer_position = 0;
}

void test_LET_xml_open_balise(void){
    Reset_env();
    LET_xml_open_balise("NAME", 0, 0, 0);
    if(!strcmp(buffer, "<NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 0, 0, 0) KO\n");
    }


    Reset_env();
    LET_xml_open_balise("NAME", 1, 0, 0);
    if(!strcmp(buffer, "\n<NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 1, 0, 0) KO\n");
    }
    Reset_env();
    LET_xml_open_balise("NAME", 0, 0, 1);
    if(!strcmp(buffer, "</NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 0, 0, 1) KO\n");
    }

    Reset_env();
    LET_xml_open_balise("NAME", 0, 1, 0);
    if(!strcmp(buffer, "\t<NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 0, 1, 0) KO\n");
    }

    Reset_env();
    LET_xml_open_balise("NAME", 0, 2, 0);
    if(!strcmp(buffer, "\t\t<NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 0, 2, 0) KO\n");
    }

    Reset_env();
    LET_xml_open_balise("NAME", 1, 3, 1);
    if(!strcmp(buffer, "\n\t\t\t</NAME")){
        printf("OK\n");
    }else{
        printf("LET_xml_open_balise(\"NAME\", 1, 3, 1) KO\n");
    }

}

void test_LET_xml_close_balise(void){
    Reset_env();
    LET_xml_close_balise(0);
    if(!strcmp(buffer, ">")){
        printf("OK\n");
    }else{
        printf("LET_xml_close_balise(0) KO\n");
    }

    Reset_env();
    LET_xml_close_balise(1);
    if(!strcmp(buffer, "/>")){
        printf("OK\n");
    }else{
        printf("LET_xml_close_balise(1) KO\n");
    }
}

void test_LET_xml_add_parameter(void){
    Reset_env();
    LET_xml_add_parameter("PARAM_NAME", "value");
    if(!strcmp(buffer, " PARAM_NAME=\"value\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_parameter(\"PARAM_NAME\", \"value\") KO\n");
    }
}


void test_LET_uint_to_decimal_string(void){
    Reset_env();
    LET_uint_to_decimal_string(buffer, 0);
    if(!strcmp(buffer, "0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_string(buffer, 0) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_string(buffer, 1);
    if(!strcmp(buffer, "1")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_string(buffer, 1) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_string(buffer, 12);
    if(!strcmp(buffer, "12")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_string(buffer, 12) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_string(buffer, 123);
    if(!strcmp(buffer, "123")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_string(buffer, 123) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_string(buffer, 1234567890987654321);
    if(!strcmp(buffer, "1234567890987654321")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_string(buffer, 1234567890987654321) KO\n");
    }


}

void test_LET_uint_to_base_string(void){
    Reset_env();
    LET_uint_to_base_string(buffer, 0x00, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, "0b00000000")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_string(buffer, 0b00000000, LET_BINARY, LET_BYTE) KO\n");
    }

    Reset_env();
    LET_uint_to_base_string(buffer, 0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, "0x00000000DEADBEEF")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_string(buffer, 0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_uint_to_base_string(buffer, 0xA72FA32, LET_OCTAL, LET_DWORD);
    if(!strcmp(buffer, "0c01234575062")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_string(buffer, 0c01234575062, LET_OCTAL, LET_DWORD) KO\n");
    }
}

void test_LET_int_to_string(void){
    Reset_env();
    LET_int_to_string(buffer, 0);
    if(!strcmp(buffer, "0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, 0) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, 1);
    if(!strcmp(buffer, "1")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, 1) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, -1);
    if(!strcmp(buffer, "-1")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, -1) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, 12);
    if(!strcmp(buffer, "12")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, 12) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, -12);
    if(!strcmp(buffer, "-12")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, -12) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, 1234567890987654321);
    if(!strcmp(buffer, "1234567890987654321")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, 1234567890987654321) KO\n");
    }

    Reset_env();
    LET_int_to_string(buffer, -1234567890987654321);
    if(!strcmp(buffer, "-1234567890987654321")){
        printf("OK\n");
    }else{
        printf("LET_int_to_string(buffer, -1234567890987654321) KO\n");
    }

}

void test_LET_compare_str(void){
    Reset_env();
    if(!LET_compare_str("", "") == !strcmp("","")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"\", \"\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("a", "") == !strcmp("a","")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"a\", \"\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("", "a") == !strcmp("","a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"\", \"a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("a", "a") == !strcmp("a","a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"a\", \"a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("a1", "a") == !strcmp("a1","a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"a1\", \"a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("a", "a1") == !strcmp("a","a1")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"a\", \"a1\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("a", "b") == !strcmp("a","b")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"a\", \"b\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("b", "a") == !strcmp("b","a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"b\", \"a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("1a", "1a") == !strcmp("1a","1a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"1a\", \"1a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("1a", "1b") == !strcmp("1a","1b")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"1a\", \"1b\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("1b", "1a") == !strcmp("1b","1a")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"1b\", \"1a\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("lorem_ipsum", "lorem_ipsum") == !strcmp("lorem_ipsum","lorem_ipsum")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"lorem_ipsum\", \"lorem_ipsum\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("lorem_ipsum", "lorem_ipsum2") == !strcmp("lorem_ipsum","lorem_ipsum2")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"lorem_ipsum\", \"lorem_ipsum2\") KO\n");
    }

    Reset_env();
    if(!LET_compare_str("lorem_ipsum2", "lorem_ipsum") == !strcmp("lorem_ipsum2","lorem_ipsum")){
        printf("OK\n");
    }else{
        printf("LET_compare_str(\"lorem_ipsum2\", \"lorem_ipsum\") KO\n");
    }
}

void test_LET_str_size(void){
    Reset_env();
    if(LET_str_size("") == strlen("")){
        printf("OK\n");
    }else{
        printf("LET_str_size(\"\") KO\n");
    }

    Reset_env();
    if(LET_str_size("a") == strlen("a")){
        printf("OK\n");
    }else{
        printf("LET_str_size(\"a\") KO\n");
    }

    Reset_env();
    if(LET_str_size("a1") == strlen("a1")){
        printf("OK\n");
    }else{
        printf("LET_str_size(\"a1\") KO\n");
    }

    Reset_env();
    if(LET_str_size(lorem_ipsum) == strlen(lorem_ipsum)){
        printf("OK\n");
    }else{
        printf("LET_str_size(lorem_ipsum) KO\n");
    }
}

void test_LET_str_convert(void){
    Reset_env();
}

void test_LET_str_to_uint64(void){
    uint64_t result = 0;
    char data[] = {(char)0xDEu, (char)0xADu, (char)0xBEu, (char)0xEFu, (char)0xDEu, (char)0xADu, (char)0xBEu, (char)0xEFu};

    Reset_env();
    result = LET_str_to_uint64(data, LET_BYTE);
    if(0xDEu == result){
        printf("OK\n");
    }else{
        printf("LET_str_to_uint64(data, LET_BYTE) KO\n");
    }

    Reset_env();
    result = LET_str_to_uint64(data, LET_WORD);
    if(0xDEADu == result){
        printf("OK\n");
    }else{
        printf("LET_str_to_uint64(data, LET_WORD) KO\n");
    }

    Reset_env();
    result = LET_str_to_uint64(data, LET_DWORD);
    if(0xDEADBEEFu == result){
        printf("OK\n");
    }else{
        printf("LET_str_to_uint64(data, LET_DWORD) KO\n");
    }

    Reset_env();
    result = LET_str_to_uint64(data, LET_QWORD);
    if(0xDEADBEEFDEADBEEFu == result){
        printf("OK\n");
    }else{
        printf("LET_str_to_uint64(data, LET_QWORD) KO\n");
    }

}

void test_LET_convert_uint_to_base(void){
    Reset_env();
    LET_convert_uint_to_base(buffer, 0, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, "00000000")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base(buffer, 0, LET_BINARY, LET_BYTE) KO\n");
    }

    Reset_env();
    LET_convert_uint_to_base(buffer, 0xDEADBEEFDEADBEEF, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, "DEADBEEFDEADBEEF")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base(buffer, 0xDEADBEEFDEADBEEF, LET_HEXADECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_convert_uint_to_base(buffer, 0xA72FA32, LET_OCTAL, LET_QWORD);
    if(!strcmp(buffer, "0000000000001234575062")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base(buffer, 0000000000001234575062, LET_OCTAL, LET_QWORD) KO\n");
    }
}




int main (){
    test_LET_xml_open_balise();
    test_LET_xml_close_balise();
    test_LET_xml_add_parameter();

    test_LET_uint_to_decimal_string();
    test_LET_uint_to_base_string();
    test_LET_int_to_string();
    test_LET_compare_str();
    test_LET_str_size();
    test_LET_str_convert();
    test_LET_str_to_uint64();
    test_LET_convert_uint_to_base();


    return 0;
}
