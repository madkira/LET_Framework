#include <stdint.h>
#include <stdio.h>
#include "LET_Framework.h"

void empty_init (void){

}

void function_to_test(uint8_t number){
    printf("In code debug %u", number);
}
void function_to_test_multiline(void){
    printf("\nalpha\nbeta\ncharly\ndelta\necho\n");
}

void LET_Framework_printer (const char * const data){
    printf("%s",data);
}

void mono_basic_assertion (LET_Test *itself){
    uint8_t value = 9;
    #ifndef LET_STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u",LET_ASSERT_UINT(LET_EQUAL,value,9));
    #else
    LET_ASSERT_UINT(LET_EQUAL,value,value);
    #endif
}

void dual_basic_assertion (LET_Test *itself){
    int8_t value = -9;
    #ifndef LET_STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u",LET_ASSERT_INT(LET_EQUAL, value, value));
    printf("\n| | | Result expected 0 got : %u",LET_ASSERT_INT(LET_NOT_EQUAL, value, value));
    #else
    LET_ASSERT_INT(LET_EQUAL, value, value);
    LET_ASSERT_INT(LET_NOT_EQUAL, value, value);
    #endif
}

void multi_basic_assertion (LET_Test *itself){
    uint8_t uvalue = 9;
    int8_t ivalue = -9;

    #ifndef LET_STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_UINT(LET_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_UINT(LET_LOWER_OR_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_UINT(LET_HIGHER_OR_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_UINT(LET_NOT_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_UINT(LET_LOWER_THAN, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_UINT(LET_HIGHER_THAN, uvalue, uvalue));


    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_INT(LET_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_INT(LET_LOWER_OR_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 1 got : %u", LET_ASSERT_INT(LET_HIGHER_OR_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_INT(LET_NOT_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_INT(LET_LOWER_THAN, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", LET_ASSERT_INT(LET_HIGHER_THAN, ivalue, ivalue));
    #else
    LET_ASSERT_UINT(LET_EQUAL, uvalue, uvalue);
    LET_ASSERT_UINT(LET_LOWER_OR_EQUAL, uvalue, uvalue);
    LET_ASSERT_UINT(LET_HIGHER_OR_EQUAL, uvalue, uvalue);
    LET_ASSERT_UINT(LET_NOT_EQUAL, uvalue, uvalue);
    LET_ASSERT_UINT(LET_LOWER_THAN, uvalue, uvalue);
    LET_ASSERT_UINT(LET_HIGHER_THAN, uvalue, uvalue);


    LET_ASSERT_INT(LET_EQUAL, ivalue, ivalue);
    LET_ASSERT_INT(LET_LOWER_OR_EQUAL, ivalue, ivalue);
    LET_ASSERT_INT(LET_HIGHER_OR_EQUAL, ivalue, ivalue);
    LET_ASSERT_INT(LET_NOT_EQUAL, ivalue, ivalue);
    LET_ASSERT_INT(LET_LOWER_THAN, ivalue, ivalue);
    LET_ASSERT_INT(LET_HIGHER_THAN, ivalue, ivalue);
    #endif

}

void uint_format_assertion (LET_Test *itself){
    uint8_t u8value = 192;
    uint16_t u16value = 47245;
    uint32_t u32value = 0xF3B7261A;
    uint64_t u64value = 0x0002FB36BF72261A;
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value+3, u8value, LET_BYTE, LET_BINARY);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value+3, u8value, LET_BYTE, LET_OCTAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value+3, u8value, LET_BYTE, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value+3, u8value, LET_BYTE);


    LET_ASSERT_UINT(LET_NOT_EQUAL, u16value+3, u16value, LET_WORD, LET_BINARY);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u16value+3, u16value, LET_WORD, LET_OCTAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u16value+3, u16value, LET_WORD, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u16value+3, u16value, LET_WORD);


    LET_ASSERT_UINT(LET_NOT_EQUAL, u32value+3, u32value, LET_DWORD, LET_BINARY);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u32value+3, u32value, LET_DWORD, LET_OCTAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u32value+3, u32value, LET_DWORD, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u32value+3, u32value);


    LET_ASSERT_UINT(LET_NOT_EQUAL, u64value+3, u64value, LET_QWORD, LET_BINARY);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u64value+3, u64value, LET_QWORD, LET_OCTAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u64value+3, u64value, LET_QWORD, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u64value+3, u64value, LET_QWORD);
}

