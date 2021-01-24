#include "stdio.h"
#include "LET_Framework.h"

void empty_init (void){

}

void LET_Framework_printer (const char * data){
    printf("%s",data);
}

void mono_basic_assertion (Test *itself){
    uint8_t value = 9;
    #ifndef STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u",ASSERT_UINT(EQUAL,value,9));
    #else
    ASSERT_UINT(EQUAL,value,value);
    #endif
}

void dual_basic_assertion (Test *itself){
    int8_t value = -9;
    #ifndef STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u",ASSERT_INT(EQUAL, value, value));
    printf("\n| | | Result expected 0 got : %u",ASSERT_INT(NOT_EQUAL, value, value));
    #else
    ASSERT_INT(EQUAL, value, value);
    ASSERT_INT(NOT_EQUAL, value, value);
    #endif
}

void multi_basic_assertion (Test *itself){
    uint8_t uvalue = 9;
    int8_t ivalue = -9;

    #ifndef STOP_TEST_ON_FAILED
    printf("\n| | | Result expected 1 got : %u", ASSERT_UINT(EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 1 got : %u", ASSERT_UINT(LOWER_OR_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 1 got : %u", ASSERT_UINT(HIGHER_OR_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_UINT(NOT_EQUAL, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_UINT(LOWER_THAN, uvalue, uvalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_UINT(HIGHER_THAN, uvalue, uvalue));


    printf("\n| | | Result expected 1 got : %u", ASSERT_INT(EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 1 got : %u", ASSERT_INT(LOWER_OR_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 1 got : %u", ASSERT_INT(HIGHER_OR_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_INT(NOT_EQUAL, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_INT(LOWER_THAN, ivalue, ivalue));
    printf("\n| | | Result expected 0 got : %u", ASSERT_INT(HIGHER_THAN, ivalue, ivalue));
    #else
    ASSERT_UINT(EQUAL, uvalue, uvalue);
    ASSERT_UINT(LOWER_OR_EQUAL, uvalue, uvalue);
    ASSERT_UINT(HIGHER_OR_EQUAL, uvalue, uvalue);
    ASSERT_UINT(NOT_EQUAL, uvalue, uvalue);
    ASSERT_UINT(LOWER_THAN, uvalue, uvalue);
    ASSERT_UINT(HIGHER_THAN, uvalue, uvalue);


    ASSERT_INT(EQUAL, ivalue, ivalue);
    ASSERT_INT(LOWER_OR_EQUAL, ivalue, ivalue);
    ASSERT_INT(HIGHER_OR_EQUAL, ivalue, ivalue);
    ASSERT_INT(NOT_EQUAL, ivalue, ivalue);
    ASSERT_INT(LOWER_THAN, ivalue, ivalue);
    ASSERT_INT(HIGHER_THAN, ivalue, ivalue);
    #endif

}

void uint_format_assertion (Test *itself){
    uint8_t u8value = 192;
    uint16_t u16value = 47245;
    uint32_t u32value = 0xF3B7261A;
    uint64_t u64value = 0x0002FB36BF72261A;
    ASSERT_UINT(NOT_EQUAL, u8value+3, u8value, BYTE, BINARY);
    ASSERT_UINT(NOT_EQUAL, u8value+3, u8value, BYTE, OCTAL);
    ASSERT_UINT(NOT_EQUAL, u8value+3, u8value, BYTE, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value+3, u8value, BYTE);


    ASSERT_UINT(NOT_EQUAL, u16value+3, u16value, WORD, BINARY);
    ASSERT_UINT(NOT_EQUAL, u16value+3, u16value, WORD, OCTAL);
    ASSERT_UINT(NOT_EQUAL, u16value+3, u16value, WORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u16value+3, u16value, WORD);


    ASSERT_UINT(NOT_EQUAL, u32value+3, u32value, DWORD, BINARY);
    ASSERT_UINT(NOT_EQUAL, u32value+3, u32value, DWORD, OCTAL);
    ASSERT_UINT(NOT_EQUAL, u32value+3, u32value, DWORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u32value+3, u32value);


    ASSERT_UINT(NOT_EQUAL, u64value+3, u64value, QWORD, BINARY);
    ASSERT_UINT(NOT_EQUAL, u64value+3, u64value, QWORD, OCTAL);
    ASSERT_UINT(NOT_EQUAL, u64value+3, u64value, QWORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u64value+3, u64value, QWORD);
}

void uint_conversion_assertion (Test *itself){
    uint64_t u64value = 0x0002FB36BF72261A;
    uint8_t u8value = 0x1A;
    ASSERT_UINT(EQUAL, u8value, u64value, BYTE, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, WORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, DWORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, QWORD, HEXADECIMAL);
}

void str_assertion(Test *itself){
    char *lorem_ipsum = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged.";
    char *lorem_ipsum2 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry. Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, when an unknown printer took a galley of type and scrambled it to make a type specimen book. It has survived not only five centuries, but also the leap into electronic typesetting, remaining essentially unchanged!";
    char *lorem_ipsum3 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry.";
    char *lorem_ipsum4 = "Lorem Ipsum is simply dummy text of the printing and typesetting industry!";
    ASSERT_STR(EQUAL, lorem_ipsum, lorem_ipsum);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum2, lorem_ipsum);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum2, lorem_ipsum3);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum4, lorem_ipsum);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum2, lorem_ipsum4);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, BYTE, HEXADECIMAL);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, WORD, HEXADECIMAL);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, DWORD, HEXADECIMAL);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, QWORD, HEXADECIMAL);

    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, BYTE, BINARY);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, WORD, BINARY);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, DWORD, BINARY);
    ASSERT_STR(NOT_EQUAL, lorem_ipsum3, lorem_ipsum4, QWORD, BINARY);
}

void rename_assertion (Test *itself){
    uint8_t u8value = 0x1A;
    ASSERT_UINT(EQUAL, u8value, u8value, BYTE, HEXADECIMAL, "Rename uint assertion");
    ASSERT_INT(EQUAL, u8value, u8value, "Rename int assertion");
}

int main (){
    LET_init();
    Service mono_test = service_init("mono", empty_init);
    test_register(&mono_test, "mono_basic_assertion", mono_basic_assertion);
    service_runner(&mono_test);

    Service dual_test = service_init("dual", empty_init);
    test_register(&dual_test, "mono_basic_assertion", mono_basic_assertion);
    test_register(&dual_test, "dual_basic_assertion", dual_basic_assertion);
    service_runner(&dual_test);

    Service multi_test = service_init("multi", empty_init);
    test_register(&multi_test, "mono_basic_assertion", mono_basic_assertion);
    test_register(&multi_test, "dual_basic_assertion", dual_basic_assertion);
    test_register(&multi_test, "multi_basic_assertion", multi_basic_assertion);
    service_runner(&multi_test);

    Service format_test = service_init ("format", empty_init);
    test_register(&format_test, "uint_format_assertion", uint_format_assertion);
    test_register(&format_test, "uint_conversion_assertion", uint_conversion_assertion);
    test_register(&format_test, "rename_assertion", rename_assertion);
    test_register(&format_test, "str_assertion", str_assertion);
    service_runner(&format_test);
    LET_end();
    return 0;
}
