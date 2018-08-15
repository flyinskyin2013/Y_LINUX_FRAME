# Y_LINUX_FRAME
	A Muti-Processes and Muti-Threads Frame based on linux.

#How to use 
	firstly,you should modified bellow files to sure how many threads you want.default,there are two threads

	include/userthreads.h
		you should add your thread-declare
	include/Y_ChildProcess.h
		modified macro ThreadTotalNum to set num of threads you want.
	src/userthreads.c
		you should add your thread-implement
	src/Y_ChildProcess.c
		modified ThreadTable[] to add macro createThread(num,threadname,runstatus).

	now,

	make

# The lastest status
On 2018-8-15,This project from college merges to project-yLib(https://github.com/flyinskyin2013/yLib)
