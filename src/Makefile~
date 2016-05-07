.PHONY:all clean  

all:${OBJ}
	@${CC} ${C_FLAGS} ${OBJ} -o ${TARGET}
	@mv ${TARGET} ${BUILD_DIR}
	@mv $^ ${BUILD_DIR}
#this is to make test from a static-lib
test_static:${OBJ}
	@${CC} ${C_FLAGS} ${OBJ_S} -o test_static -static -L ${LIB_DIR} -l Y_Stdio

#this is to make test from a shared-lib
test_share:${OBJ}
	@${CC} ${C_FLAGS} ${OBJ_S} -o test_share -L ${LIB_DIR} -l Y_Stdio

#this is to make a static-lib
libY_Stdio_Static:
	@${CC} ${C_FLAGS} -c Y_Stdio.c
	@ar -rcs libY_Stdio.a Y_Stdio.o
	@mv libY_Stdio.a ${LIB_DIR}
#this is to make a shared-lib
libY_Stdio_Shared:
	@${CC} ${C_FLAGS} -fPIC -c Y_Stdio.c
	@${CC} -shared -fPIC -o libY_Stdio.so Y_Stdio.o
	@mv libY_Stdio.so ${LIB_DIR}

Y_Stdio.o:Y_Stdio.c
	@${CC} ${C_FLAGS} -c $<

Y_Start.o:Y_Start.c
	@${CC} ${C_FLAGS} -c $<

Y_ChildProcess.o:Y_ChildProcess.c
	@${CC} ${C_FLAGS} -c $<

userthreads.o:userthreads.c
	@${CC} ${C_FLAGS} -c $<


#clean target
clean:
	@rm Y_Start.o Y_ChildProcess.o Y_Stdio.o userthreads.o test

