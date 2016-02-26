/*
*	FileName:ChildProcess.c
*	Version: 1.0	
*	Description: The file defines the body of ChildProcess() 
*	Created On:2016-2-16
*	Modified date:
*	Author:Sky
*
*/
#include "Y_ChildProcess.h"

void * Y_ChildProcess(const void * arg){

	void * retval;

	//
	//Your code here.
	//

#ifdef Y_DEBUG
	SHOW_MSG("This is ChildProcess.");
#endif //Y_DEBUG
	
	//retval can be any type of point,only force-convertting to void *
	return retval;
}
