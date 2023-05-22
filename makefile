compile: main.cpp pokemon.cpp pokemonDatabase.cpp Menu.cpp Pokedex.cpp PokedexPokemon.cpp
	g++ -Wall -c main.cpp pokemon.cpp pokemonDatabase.cpp Menu.cpp Pokedex.cpp PokedexPokemon.cpp
	g++ main.o pokemonDatabase.o pokemon.o Menu.o Pokedex.o PokedexPokemon.o -o app -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
run:
	./app