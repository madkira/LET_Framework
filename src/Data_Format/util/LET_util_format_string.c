/*******************************************************************************
 ** File Name : LET_Framework_Result.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +----------------------------------------------------+
// | LET_Framework_Result includes                      |
// +----------------------------------------------------+
// Temporary Shared library Might be removed for no dependency purpose
#include <stdint.h>
#include "LET_Framework.h"
#include "LET_Framework_Result.h"
#include "LET_util_format_string.h"

// +----------------------------------------------------+
// | LET_Framework_Result macros                        |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result types                         |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result variables                     |
// +----------------------------------------------------+
const char *LET_ASSERT_COMPARE_STRING[] = {
  LET_FOREACH_COMPARE(LET_GENERATE_STRING)
};

const char *LET_ASSERT_TYPE_STRING[] = {
  LET_FOREACH_TYPE(LET_GENERATE_STRING)
};

const char *LET_ASSERT_RESULT_STRING[] = {
  LET_FOREACH_RESULT(LET_GENERATE_STRING)
};

#define LET_CHAR_HEXADECIMAL "0123456789ABCDEF"
#define LET_BEGIN_HEXADECIMAL 'x'
#define LET_BEGIN_OCTAL 'c'
#define LET_BEGIN_BINARY 'b'

#define LET_MASK_HEXADECIMAL 0x0F
#define LET_MASK_OCTAL 0x07
#define LET_MASK_BINARY 0x01

#define LET_BIT_NUMBER_HEXADECIMAL 4u
#define LET_BIT_NUMBER_OCTAL 3u
#define LET_BIT_NUMBER_BINARY 1u

// +----------------------------------------------------+
// | LET_Framework_Result extern functions definition   |
// +----------------------------------------------------+
extern void LET_Framework_printer(const char *const data);


// +----------------------------------------------------+
// | LET_Framework_Result private functions definition  |
// +----------------------------------------------------+
uint64_t LET_str_to_uint64(const char *const a, LET_ASSERT_PRECISION whitespace);

// +----------------------------------------------------+
// | LET_Framework_Result private functions declaration |
// +----------------------------------------------------+
uint64_t LET_str_to_uint64(const char *const a, LET_ASSERT_PRECISION whitespace){
  uint64_t result = 0u;
  for(uint8_t i=0; i < whitespace; i++ ){
    result = result<<8 | (uint8_t) a[i];
  }
  return result;
}

// +----------------------------------------------------+
// | LET_Framework_Result public functions declaration  |
// +----------------------------------------------------+
void LET_uint_to_decimal_string(char str[], uint64_t num){
  uint8_t i, rem, len = 0;
  uint64_t  n = num;

  do{
    len++;
    n /= 10;
  }while (n != 0);

  for (i = 0; i < len; i++){
    rem = (uint8_t)(num % 10);
    num = num / 10;
    *((uint8_t*)&str[len - (i + 1)]) = rem + '0';
  }

  str[len] = '\0';
}

uint8_t LET_convert_uint_to_base(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  uint8_t i;
  uint8_t mask_format = (uint8_t) (LET_BINARY == format)? LET_MASK_BINARY : (LET_OCTAL == format)? LET_MASK_OCTAL : LET_MASK_HEXADECIMAL;
  uint8_t bit_number = (uint8_t) (LET_BINARY == format)? LET_BIT_NUMBER_BINARY : (LET_OCTAL == format)? LET_BIT_NUMBER_OCTAL : LET_BIT_NUMBER_HEXADECIMAL;
  uint8_t character_number = (uint8_t) (((LET_OCTAL == format)?2:0) +(bytes*8))/bit_number;
  for(i=0; i < character_number; i++){
    str[i] = LET_CHAR_HEXADECIMAL[(num>>((character_number-i-1)*bit_number))&mask_format];
  }
  return i;
}

void LET_uint_to_base_string(char str[], uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  uint8_t i;
  str[0] = '0';
  str[1] = (LET_BINARY == format)? LET_BEGIN_BINARY : (LET_OCTAL == format)? LET_BEGIN_OCTAL : LET_BEGIN_HEXADECIMAL;
  i = LET_convert_uint_to_base(str+2, num, format, bytes);
  str[2+i] = '\0';
}


void LET_int_to_string(char str[], int64_t num){
    if(num < 0){
      str[0] = '-';
      LET_uint_to_decimal_string(str+1, (uint64_t) - num);
    }else{
      LET_uint_to_decimal_string(str, (uint64_t) num);
    }
}


int8_t LET_compare_str(const char * a, const char * b){
  while( ( *a != '\0' && *b != '\0' ) && *a == *b ){
    a++;
    b++;
  }
  return *a - *b;
}


void LET_array_convert(char dest[], const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace){
  uint32_t i = 0;
  uint16_t position = 0;
  uint64_t buffer = 0;
  for (; i<size/whitespace; i++){
    buffer = LET_str_to_uint64(src+(i*whitespace), whitespace);
    position +=  LET_convert_uint_to_base(dest+position, buffer, format, whitespace);
    dest[position++]=' ';
  }
  for(uint8_t j = 0; j < size%whitespace; j++){
    buffer = LET_str_to_uint64(src+j+(i*whitespace), LET_BYTE);
    position += LET_convert_uint_to_base(dest+position, buffer, format, LET_BYTE);
  }
  dest[position-((size%whitespace)?0:1)]='\0';
}



void LET_uint_to_decimal_printer(uint64_t num){
  char data[] = "\0";
  uint64_t  n = 1u;

  while (n <= num/10u){
    n *= 10u;
  }
  for (; n > 0; n/=10){
    data[0] = LET_CHAR_HEXADECIMAL[(num/n)%10];
    LET_Framework_printer(data);
  }
}
void LET_int_printer(int64_t num){
    if(num < 0){
      LET_Framework_printer("-");
      LET_uint_to_decimal_printer((uint64_t) - num);
    }else{
      LET_uint_to_decimal_printer((uint64_t) num);
    }
}


void LET_convert_uint_to_base_printer(uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  char data[] = "\0";
  uint8_t i;
  uint8_t mask_format = (uint8_t) (LET_BINARY == format)? LET_MASK_BINARY : (LET_OCTAL == format)? LET_MASK_OCTAL : LET_MASK_HEXADECIMAL;
  uint8_t bit_number = (uint8_t) (LET_BINARY == format)? LET_BIT_NUMBER_BINARY : (LET_OCTAL == format)? LET_BIT_NUMBER_OCTAL : LET_BIT_NUMBER_HEXADECIMAL;
  uint8_t character_number = (uint8_t) (((LET_OCTAL == format)?2:0) +(bytes*8))/bit_number;
  for(i=0; i < character_number; i++){
    data[0] = LET_CHAR_HEXADECIMAL[(num>>((character_number-i-1)*bit_number))&mask_format];
    LET_Framework_printer(data);
  }
}


void LET_uint_to_base_printer(uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  char data[] = "0\0";
  data[1] = (LET_BINARY == format)? LET_BEGIN_BINARY : (LET_OCTAL == format)? LET_BEGIN_OCTAL : LET_BEGIN_HEXADECIMAL;
  LET_Framework_printer(data);
  LET_convert_uint_to_base_printer(num, format, bytes);
}


void LET_array_printer(const char *const src, uint32_t size, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION whitespace){
  uint32_t i = 0;
  uint64_t buffer = 0;
  for (; i<size/whitespace; i++){
    buffer = LET_str_to_uint64(src+(i*whitespace), whitespace);
    LET_convert_uint_to_base_printer(buffer, format, whitespace);
    LET_Framework_printer(" ");
  }
  for(uint8_t j = 0; j < size%whitespace; j++){
    buffer = LET_str_to_uint64(src+j+(i*whitespace), LET_BYTE);
    LET_convert_uint_to_base_printer(buffer, format, LET_BYTE);
  }
}