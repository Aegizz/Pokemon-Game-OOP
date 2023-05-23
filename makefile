compile: main.cpp pokemonDatabase.cpp Menu.cpp Pokedex.cpp PokedexPokemon.cpp
	g++ -Wall -c main.cpp pokemonDatabase.cpp Menu.cpp Pokedex.cpp PokedexPokemon.cpp
	g++ main.o pokemonDatabase.o Menu.o Pokedex.o PokedexPokemon.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app