/*******************************************************************************
 ** File Name : LET_Framework_Result.h
 ** Author : Raphaël KUMAR
 ** Github : github.com/madkira/LET_Framework
 ** Created : 30 October 2020
 ** Version : 0.0.1
*******************************************************************************/
#ifndef D_UTIL_FORMAT_H_
#define D_UTIL_FORMAT_H_
// +-------------------------------------------+
// | LET_Framework_Result Includes             |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Types                |
// +-------------------------------------------+
/*Not Used*/

// +-------------------------------------------+
// | LET_Framework_Result Structures           |
// +-------------------------------------------+

// +-------------------------------------------+
// | LET_Framework_Result Macros               |
// +-------------------------------------------+
#define BALISE_SERVICE "SERVICE"
#define BALISE_TEST "TEST"
#define BALISE_ASSERT "ASSERT"
#define BALISE_ANNOTATION "NOTE"
#define BALISE_ERROR "ERROR"


// +-------------------------------------------+
// | LET_Framework_Result Variables            |
// +-------------------------------------------+
/*Not Used*/


// +-------------------------------------------+
// | LET_Framework_Result Functions Definition |
// +-------------------------------------------+
void uint_to_string(char str[], uint64_t num);
void int_to_string(char str[], int64_t num);


#endif //D_UTIL_FORMAT_H_
