#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "LET_Framework.h"
#include "LET_Framework_Result.h"


uint8_t count_LET_assert_printer;
uint8_t count_LET_uint_to_decimal_string;
uint8_t count_LET_uint_to_base_string;
uint8_t count_LET_int_to_string;
uint8_t count_LET_compare_str;
uint8_t count_LET_str_size;


char null_char[] = "null\n";

char *LET_assert_printer_expected_name;
LET_ASSERT_TYPE  LET_assert_printer_expected_type;
LET_ASSERT_COMPARE  LET_assert_printer_expected_compare;
char *LET_assert_printer_expected_expected;
char *LET_assert_printer_expected_obtained;
char *LET_uint_to_decimal_string_expected_str[2];
uint64_t LET_uint_to_decimal_string_expected_num[2];
char *LET_uint_to_base_string_expected_str[2];
uint64_t LET_uint_to_base_string_expected_num[2];
LET_ASSERT_REPRESENT LET_uint_to_base_string_expected_format[2];
LET_ASSERT_PRECISION LET_uint_to_base_string_expected_bytes[2];
char *LET_int_to_string_expected_str[2];
uint64_t LET_int_to_string_expected_num[2];
char *LET_compare_str_expected_a[2];
char *LET_compare_str_expected_b[2];
char *LET_str_size_expected_a[2];


void Reset_env(void){
  count_LET_assert_printer = 0;
  count_LET_uint_to_decimal_string = 0;
  count_LET_uint_to_base_string = 0;
  count_LET_int_to_string = 0;
  count_LET_compare_str = 0;
  count_LET_str_size = 0;

  LET_assert_printer_expected_name = null_char;
  LET_assert_printer_expected_expected = null_char;
  LET_assert_printer_expected_obtained = null_char;
  LET_uint_to_decimal_string_expected_str[0] = null_char;
  LET_uint_to_decimal_string_expected_str[1] = null_char;
  LET_uint_to_base_string_expected_str[0] = null_char;
  LET_uint_to_base_string_expected_str[1] = null_char;
  LET_int_to_string_expected_str[0] = null_char;
  LET_int_to_string_expected_str[1] = null_char;
  LET_compare_str_expected_a[0] = null_char;
  LET_compare_str_expected_a[1] = null_char;
  LET_compare_str_expected_b[0] = null_char;
  LET_compare_str_expected_b[1] = null_char;
  LET_str_size_expected_a[0] = null_char;
  LET_str_size_expected_a[1] = null_char;

  LET_uint_to_decimal_string_expected_num[0] = 0;
  LET_uint_to_decimal_string_expected_num[1] = 0;
  LET_uint_to_base_string_expected_num[0] = 0;
  LET_uint_to_base_string_expected_num[1] = 0;
  LET_int_to_string_expected_num[0] = 0;
  LET_int_to_string_expected_num[1] = 0;

  LET_assert_printer_expected_type = 0;
  LET_assert_printer_expected_compare = 0;
  LET_uint_to_base_string_expected_format[0] = 0;
  LET_uint_to_base_string_expected_format[1] = 0;
  LET_uint_to_base_string_expected_bytes[0] = 0;
  LET_uint_to_base_string_expected_bytes[1] = 0;

}

/****************************************************************************************
 * BEGIN STUB
 ****************************************************************************************/
void LET_assert_printer(char *name,
                  LET_ASSERT_TYPE type,
                  LET_ASSERT_COMPARE compare,
                  char *expected,
                  char *obtained
){
  if(!strcmp(LET_assert_printer_expected_name, name)){
    printf("OK\n");
  }else {
    printf("LET_assert_printer name  KO\n");
  }
  if(LET_assert_printer_expected_type == type){
    printf("OK\n");
  }else {
    printf("LET_assert_printer type  KO\n");
  }
  if(LET_assert_printer_expected_compare == compare){
    printf("OK\n");
  }else {
    printf("LET_assert_printer compare  KO\n");
  }
  if(!strcmp(LET_assert_printer_expected_expected, expected)){
    printf("OK\n");
  }else {
    printf("LET_assert_printer expected  KO\n");
  }
  if(!strcmp(LET_assert_printer_expected_obtained, obtained)){
    printf("OK\n");
  }else {
    printf("LET_assert_printer obtained  KO\n");
  }

  count_LET_assert_printer++;
}

void LET_uint_to_decimal_string(char str[], uint64_t num){
  if(!strcmp(LET_uint_to_decimal_string_expected_str[count_LET_uint_to_decimal_string], str)){
    printf("OK\n");
  }else {
    printf("LET_uint_to_decimal_string str  KO\n");
  }
  if(LET_uint_to_decimal_string_expected_num[count_LET_uint_to_decimal_string] == num){
    printf("OK\n");
  }else {
    printf("LET_uint_to_decimal_string num  KO\n");
  }
  count_LET_uint_to_decimal_string++;
}

void LET_uint_to_base_string(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  if(!strcmp(LET_uint_to_base_string_expected_str[count_LET_uint_to_base_string], str)){
    printf("OK\n");
  }else {
    printf("LET_uint_to_base_string str  KO\n");
  }
  if(LET_uint_to_base_string_expected_num[count_LET_uint_to_base_string] == num){
    printf("OK\n");
  }else {
    printf("LET_uint_to_base_string num  KO\n");
  }
  if(LET_uint_to_base_string_expected_format[count_LET_uint_to_base_string] == format){
    printf("OK\n");
  }else {
    printf("LET_uint_to_base_string format  KO\n");
  }
  if(LET_uint_to_base_string_expected_bytes[count_LET_uint_to_base_string] == bytes){
    printf("OK\n");
  }else {
    printf("LET_uint_to_base_string bytes  KO\n");
  }
  count_LET_uint_to_base_string++;
}

void LET_int_to_string(char str[], int64_t num){
  if(!strcmp(LET_int_to_string_expected_str[count_LET_int_to_string], str)){
    printf("OK\n");
  }else {
    printf("LET_int_to_string str  KO\n");
  }
  if(LET_int_to_string_expected_num[count_LET_int_to_string] == num){
    printf("OK\n");
  }else {
    printf("LET_int_to_string num  KO\n");
  }
  count_LET_int_to_string++;
}

uint8_t LET_compare_str(char *a, char *b){
  if(!strcmp(LET_compare_str_expected_a[count_LET_compare_str], a)){
    printf("OK\n");
  }else {
    printf("LET_compare_str a  KO\n");
  }
  if(!strcmp(LET_compare_str_expected_b[count_LET_compare_str], b)){
    printf("OK\n");
  }else {
    printf("LET_compare_str b  KO\n");
  }
  count_LET_compare_str++;
  return 0;
}

uint32_t LET_str_size(char *a){
  if(!strcmp(LET_str_size_expected_a[count_LET_str_size], a)){
    printf("OK\n");
  }else {
    printf("LET_str_size a  KO\n");
  }
  count_LET_str_size++;
  return 0;
}

/****************************************************************************************
 * END STUB
 ****************************************************************************************/




void test_LET_ASSERT_uint(void){
  Reset_env();
  LET_Test itself;
  LET_ASSERT_RESULT result = LET_ASSERT_uint(LET_EQUAL,32,32,LET_BYTE,LET_DECIMAL,"alpha",&itself);
}

void test_LET_ASSERT_int(void){
  Reset_env();

}

void test_LET_ASSERT_str(void){
  Reset_env();

}






int main (){
  test_LET_ASSERT_uint();
  test_LET_ASSERT_int();
  test_LET_ASSERT_str();
  return 0;
}
