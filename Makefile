
APPNAME:=$(shell basename `pwd`)

ifeq ($(OS),LIN)
    LDFLAGS:=-L ../raylib/src
else
    LDFLAGS:=-L H:\raylib\include
endif
LDFLAGS+=-lm -lraylib -pthread
ifeq ($(OS),LIN)
    LDFLAGS+= -lX11 -ldl
else
    LDFLAGS+= -lopengl32 -lgdi32 -lwinmm -mwindows
endif

CFLAGS:= -g -Wfatal-errors -pedantic -Wall -Wextra -Werror -std=c++11 -I ./include
ifeq ($(OS),LIN)
    CFLAGS+= -I ../raylib/src
else
    CFLAGS+= -I H:\raylib
endif
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
