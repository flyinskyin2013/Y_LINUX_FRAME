/*
*	FileName:Y_Macro.h
*	Version: 1.2	
*	Description: The file defines my favorite macroes.
*	Created On:2016-2-16
*	Modified date:2016-2-22
*	Author:Sky
*
*/
#ifndef _Y_MACRO_H
#define _Y_MACRO_H

#include <string.h>
#include <stdlib.h>
#include "Y_Stdio.h"

#define PROGRAM_ERROR 0x00
#define PROGRAM_END 0x01


#define ERROR_MSG(where,what) do{ \
	char * addr; \
	addr = malloc(sizeof(char)*128); \
	Y_PRINTF("%s",strcat(strcat(strcat(strcat(addr,where )," is error, The error is "),(what) ),"\n")); \
	free(addr); \
	} while(0)
	

#define SHOW_MSG(what) do{ \
	char * addr; \
	addr = malloc(sizeof(char)*128); \
	Y_PRINTF("%s",strcat(strcat(addr,(what) ),"\n")); \
	free(addr); \
	} while(0)


#endif//_Y_MACRO_H
