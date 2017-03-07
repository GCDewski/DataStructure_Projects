CC = g++

all: zuul

zuul: Command.o CommandWords.o Parser.o Room.o Game.o main.o
	$(CC) Command.o CommandWords.o Parser.o Room.o Game.o main.o -o zuul

.cpp.o:
	$(CC) -c $< -o $@
