CC = g++
LIBS = -lm -pg
SRC = src
OBJ = obj
INC = include
BIN = bin
OBJS = $(OBJ)/main.o $(OBJ)/ord.o $(OBJ)/random.o
HDRS = $(INC)/ord.hpp $(INC)/random.hpp
CFLAGS = -Wall 

EXE = $(BIN)/tp0.out

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) -o $(EXE) $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC) $(CFLAGS) -o $@ $(SRC)/main.cpp

$(OBJ)/ord.o: $(HDRS) $(SRC)/ord.cpp
	$(CC) $(CFLAGS) -o $@ $(SRC)/ord.cpp

$(OBJ)/random.o: $(HDRS) $(SRC)/random.cpp
	$(CC) $(CFLAGS) -o $@ $(SRC)/random.cpp

clean:
	rm -f $(EXE) $(OBJS)