void uint_conversion_assertion (LET_Test *itself){
    uint64_t u64value = 0x0002FB36BF72261A;
    uint8_t u8value = 0x1A;
    LET_ASSERT_UINT(LET_EQUAL, u8value, u64value, LET_BYTE, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value, u64value, LET_WORD, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value, u64value, LET_DWORD, LET_HEXADECIMAL);
    LET_ASSERT_UINT(LET_NOT_EQUAL, u8value, u64value, LET_QWORD, LET_HEXADECIMAL);
}

void str_assertion(LET_Test *itself){
    char *lorem_ipsum = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.";
    char *lorem_ipsum2 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!";
    char *lorem_ipsum3 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
    char *lorem_ipsum4 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry!";
    LET_ASSERT_STR(LET_EQUAL, lorem_ipsum, lorem_ipsum);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum2, lorem_ipsum);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum3, lorem_ipsum);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum2, lorem_ipsum3);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum4, lorem_ipsum);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum2, lorem_ipsum4);
    LET_ASSERT_STR(LET_NOT_EQUAL, lorem_ipsum3, lorem_ipsum4);
}

void array_assertion(LET_Test *itself){
    char *data1 = "azertyuiop\0\0sxfgyhnjkl";
    char *data2 = "azertyuiop\n\0sxfgyhnjkl";
    LET_ASSERT_ARRAY(LET_EQUAL, data1, data1, 23);
    LET_ASSERT_ARRAY(LET_NOT_EQUAL, data1, data2, 23);
}

void rename_assertion (LET_Test *itself){
    uint8_t u8value = 0x1A;
    LET_ASSERT_UINT(LET_EQUAL, u8value, u8value, LET_BYTE, LET_HEXADECIMAL, "Rename uint assertion");
    LET_ASSERT_INT(LET_EQUAL, u8value, u8value, "Rename int assertion");
}


LET_TEST(debug_print_one_line){
    LET_CALL_WRAP(function_to_test(3u));
    LET_ASSERT_UINT(LET_EQUAL, 1u,1u);
}

LET_TEST(debug_print_multi_lines){
    LET_CALL_WRAP(function_to_test_multiline());
    LET_ASSERT_UINT(LET_EQUAL, 1u,1u);
}

int main (){
    LET_init();
    LET_Service mono_test = LET_service_init("mono", empty_init);
    LET_test_register(&mono_test, "mono_basic_assertion", mono_basic_assertion);
    LET_service_runner(&mono_test);

    LET_Service dual_test = LET_service_init("dual", empty_init);
    LET_test_register(&dual_test, "mono_basic_assertion", mono_basic_assertion);
    LET_test_register(&dual_test, "dual_basic_assertion", dual_basic_assertion);
    LET_service_runner(&dual_test);

    LET_Service multi_test = LET_service_init("multi", empty_init);
    LET_test_register(&multi_test, "mono_basic_assertion", mono_basic_assertion);
    LET_test_register(&multi_test, "dual_basic_assertion", dual_basic_assertion);
    LET_test_register(&multi_test, "multi_basic_assertion", multi_basic_assertion);
    LET_service_runner(&multi_test);

    LET_Service format_test = LET_service_init ("format", empty_init);
    LET_test_register(&format_test, "uint_format_assertion", uint_format_assertion);
    LET_test_register(&format_test, "uint_conversion_assertion", uint_conversion_assertion);
    LET_test_register(&format_test, "rename_assertion", rename_assertion);
    LET_test_register(&format_test, "str_assertion", str_assertion);
    LET_test_register(&format_test, "array_assertion", array_assertion);
    LET_service_runner(&format_test);

    LET_Service debug_test = LET_service_init ("debug", empty_init);
    LET_test_register(&debug_test, "debug_print_one_line", debug_print_one_line);
    LET_test_register(&debug_test, "debug_print_multi_lines", debug_print_multi_lines);
    LET_service_runner(&debug_test);

    LET_end();
    return 0;
}
