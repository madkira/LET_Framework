#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "LET_Framework.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

#define TEST_MAX_BUFFER_SIZE 1024

uint32_t buffer_position;
char buffer[TEST_MAX_BUFFER_SIZE];
char lorem_ipsum[] = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.";
char *lorem_ipsum2 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!";


extern uint64_t LET_str_to_uint64(char*a, LET_ASSERT_PRECISION whitespace);
extern uint8_t LET_convert_uint_to_base(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION LET_bytes);
extern uint8_t LET_convert_uint_to_base_printer(uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION LET_bytes);


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

void test_LET_xml_str_add_parameter(void){
    Reset_env();
    LET_xml_add_str_parameter("PARAM_NAME", "value");
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



void test_LET_array_convert(void){
    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_HEXADECIMAL, LET_BYTE);
    if(!strcmp(buffer, "61 62 63 64 65 66 67 68 69 6A 6B 6C 6D 6E 6F 70 71 72 73 74 75 76 77 78 79 7A 20 00 20 31 32 33 34 35 36 37 38 39 30\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_HEXADECIMAL, LET_BYTE)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_HEXADECIMAL, LET_WORD);
    if(!strcmp(buffer, "6162 6364 6566 6768 696A 6B6C 6D6E 6F70 7172 7374 7576 7778 797A 2000 2031 3233 3435 3637 3839 30\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_HEXADECIMAL, LET_WORD)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_HEXADECIMAL, LET_DWORD);
    if(!strcmp(buffer, "61626364 65666768 696A6B6C 6D6E6F70 71727374 75767778 797A2000 20313233 34353637 383930\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_HEXADECIMAL, LET_DWORD)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, "6162636465666768 696A6B6C6D6E6F70 7172737475767778 797A200020313233 34353637383930\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_HEXADECIMAL, LET_QWORD)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, "01100001 01100010 01100011 01100100 01100101 01100110 01100111 01101000 01101001 01101010 01101011 01101100 01101101 01101110 01101111 01110000 01110001 01110010 01110011 01110100 01110101 01110110 01110111 01111000 01111001 01111010 00100000 00000000 00100000 00110001 00110010 00110011 00110100 00110101 00110110 00110111 00111000 00111001 00110000\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_BINARY, LET_BYTE)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_BINARY, LET_WORD);
    if(!strcmp(buffer, "0110000101100010 0110001101100100 0110010101100110 0110011101101000 0110100101101010 0110101101101100 0110110101101110 0110111101110000 0111000101110010 0111001101110100 0111010101110110 0111011101111000 0111100101111010 0010000000000000 0010000000110001 0011001000110011 0011010000110101 0011011000110111 0011100000111001 00110000\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_BINARY, LET_WORD)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_BINARY, LET_DWORD);
    if(!strcmp(buffer, "01100001011000100110001101100100 01100101011001100110011101101000 01101001011010100110101101101100 01101101011011100110111101110000 01110001011100100111001101110100 01110101011101100111011101111000 01111001011110100010000000000000 00100000001100010011001000110011 00110100001101010011011000110111 001110000011100100110000\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_BINARY, LET_DWORD)  %s KO\n", buffer);
    }

    Reset_env();
    LET_array_convert(buffer, "abcdefghijklmnopqrstuvwxyz \0 1234567890", 39, LET_BINARY, LET_QWORD);
    if(!strcmp(buffer, "0110000101100010011000110110010001100101011001100110011101101000 0110100101101010011010110110110001101101011011100110111101110000 0111000101110010011100110111010001110101011101100111011101111000 0111100101111010001000000000000000100000001100010011001000110011 00110100001101010011011000110111001110000011100100110000\0")){
        printf("OK\n");
    }else{
        printf("LET_array_convert(buffer, \"abcdefghijklmnopqrstuvwxyz \\0 1234567890\", 38, LET_BINARY, LET_QWORD)  %s KO\n", buffer);
    }

}


void test_LET_uint_to_decimal_printer(void){
    Reset_env();
    LET_uint_to_decimal_printer(0u);
    if(!strcmp(buffer, "0\0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_printer(0u) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_printer(1u);
    if(!strcmp(buffer, "1\0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_printer(1u) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_printer(12u);
    if(!strcmp(buffer, "12\0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_printer(12u) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_printer(1234567890987654321UL);
    if(!strcmp(buffer, "1234567890987654321\0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_printer(1234567890987654321UL) KO\n");
    }

    Reset_env();
    LET_uint_to_decimal_printer(0xFFFFFFFFFFFFFFFFUL);
    if(!strcmp(buffer, "18446744073709551615\0")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_decimal_printer(0xFFFFFFFFFFFFFFFFUL) KO\n");
    }

}


void test_LET_int_to_decimal_printer(void){
    Reset_env();
    LET_int_printer(0);
    if(!strcmp(buffer, "0\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(0) KO\n");
    }

    Reset_env();
    LET_int_printer(1);
    if(!strcmp(buffer, "1\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(1) KO\n");
    }

    Reset_env();
    LET_int_printer(12);
    if(!strcmp(buffer, "12\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(12) KO\n");
    }

    Reset_env();
    LET_int_printer(1234567890987654321L);
    if(!strcmp(buffer, "1234567890987654321\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(1234567890987654321L) KO\n");
    }

    Reset_env();
    LET_int_printer(0x7FFFFFFFFFFFFFFFL);
    if(!strcmp(buffer, "9223372036854775807\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(9223372036854775807) KO\n");
    }

    Reset_env();
    LET_int_printer(-1);
    if(!strcmp(buffer, "-1\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(-1) KO\n");
    }

    Reset_env();
    LET_int_printer(-12);
    if(!strcmp(buffer, "-12\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(-12) KO\n");
    }

    Reset_env();
    LET_int_printer(-1234567890987654321L);
    if(!strcmp(buffer, "-1234567890987654321\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(-1234567890987654321L) KO\n");
    }

    Reset_env();
    LET_int_printer((int64_t)0x8000000000000000L);
    if(!strcmp(buffer, "-9223372036854775808\0")){
        printf("OK\n");
    }else{
        printf("LET_int_to_decimal_printer(-9223372036854775808) %s KO\n", buffer);
    }

}


void test_LET_convert_uint_to_base_printer(void){
    Reset_env();
    LET_convert_uint_to_base_printer(0, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, "00000000")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base_printer(0, LET_BINARY, LET_BYTE) KO\n");
    }

    Reset_env();
    LET_convert_uint_to_base_printer(0xDEADBEEFDEADBEEF, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, "DEADBEEFDEADBEEF")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base_printer(0xDEADBEEFDEADBEEF, LET_HEXADECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_convert_uint_to_base_printer(0xA72FA32, LET_OCTAL, LET_QWORD);
    if(!strcmp(buffer, "0000000000001234575062")){
        printf("OK\n");
    }else{
        printf("LET_convert_uint_to_base_printer(0000000000001234575062, LET_OCTAL, LET_QWORD) KO\n");
    }
}

void test_LET_uint_to_base_printer(void){
    Reset_env();
    LET_uint_to_base_printer(0x00, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, "0b00000000")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_printer(0b00000000, LET_BINARY, LET_BYTE) KO\n");
    }

    Reset_env();
    LET_uint_to_base_printer(0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, "0x00000000DEADBEEF")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_printer(0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_uint_to_base_printer(0xA72FA32, LET_OCTAL, LET_DWORD);
    if(!strcmp(buffer, "0c01234575062")){
        printf("OK\n");
    }else{
        printf("LET_uint_to_base_printer(0c01234575062, LET_OCTAL, LET_DWORD) KO\n");
    }
}

void test_LET_xml_add_uint_parameter(void){
    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 1, LET_DECIMAL, LET_DWORD);
    if(!strcmp(buffer, " parameter uint=\"1\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 1, LET_DECIMAL, LET_DWORD) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 1234, LET_DECIMAL, LET_DWORD);
    if(!strcmp(buffer, " parameter uint=\"1234\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 1234, LET_DECIMAL, LET_DWORD) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 1234567890987654321UL, LET_DECIMAL, LET_QWORD);
    if(!strcmp(buffer,  " parameter uint=\"1234567890987654321\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 1234567890987654321UL, LET_DECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 0xFFFFFFFFFFFFFFFFUL, LET_DECIMAL, LET_QWORD);
    if(!strcmp(buffer,  " parameter uint=\"18446744073709551615\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 0xFFFFFFFFFFFFFFFFUL, LET_DECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 0x00, LET_BINARY, LET_BYTE);
    if(!strcmp(buffer, " parameter uint=\"0b00000000\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 0b00000000, LET_BINARY, LET_BYTE) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD);
    if(!strcmp(buffer, " parameter uint=\"0x00000000DEADBEEF\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 0x00000000DEADBEEF, LET_HEXADECIMAL, LET_QWORD) KO\n");
    }

    Reset_env();
    LET_xml_add_uint_parameter("parameter uint", 0xA72FA32, LET_OCTAL, LET_DWORD);
    if(!strcmp(buffer, " parameter uint=\"0c01234575062\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_uint_parameter(\"parameter uint\", 0c01234575062, LET_OCTAL, LET_DWORD) KO\n");
    }
}



void test_LET_xml_add_int_parameter(void){
    Reset_env();
    LET_xml_add_int_parameter("parameter int", 0);
    if(!strcmp(buffer, " parameter int=\"0\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", 0) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", 1);
    if(!strcmp(buffer, " parameter int=\"1\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", 1) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", 12);
    if(!strcmp(buffer, " parameter int=\"12\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", 12) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", 1234567890987654321L);
    if(!strcmp(buffer, " parameter int=\"1234567890987654321\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", 1234567890987654321L) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", 0x7FFFFFFFFFFFFFFFL);
    if(!strcmp(buffer, " parameter int=\"9223372036854775807\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", 9223372036854775807) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", -1);
    if(!strcmp(buffer, " parameter int=\"-1\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", -1) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", -12);
    if(!strcmp(buffer, " parameter int=\"-12\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", -12) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", -1234567890987654321L);
    if(!strcmp(buffer, " parameter int=\"-1234567890987654321\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", -1234567890987654321L) KO\n");
    }

    Reset_env();
    LET_xml_add_int_parameter("parameter int", (int64_t)0x8000000000000000L);
    if(!strcmp(buffer, " parameter int=\"-9223372036854775808\"")){
        printf("OK\n");
    }else{
        printf("LET_xml_add_int_parameter(\"parameter int\", -9223372036854775808) %s KO\n", buffer);
    }

}


int main (){
    test_LET_xml_open_balise();
    test_LET_xml_close_balise();
    test_LET_xml_str_add_parameter();

    test_LET_uint_to_decimal_string();
    test_LET_uint_to_base_string();
    test_LET_int_to_string();
    test_LET_compare_str();
    test_LET_str_to_uint64();
    test_LET_convert_uint_to_base();

    test_LET_array_convert();

    test_LET_uint_to_decimal_printer();
    test_LET_int_to_decimal_printer();
    test_LET_convert_uint_to_base_printer();
    test_LET_uint_to_base_printer();
    test_LET_xml_add_uint_parameter();
    test_LET_xml_add_int_parameter();

    return 0;
}
