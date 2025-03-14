all: compile link


compile: 
	g++ main.cpp -c main.o
	g++ src/CrackCode.cpp -c CrackCode.o

link:
	g++ main.o CrackCode.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-audio -lsfml-system

start:
	./sfml-app