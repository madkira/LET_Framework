#include "stdio.h"
#include "LET_Framework.h"

void empty_init (void){

}

void LET_Framework_printer (char * data){
    printf(data);
}

void mono_assertion (void){
    uint8_t value = 9;
    printf("\n|    Result expected 1 got : %u",ASSERT_UINT(EQUAL,value,value));
}

void dual_assertion (void){
    int8_t value = -9;
    printf("\n|    Result expected 1 got : %u",ASSERT_INT(EQUAL, value, value));
    printf("\n|    Result expected 0 got : %u",ASSERT_INT(NOT_EQUAL, value, value));
}

void multi_assertion (void){
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

int main (){
    Service mono_test = service_init("mono", empty_init);
    test_register(&mono_test, "mono_assertion", mono_assertion);
    service_runner(&mono_test);

    Service dual_test = service_init("dual", empty_init);
    test_register(&dual_test, "mono_assertion", mono_assertion);
    test_register(&dual_test, "dual_assertion", dual_assertion);
    service_runner(&dual_test);

    Service multi_test = service_init("multi", empty_init);
    test_register(&multi_test, "mono_assertion", mono_assertion);
    test_register(&multi_test, "dual_assertion", dual_assertion);
    test_register(&multi_test, "multi_assertion", multi_assertion);
    service_runner(&multi_test);


    return 0;
}
