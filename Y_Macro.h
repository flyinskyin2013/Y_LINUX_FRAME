/*
*	FileName:Y_Macro.c
*	Version: 1.0	
*	Description: The file defines my favorite macroes.
*	Created On:2016-2-16
*	Modified date:
*	Author:Sky
*
*/
#ifndef _Y_MACRO_H
#define _Y_MACRO_H

#include <string.h>
#include "Y_Stdio.h"

#define PROGRAM_ERROR 0x00
#define PROGRAM_END 0x01


#define GET_ERROR_MSG_DEALED(where,what)({ \
		char msg[128]; \
		strcat(strcat(strcat(strcat(msg,where)," is error, The error is "),what),"\n"); \
	})
#define ERROR_MSG(where,what) \
	Y_PRINTF(GET_ERROR_MSG_DEALED(where,what)) \

#define GET_SHOW_MSG_DEALED(what)({ \
		char msg[128]; \
		strcat(strcat(msg,what),"\n"); \
	})
#define SHOW_MSG(what) \
	Y_PRINTF(GET_SHOW_MSG_DEALED(what))

#endif//_Y_MACRO_H
