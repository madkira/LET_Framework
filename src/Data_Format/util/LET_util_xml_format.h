/*******************************************************************************
 ** File Name : LET_util_xml_format.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_UTIL_XML_FORMAT_H_
#define D_UTIL_XML_FORMAT_H_
// +-------------------------------------------+
// | LET_util_xml_format Includes              |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_xml_format Types                 |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_xml_format Structures            |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_xml_format Macros                |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_xml_format Variables             |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_xml_format Functions Definition  |
// +-------------------------------------------+
void open_balise(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close);
void close_balise(uint8_t standalone);
void add_parameter(const char *parameter_name, const char* value);
#endif //D_UTIL_XML_FORMAT_H_
