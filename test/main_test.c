#include "stdio.h"
#include "LET_Framework.h"

void empty_init (void){

}

void LET_Framework_printer (const char * data){
    printf(data);
}

void mono_basic_assertion (void){
    uint8_t value = 9;
    printf("\n|    Result expected 1 got : %u",ASSERT_UINT(EQUAL,value,value));
}

void dual_basic_assertion (void){
    int8_t value = -9;
    printf("\n|    Result expected 1 got : %u",ASSERT_INT(EQUAL, value, value));
    printf("\n|    Result expected 0 got : %u",ASSERT_INT(NOT_EQUAL, value, value));
}

void multi_basic_assertion (void){
    uint8_t uvalue = 9;
    int8_t ivalue = -9;

    printf("\n|    Result expected 1 got : %u", ASSERT_UINT(EQUAL, uvalue, uvalue));
    printf("\n|    Result expected 1 got : %u", ASSERT_UINT(LOWER_OR_EQUAL, uvalue, uvalue));
    printf("\n|    Result expected 1 got : %u", ASSERT_UINT(HIGHER_OR_EQUAL, uvalue, uvalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_UINT(NOT_EQUAL, uvalue, uvalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_UINT(LOWER_THAN, uvalue, uvalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_UINT(HIGHER_THAN, uvalue, uvalue));


    printf("\n|    Result expected 1 got : %u", ASSERT_INT(EQUAL, ivalue, ivalue));
    printf("\n|    Result expected 1 got : %u", ASSERT_INT(LOWER_OR_EQUAL, ivalue, ivalue));
    printf("\n|    Result expected 1 got : %u", ASSERT_INT(HIGHER_OR_EQUAL, ivalue, ivalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_INT(NOT_EQUAL, ivalue, ivalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_INT(LOWER_THAN, ivalue, ivalue));
    printf("\n|    Result expected 0 got : %u", ASSERT_INT(HIGHER_THAN, ivalue, ivalue));


}

void uint_format_assertion (void){
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

void uint_conversion_assertion (void){
    uint64_t u64value = 0x0002FB36BF72261A;
    uint8_t u8value = 0x1A;
    ASSERT_UINT(EQUAL, u8value, u64value, BYTE, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, WORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, DWORD, HEXADECIMAL);
    ASSERT_UINT(NOT_EQUAL, u8value, u64value, QWORD, HEXADECIMAL);
}

int main (){
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

    Service format_test = service_init ("formart", empty_init);
    test_register(&format_test, "uint_format_assertion", uint_format_assertion);
    test_register(&format_test, "uint_conversion_assertion", uint_conversion_assertion);
    service_runner(&format_test);

    return 0;
}
