appname = TicTacToe
files = $(shell find ./src -name '*.cpp')
compiler = gcc
flags = -std=c++11 -lstdc++

all: $(files)
	$(compiler) $(flags) -o $(appname) $(files)