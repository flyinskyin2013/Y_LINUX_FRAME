#!/bin/bash

#start to build c-program basic structure.

#init default value
FILE_CONTENT=
FILE_NAME=main
FILE_TYPE=.c
BACKUP_FILE_TYPE="$FILE_TYPE"".bak"



#define init fuction
function backup_file()
{
	#The first way is failed,because it can not save text format
	#FILE_CONTENT=$(cat $FILE_NAME$FILE_TYPE) 
	cat $FILE_NAME$FILE_TYPE > $FILE_NAME$BACKUP_FILE_TYPE
}
function clean_file()
{
	echo "" > $FILE_NAME$FILE_TYPE
}
function make_comment()
{
	NowTime=`date`
	echo "/*">> $FILE_NAME$FILE_TYPE
	echo "	FileName:"$FILE_NAME$FILE_TYPE >> $FILE_NAME$FILE_TYPE
	echo "	Version:" >> $FILE_NAME$FILE_TYPE
	echo "	Description:" >> $FILE_NAME$FILE_TYPE
	echo "	Created On:"$NowTime >> $FILE_NAME$FILE_TYPE
	echo "	Modified date:" >> $FILE_NAME$FILE_TYPE
	echo "	Author:" >> $FILE_NAME$FILE_TYPE
	echo "*/">> $FILE_NAME$FILE_TYPE
}
function start_wirte()
{
	cat $FILE_NAME$BACKUP_FILE_TYPE >> $FILE_NAME$FILE_TYPE
	rm $FILE_NAME$BACKUP_FILE_TYPE
}
function completed_wirte()
{
	echo "Wirte success"
}



#check num of argument.
if [ $# -ge 1 ];
then
	echo "Now,starting ......"
else
	echo "error num,Useage: ./init.sh [filename] [...]"
	exit 1
fi

#check arg $1 
if [ -n "$1" ];
then
	FILE_NAME=$1
else
	echo "error arg,Useage: ./init.sh [filename] [...]"
	exit 1
fi

backup_file;
clean_file;
make_comment;
start_wirte;
completed_wirte;
