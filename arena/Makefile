CC := g++
RM := rm
BUILD_DIR := build
SRC_DIR := src
C_FLAGS := -Wno-pointer-arith



build: 
	${CC} ${C_FLAGS} ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/app.exe

run:
	${BUILD_DIR}\app.exe

build-run:
	${CC} ${C_FLAGS} ${SRC_DIR}/main.cpp -o ${BUILD_DIR}/app.exe
	${BUILD_DIR}\app.exe



clean:
	${RM} -r ${BUILD_DIR}
	mkdir build
