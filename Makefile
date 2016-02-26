CC:=gcc
CFLAG:=-D Y_DEBUG -I include/
OBJ:=Y_Start.o Y_ChildProcess.o Y_Stdio.o

test:${OBJ}
	@${CC} ${CFLAG} ${OBJ} -o test
Y_Start.o:src/Y_Start.c
	@${CC} ${CFLAG} -c src/Y_Start.c
Y_ChildProcess.o:src/Y_ChildProcess.c
	@${CC} ${CFLAG} -c src/Y_ChildProcess.c
Y_Stdio.o:src/Y_Stdio.c
	@${CC} ${CFLAG} -c src/Y_Stdio.c
.PHONY : clean
clean:
	@rm Y_Start.o Y_ChildProcess.o Y_Stdio.o test


