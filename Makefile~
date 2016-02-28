CC:=gcc
CFLAG:=-D Y_DEBUG -I include/
OBJ:=Y_Start.o Y_ChildProcess.o Y_Stdio.o
OBJ_S:=Y_Start.o Y_ChildProcess.o 


test:${OBJ}
	@${CC} ${CFLAG} ${OBJ} -o test

test_static:${OBJ}
	@${CC} ${CFLAG} ${OBJ_S} -o test_static -static -L./lib/ -l Y_Stdio
test_share:${OBJ}
	@${CC} ${CFLAG} ${OBJ_S} -o test_share -L./lib/ -l Y_Stdio
libY_Stdio_Static:
	@${CC} ${CFLAG} -c src/Y_Stdio.c
	@ar -rcs libY_Stdio.a Y_Stdio.o
	@mv libY_Stdio.a ./lib
libY_Stdio_Shared:
	@${CC} ${CFLAG} -fPIC -c src/Y_Stdio.c
	@${CC} -shared -fPIC -o libY_Stdio.so Y_Stdio.o
	@mv libY_Stdio.so ./lib
Y_Start.o:src/Y_Start.c
	@${CC} ${CFLAG} -c src/Y_Start.c
Y_ChildProcess.o:src/Y_ChildProcess.c
	@${CC} ${CFLAG} -c src/Y_ChildProcess.c
Y_Stdio.o:src/Y_Stdio.c
	@${CC} ${CFLAG} -c src/Y_Stdio.c
.PHONY : clean
clean:
	@rm Y_Start.o Y_ChildProcess.o Y_Stdio.o test


