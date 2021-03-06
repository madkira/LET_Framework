/*******************************************************************************
 ** File Name : LET_util_xml_format.c
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/

// +---------------------------------------------------+
// | LET_util_xml_format includes                      |
// +---------------------------------------------------+
#include <stdint.h>

#include "LET_Framework.h"
#include "LET_util_format_string.h"
#include "LET_util_xml_format.h"

// +---------------------------------------------------+
// | LET_util_xml_format macros                        |
// +---------------------------------------------------+
/*Not Used*/

// +---------------------------------------------------+
// | LET_util_xml_format types                         |
// +---------------------------------------------------+
/*Not Used*/

// +---------------------------------------------------+
// | LET_util_xml_format variables                     |
// +---------------------------------------------------+
/*Not Used*/

// +---------------------------------------------------+
// | LET_util_xml_format extern functions              |
// +---------------------------------------------------+
extern void LET_Framework_printer(const char * data);

// +---------------------------------------------------+
// | LET_util_xml_format private functions declaration |
// +---------------------------------------------------+
void LET_xml_open_balise(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close){
  if(new_line) LET_Framework_printer("\n");
  for(uint8_t i = 0; i<tabulation; i++){
    LET_Framework_printer("\t");
  }
  LET_Framework_printer("<");
  if(close) LET_Framework_printer("/");
  LET_Framework_printer(balise_name);
}

void LET_xml_close_balise(uint8_t standalone){
  if(standalone) LET_Framework_printer("/");
  LET_Framework_printer(">");
}

void LET_xml_add_str_parameter(const char *parameter_name, const char* value){
  LET_Framework_printer(" ");
  LET_Framework_printer(parameter_name);
  LET_Framework_printer("=\"");
  LET_Framework_printer(value);
  LET_Framework_printer("\"");
}

void LET_xml_add_uint_parameter(const char *parameter_name, uint64_t num, LET_ASSERT_REPRESENT format, LET_ASSERT_PRECISION bytes){
  LET_Framework_printer(" ");
  LET_Framework_printer(parameter_name);
  LET_Framework_printer("=\"");
  if(LET_DECIMAL ==  format){
    LET_uint_to_decimal_printer(num);
  }else{
    LET_uint_to_base_printer(num, format, bytes);
  }
  LET_Framework_printer("\"");
}

void LET_xml_add_int_parameter(const char *parameter_name, int64_t num){
  LET_Framework_printer(" ");
  LET_Framework_printer(parameter_name);
  LET_Framework_printer("=\"");
  LET_int_printer(num);
  LET_Framework_printer("\"");
}
