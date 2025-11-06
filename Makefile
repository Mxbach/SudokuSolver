# Makefile

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

all: build
	./$(BIN_DIR)/solver

build: 
	mkdir -p $(BIN_DIR)
	g++ -o $(BIN_DIR)/solver $(SRC_DIR)/sudokuSolver.cpp

clean:
	rm -rf $(BIN_DIR)
	rm -rf $(OBJ_DIR)

.PHONY: all build clean