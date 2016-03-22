#include "Y_ProcessConfig.h"

Y_ProConf InitVal;

void Y_ProConfInit(const char * confdir){
	
	InitVal.confdir = confdir;
	strcat(InitVal.confPath, InitVal.confdir);
	strcat(InitVal.confPath,"/config.conf");   
}

void Y_ProConfRead(ConfValue * DesStruct){
   
    config_t cfg;
	config_setting_t * setting, *root, * group;

    config_init(&cfg);
    /* Read the file. If there is an error, report it and exit. */
    if(! config_read_file(&cfg, InitVal.confPath))
    {
#ifdef Y_DEBUG
    printf("%s \n", InitVal.confPath);
#endif
     fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
     config_error_line(&cfg), config_error_text(&cfg));
     config_destroy(&cfg);
     exit(EXIT_FAILURE);
    }
    //config_lookup_int();
    //config_lookup_string();
	setting = config_lookup(&cfg,"test");
    CONFIG_LOOKUP(cfg,DesStruct);        
    config_destroy(&cfg); 
}

void Y_ProConfWrite(const ConfValue * srcStruct){

    config_t cfg;
    config_setting_t * setting, *root, * group;

    config_init(&cfg);
      /* Read the file. If there is an error, report it and exit. */
    if(! config_read_file(&cfg, InitVal.confPath))
    {
#ifdef Y_DEBUG
    printf("%s \n", InitVal.confPath);
#endif
          fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
          config_error_line(&cfg), config_error_text(&cfg));
          config_destroy(&cfg);
          return(EXIT_FAILURE);
    }
#ifdef Y_DEBUG
    printf("%s \n", InitVal.confPath);
#endif
    setting = config_lookup(&cfg,"test");
    CONFIG_SETTING(setting,srcStruct);
    /* Write out the updated configuration. */
	if(! config_write_file(&cfg, InitVal.confPath))
	{
    		fprintf(stderr, "Error while writing file.\n");
    		config_destroy(&cfg);
    		exit(EXIT_FAILURE);
  	}
    config_destroy(&cfg);
}
