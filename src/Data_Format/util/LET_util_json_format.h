/*******************************************************************************
 ** File Name : LET_util_json_format.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_UTIL_JSON_FORMAT_H_
#define D_UTIL_JSON_FORMAT_H_
// +-------------------------------------------+
// | LET_util_json_format Includes             |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_json_format Types                |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_json_format Structures           |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_json_format Macros               |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_json_format Variables            |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_util_json_format Functions Definition |
// +-------------------------------------------+
void LET_json_open_object(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close);
void LET_json_close_object(uint8_t standalone);

void LET_json_open_array(char *balise_name, uint8_t new_line, uint8_t tabulation, uint8_t close);
void LET_json_close_array(uint8_t standalone);

void LET_add_parameter(const char *parameter_name, const char* value);
#endif //D_UTIL_JSON_FORMAT_H_
