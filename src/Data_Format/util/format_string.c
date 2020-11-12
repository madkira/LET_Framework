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
#include "stdint.h"
#include <stdio.h>
#include "format_string.h"
#include "LET_Framework_Result.h"

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
const char *ASSERT_COMPARE_STRING[] = {
  FOREACH_COMPARE(GENERATE_STRING)
};

const char *ASSERT_TYPE_STRING[] = {
  FOREACH_TYPE(GENERATE_STRING)
};

const char *ASSERT_RESULT_STRING[] = {
  FOREACH_RESULT(GENERATE_STRING)
};

#define CHAR_HEXADECIMAL "0123456789ABCDEF"
#define BEGIN_HEXADECIMAL 'x'
#define BEGIN_OCTAL 'c'
#define BEGIN_BINARY 'b'

#define MASK_HEXADECIMAL 0x0F
#define MASK_OCTAL 0x07
#define MASK_BINARY 0x01

#define BIT_NUMBER_HEXADECIMAL 4u
#define BIT_NUMBER_OCTAL 3u
#define BIT_NUMBER_BINARY 1u

// +----------------------------------------------------+
// | LET_Framework_Result extern functions definition   |
// +----------------------------------------------------+
/*Not Used*/


// +----------------------------------------------------+
// | LET_Framework_Result private functions definition  |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result private functions declaration |
// +----------------------------------------------------+
/*Not Used*/

// +----------------------------------------------------+
// | LET_Framework_Result public functions declaration  |
// +----------------------------------------------------+
void uint_to_decimal_string(char str[], uint64_t num){
  uint64_t i, rem, len = 0, n = num;

  do{
    len++;
    n /= 10;
  }while (n != 0);

  for (i = 0; i < len; i++){
    rem = num % 10;
    num = num / 10;
    str[len - (i + 1)] = rem + '0';
  }

  str[len] = '\0';
}

uint8_t convert_uint_to_base(char str[], uint64_t num, ASSERT_REPRESENT format, ASSERT_PRECISION bytes){
  uint8_t i;
  uint8_t mask_format = (BINARY == format)? MASK_BINARY : (OCTAL == format)? MASK_OCTAL : MASK_HEXADECIMAL;
  uint8_t bit_number = (BINARY == format)? BIT_NUMBER_BINARY : (OCTAL == format)? BIT_NUMBER_OCTAL : BIT_NUMBER_HEXADECIMAL;
  uint8_t character_number = (((OCTAL == format)?2:0) +(bytes*8))/bit_number;
  for(i=0; i < character_number; i++){
    str[i] = CHAR_HEXADECIMAL[(num>>((character_number-i-1)*bit_number))&mask_format];
  }
  return i;
}

void uint_to_base_string(char str[], uint64_t num, ASSERT_REPRESENT format, ASSERT_PRECISION bytes){
  uint8_t i;
  str[0] = '0';
  str[1] = (BINARY == format)? BEGIN_BINARY : (OCTAL == format)? BEGIN_OCTAL : BEGIN_HEXADECIMAL;
  i = convert_uint_to_base(str+2, num, format, bytes);
  str[2+i] = '\0';
}


void int_to_string(char str[], int64_t num){
    if(num < 0){
      str[0] = '-';
      uint_to_decimal_string(str+1, (uint64_t) - num);
    }else{
      uint_to_decimal_string(str, (uint64_t) num);
    }
}



uint8_t compare_str(char *a, char *b){
  while( ( *a != '\0' && *b != '\0' ) && *a == *b ){
    a++;
    b++;
  }
  return *a - *b;
}

uint16_t str_size(char *a){
  uint16_t size = 0;
  for(; a[size] != '\0'; size++);
  return size;
}

uint64_t str_to_uint64(char*a, ASSERT_PRECISION whitespace){
  uint64_t result = 0;
  for(uint8_t i=0; i < whitespace; i++ ){
    result = result<<8 | a[i];
  }
  return result;
}

void str_convert(char dest[], char *src, ASSERT_REPRESENT format, ASSERT_PRECISION whitespace){
  uint16_t i = 0;
  uint16_t position = 0;
  uint64_t buffer = 0;
  uint16_t size = str_size(src);
  for (; i<size/whitespace; i++){
    buffer = str_to_uint64(src+(i*whitespace), whitespace);
    position +=  convert_uint_to_base(dest+position, buffer, format, whitespace);
    dest[position++]=' ';
  }
  for(uint16_t j = 0; j < size%whitespace; j++){
    buffer = str_to_uint64(src+j+(i*whitespace), BYTE);
    position += convert_uint_to_base(dest+position, buffer, format, BYTE);
  }
  dest[position]='\0';
}