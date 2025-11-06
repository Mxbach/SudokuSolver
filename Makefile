# Makefile

SRC_DIR=src
OBJ_DIR=obj
BIN_DIR=bin

all: build
	./$(BIN_DIR)/solver

build: 
	g++ -o $(BIN_DIR)/solver $(SRC_DIR)/sudokuSolver.cpp

clean:
	rm $(BIN_DIR)/*
	rm -rf $(OBJ_DIR)/*

.PHONY: build clean