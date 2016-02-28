
/*
*	FileName:Y_Stdarg.h
*	Version: 1.0
*	Description: The file defines two macroes about y_va-
*		_list,y_va_start,y_va_end,y_va_arg
*	Created On:2016-2-25
*	Modified date:
*	Author:Sky
*
*/

#ifndef _Y_STDARG_H
#define _Y_STDARG_H


#ifdef Y_TEST_VA

typedef char * y_va_list;

/*
*	Storage alignment properties
*/

//The size of int is 4 bytes (32bits)
#define Y_AUPBND (sizeof (int) - 1) 

#define Y_ADNBND (sizeof (int) - 1) 

/*
*	Variable argument list macro definitions
*/

#define y_bnd(X, bnd) (((sizeof (X)) + (bnd)) & (~(bnd))) //memory align
#define y_va_start(ap,A) (void) ( (ap) = ( ((y_va_list)&(A)) + (y_bnd(A,Y_AUPBND)) ) )//Making ap point at &A + 4
#define y_va_arg(ap,T) (*(T *)( ( (ap) += (y_bnd(T,Y_AUPBND)) ) - (y_bnd(T,Y_AUPBND)) ))//get value of ap,and ap + 4
#define y_va_end(ap)  ( (ap) = (y_va_list)0 ) 


#else


typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list y_va_list;

#define y_va_start(ap,A) __builtin_va_start(ap,A)
#define y_va_arg(ap,T) __builtin_va_arg(ap,T)
#define y_va_end(ap)  __builtin_va_end(ap)

    

#endif //Y_TEST_VA







#endif //_Y_STDARG_H
