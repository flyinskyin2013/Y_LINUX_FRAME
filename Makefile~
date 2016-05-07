##############################
# file:   Makefile
# author:  sky
# modified-date:  2016-05-07
###############################

export ROOT_DIR := $(shell pwd)  
#get out of start and end char' ' of the string
ROOT_DIR :=$(strip ${ROOT_DIR})


export LIB_DIR:=$(ROOT_DIR)/lib
export SRC_DIR:=$(ROOT_DIR)/src
export INCLUDE_DIR:=$(ROOT_DIR)/include


export TARGET:=test


export CC:=gcc
export	LD_FLAGS:=-l config -pthread

export SRC:=$(wildcard ${SRC_DIR}/*.c)
export OBJ:=$(patsubst %.c,%.o,${SRC})
 
export OBJ_S:=Y_Start.o Y_ChildProcess.o 

#if you want to build release-program , use command: make BUILD_RELEASE=TRUE
ifeq ($(BUILD_RELEASE), TRUE)
export	C_FLAGS:= -I ${INCLUDE_DIR} -std=c99 
export BUILD_DIR := $(ROOT_DIR)/release  
else
export	C_FLAGS:= -g -D Y_DEBUG -I ${INCLUDE_DIR} -std=c99  
export BUILD_DIR := $(ROOT_DIR)/debug
endif

export OLD_OBJ:=$(wildcard ${BUILD_DIR}/*.o)



.PHONY :default all clean 

default:all 

all :
	@${MAKE} -C src all

clean: 
	@${MAKE} -C src clean



