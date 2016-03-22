#include "Y_ProcessConfig.h"
#include "string.h"

int main(int argc, char *argv[]){
	
	ConfValue test,tmp;
	Y_ProConfInit(".");
	test.test1=100;
	strcpy(test.test2,"nimabi");
	//test.test2="nimabi"
	Y_ProConfWrite(&test);

	Y_ProConfRead(&tmp);
	printf("%d   %s \n",tmp.test1,tmp.test2);
	return 0;
}
