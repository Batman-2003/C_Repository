CC := gcc
RM := rm
BUILD_DIR := build
SRC_DIR := src
C_FLAGS := -Wno-pointer-arith -Wall --pedantic -fsanitize=address  
C_FLAGS_DEBUG := -ggdb



build: 
	${CC} ${C_FLAGS} ${SRC_DIR}/main.c -o ${BUILD_DIR}/app

run:
	${BUILD_DIR}/app

build-run:
	${CC} ${C_FLAGS} ${SRC_DIR}/main.c -o ${BUILD_DIR}/app
	${BUILD_DIR}/app

debug-build-run:
	${CC} ${C_FLAGS} ${C_FLAGS_DEBUG} ${SRC_DIR}/main.c -o ${BUILD_DIR}/app
	${BUILD_DIR}/app


clean:
	${RM} -r ${BUILD_DIR}
	mkdir build
