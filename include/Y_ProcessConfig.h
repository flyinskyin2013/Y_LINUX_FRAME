#ifndef _Y_PROCESSCONFIG_H
#define _Y_PROCESSCONFIG_H

#include "Y_Macro.h"
#include "string.h"
#include <stdlib.h>
#include <stdio.h>

// This header file  come from libconfig
#include <libconfig.h>


//I will define something to conveniently use *.conf file using libconfig

typedef struct 
{
	const char * confdir;
   	char  confPath[100];
}  Y_ProConf;

typedef struct {
    //your code here
    //This is example
    int test1;
    char test2[100];
} ConfValue;

//add your code 
//this code is an example
#define CONFIG_LOOKUP(cfg,DesStruct) do{\
          config_lookup_int(&cfg, "test.test1", &DesStruct->test1);\
	  memset(DesStruct->test2,'0',100);\
	  char *tmp;\
          config_lookup_string(&cfg, "test.test2", &tmp);\
	  strcpy(DesStruct->test2,tmp);\
          }while(0)

#define CONFIG_SETTING(setting,srcStruct) do{\
          config_setting_t *t1;\
          t1=config_setting_get_member(setting,"test1");\
          config_setting_set_int(t1, srcStruct->test1);\
          config_setting_t *t2;\
          t2 = config_setting_get_member(setting,"test2");\
          config_setting_set_string(t2,srcStruct->test2);\
          }while(0)
void Y_ProConfInit(const char * confdir);

void Y_ProConfRead(ConfValue *DesStruct);

void Y_ProConfWrite(const ConfValue * srcStruct);

#endif //_Y_PROCESSCONFIG_H

