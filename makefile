compile: main.cpp pokemon.cpp pokemonDatabase.cpp
	g++ -c main.cpp pokemon.cpp pokemonDatabase.cpp
	g++ main.o pokemonDatabase.o pokemon.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app