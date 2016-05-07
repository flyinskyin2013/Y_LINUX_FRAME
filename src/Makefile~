.PHONY:all clean  

all:${TARGET}
	@${CC}  ${OBJ} -o ${TARGET} ${LD_FLAGS}
	@mv ${TARGET} ${BUILD_DIR}
	@mv ${OBJ} ${BUILD_DIR}
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

${TARGET}:
	@${CC} ${C_FLAGS} -c ${SRC}



#clean target
clean:
	@rm  ${OLD_OBJ} ${BUILD_DIR}/${TARGET}

