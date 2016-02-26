/*
*	FileName:Y_Stdio.h
*	Version: 1.2	
*	Description: The file defines two macroes about st-
*		andard input and output datas.
*	Created On:2015-9-10
*	Modified date:2016-2-26
*	Author:Sky
*
*/
#ifndef _Y_STDIO_H
#define _Y_STDIO_H

#include "stdlib.h"
#include "string.h"
#include "Y_Stdarg.h"

extern int y_printf(const char * fmt, ...);

#define Y_PRINTF(Fromat,...) \
            y_printf(Fromat,##__VA_ARGS__)

#define Y_SCANF(Fromat,...) \
            scanf(Fromat,##__VA_ARGS__)



#endif //_YSTDIO_H
