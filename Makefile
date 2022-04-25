all: compile link

compile:
	g++ -I src/include -I src/Headers -c src/main.cpp src/board.cpp src/AI.cpp src/Game.cpp src/button.cpp
link:
	g++ -o main.exe main.o board.o ai.o game.o button.o -L src/lib -l sfml-graphics -l sfml-window -l sfml-system -l sfml-audio