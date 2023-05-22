#ifndef POKEDEXPOKEMON_H
#define POKEDEXPOKEMON_H
#include "Pokedex.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
class PokedexPokemon: public Pokedex{
    private:
        vector<vector<string>> database;
        sf::Text entriesInfo[70];
        
    public:
        PokedexPokemon();
        PokedexPokemon(vector<vector<string>> database, int width, int height, int selectedItem);
        void draw(sf::RenderWindow &window, int page);
};

#endif