/*
*	FileName:list_test.c
*	Version: 1.0
*	Description: The file test my list if it is right
*	Created On:2016-5-15
*	Modified date:
*	Author:Sky
*
*/
#include <stdio.h>
#include "Y_List/Y_List.h"

typedef struct {
	int a;
	Y_LISTHEAD list;
} test;

test* ptr_test;

int main(int argc, char * argv[]){
	
	//test head;

	LIST_HEAD(test_list);
	Y_LISTHEAD * pos;
	test * entry;
	
	//INIT_LIST_HEAD(head->list);
	
	
	ptr_test = (test *)malloc(sizeof(test));
	ptr_test->a = 0;
	
	LIST_ADD(&ptr_test->list,&test_list);

	ptr_test = (test *)malloc(sizeof(test));
	ptr_test->a = 2;
	
	LIST_ADD_TAIL(&ptr_test->list,&test_list);

	ptr_test = (test *)malloc(sizeof(test));
	ptr_test->a = 4;
	
	LIST_ADD(&ptr_test->list,&test_list);

	ptr_test = (test *)malloc(sizeof(test));
	ptr_test->a = 8;
	
	LIST_ADD_TAIL(&ptr_test->list,&test_list);


	LIST_FOR_EACH(pos,&test_list){
		
		entry = GET_ENTRY(pos,test,list);	
		printf("%d\n",entry->a);
	}


	LIST_DEL_ENTRY(&(ptr_test->list));


	LIST_FOR_EACH(pos,&test_list){
		
		entry = GET_ENTRY(pos,test,list);	
		printf("%d\n",entry->a);
	}

	
	LIST_FOR_EACH(pos,&test_list){
		
		entry = GET_ENTRY(pos,test,list);
		free(entry);
	}


	return 0;
}
