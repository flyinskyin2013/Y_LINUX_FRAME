#include "userthreads.h"
#include "Y_Macro.h"

void * thread1(const void * arg){
	void * a;
#ifdef Y_DEBUG
	SHOW_MSG("This is Thread1.\n");
#endif //Y_DEBUG
	return a;
}

void * thread2(const void * arg){
	void * a;
#ifdef Y_DEBUG
	SHOW_MSG("This is Thread2.\n");
#endif //Y_DEBUG
	return a;
}
