CC = g++
LIBS = -lm
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/geo.o $(OBJ)/main.o 
HDRS = $(INC)/geo.hpp
CFLAGS = -I$(INC) -c -std=c++17

EXE = $(BIN)/tp1.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp

$(OBJ)/geo.o: $(HDRS) $(SRC)/geo.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/geo.o $(SRC)/geo.cpp

clean:
	rm -f $(EXE) $(OBJS) ./bin/gmon.out ./bin/tp1.exe