CC:=gcc
CFLAG:=-D Y_DEBUG
OBJ:=Y_Start.o Y_ChildProcess.o

test:${OBJ}
	@${CC} ${CFLAG} ${OBJ} -o test
Y_Start.o:Y_Start.c
	@${CC} ${CFLAG} -c Y_Start.c
Y_ChildProcess.o:Y_ChildProcess.c
	@${CC} ${CFLAG} -c Y_ChildProcess.c
.PHONY : clean
clean:
	@rm Y_Start.o Y_ChildProcess.o test


