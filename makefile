compile: OOP_game.cpp 
	g++ -Wall -c OOP_game.cpp attack.cpp Pokemon.cpp player.cpp
	g++ OOP_game.o attack.o Pokemon.o player.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app
clean:
	rm -f *.o
	rm -f *.exe
