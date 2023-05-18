compile: OOP_game.cpp
	g++ -c OOP_game.cpp
	g++ OOP_game.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app