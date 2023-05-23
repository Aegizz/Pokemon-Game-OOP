#ifndef POKEDEXPOKEMON_H
#define POKEDEXPOKEMON_H
#include "Pokedex.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

class PokedexPokemon: public Pokedex{
    private:
        vector<vector<string>> database; //Database storage
        sf::Text entriesInfo[72]; // Array to store Pokedex entries information
        
    public:
        PokedexPokemon(); //Default constructor
        PokedexPokemon(vector<vector<string>> database, int width, int height, int selectedItem); //Constructor that takes database, height, width and the pokemon to display the data of
        void draw(sf::RenderWindow &window, int page); //Function to draw the pokedex entry depedant on the page of the pokedex information to be viewed
        void entry(int pokemonPos); //define/redfine the pokemon/entry to be viewed when calling draw
};

#endif
