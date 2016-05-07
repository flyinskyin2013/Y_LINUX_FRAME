/*
*	FileName:ChildProcess.h
*	Version: 1.1	
*	Description: The file defines a declaration of ChildProcess()
*	Created On:2016-5-7
*	Modified date:
*	Author:Sky
*
*/
#ifndef _Y_CHILDPROCESS_H
#define _Y_CHILDPROCESS_H

#include "Y_Macro.h"
#include "yThread.h"
#include "userthreads.h"

#define ThreadTotalNum 2

typedef struct
{
	int threadnum;
	pthread_t th_id;
	//void * retval;
	void * (*threadname)(const void * arg);
	//0-------stop
	//1-------run
	void * arg;
	unsigned char runstatus;
	
}Ys_Thread;



extern  Ys_Thread ThreadTable[];
extern void * Y_ChildProcess(const void * arg);
#endif //_Y_CHILDPROCESS_H
