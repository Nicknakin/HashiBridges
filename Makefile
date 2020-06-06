CXX=clang++
CXXFLAGS=-std=c++17 -Wall -I include/
LDLIBS=
SRC_DIR=./src
OBJ_DIR=./obj
TEST_DIR=./tests
TEST_OUT_DIR=./tests/bin
BUILD_DIR=./build

BRACKET_STYLE=java

OUTPUT=HashiBridges

SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
TEST_FILES := $(wildcard $(TEST_DIR)/*.cpp)

OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))
TEST_OUT := $(patsubst $(TEST_DIR)/%.cpp,$(TEST_DIR)/bin/%.test,$(TEST_FILES))

.PHONY: default objs test preprocess debug docgen clean prettify objprepender web

default: ${OBJ_FILES}
	${CXX} ${CXXFLAGS} $^ -o ${BUILD_DIR}/${OUTPUT}_Client ${LDLIBS} 

web: CXX=emcc
web: CXXFLAGS+= -s WASM=1
web: ${OBJ_FILES}
	${CXX} ${CXXFLAGS} $^ -o ${OUTPUT}.html ${LDLIBS}

objs: objprepender ${OBJ_FILES}

test: ${TEST_OUT}	

preprocess: CXXFLAGS+=-E
preprocess: default

debug: CXXFLAGS+=-g 
debug: clean default 

docgen:
	@doxygen
	@firefox ./docs/html/index.html

${TEST_OUT_DIR}/%.test: ${OBJ_FILES} ${TEST_DIR}/%.cpp 
	$(CXX) ${CXXFLAGS} $^ -o $@ ${LDLIBS}
	$@

${OBJ_DIR}/%.o: ${SRC_DIR}/%.cpp 
	$(CXX) ${CXXFLAGS} -c -o $@ $<

objprepender:
	@echo -e  "==============================================\n==============MAKING=OBJ_FILES================\n=============================================="

prettify:
	find -type f \( -iname \*.h -o -iname \*.hpp -o -iname \*.cpp \) -exec astyle -n --style=${BRACKET_STYLE} {} \; | grep ^Formatted*

clean:
	-rm -rf ${BUILD_DIR}/*
	-rm -rf ${OBJ_DIR}/*.o
	-rm -rf ${OBJ_DIR}/*/*.o
	-rm -rf ${TEST_DIR}/*.test

