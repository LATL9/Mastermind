
APPNAME:=$(shell basename `pwd`)

LDFLAGS:=-L ../raylib/src -lm -lraylib -lX11 -ldl -pthread

CFLAGS:= -g -Wfatal-errors -pedantic -Wall -Wextra -Werror
CFLAGS+= -std=c++11 -I ./include -I ../raylib/src

SRC:=$(wildcard src/*.cpp)
OBJ:=$(SRC:src/%.cpp=obj/%.o)
INC:=$(wildcard include/*.h)

CC=g++

$(APPNAME): $(OBJ)
	$(CC) $(OBJ) -o $(APPNAME) $(LDFLAGS)

$(OBJ): obj/%.o : src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: debug release
debug: CFLAGS+= -g
release: CFLAGS+= -O3

debug release: clean $(APPNAME)

.PHONY:	clean
clean:
	rm obj/* -f
	rm $(APPNAME) -f

style: $(SRC) $(INC)
	astyle -A10 -s4 -S -p -xg -j -z2 -n src/* include/*
