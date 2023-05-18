compile: main.cpp pokemon.cpp pokemonDatabase.cpp Menu.cpp
	g++ -c main.cpp pokemon.cpp pokemonDatabase.cpp Menu.cpp
	g++ main.o pokemonDatabase.o pokemon.o Menu.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app