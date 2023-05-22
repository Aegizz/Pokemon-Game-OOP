#include "PokedexPokemon.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

PokedexPokemon::PokedexPokemon(){

}
PokedexPokemon::PokedexPokemon(vector<vector<string>> _data, int _width, int _height, int pokemonPos){
    width = _width;
    height = _height;
    database = _data;
    font.loadFromFile("PKMN RBYGSC.ttf");
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));
    for (int i = 0; i < 35; i++){
        entriesInfo[2*i].setString(database[0][i]);
        entriesInfo[2*i].setFillColor(sf::Color::Black);
        entriesInfo[2*i].setFont(font);
        entriesInfo[2*i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f)));
    }
}
void PokedexPokemon::draw(sf::RenderWindow &window, int page){
    window.draw(menuBox);
    selectedItemIndex = page + 1;
    for (int i = page; i < page + 2; i=i+2){
        window.draw(entriesInfo[i]);
        window.draw(entriesInfo[i+1]);
        
    }

}
void PokedexPokemon::Entry(int pokemonPos){
    for (int i = 0; i < 35; i++){
        if (2*i + 1 < 70){
            entriesInfo[(2*i+1)].setString(database[pokemonPos+1][i]);
            entriesInfo[(2*i+1)].setFillColor(sf::Color::Black);
            entriesInfo[(2*i+1)].setFont(font);
            entriesInfo[(2*i+1)].setPosition(sf::Vector2f(width+ 15.0f, height+(60.0f)));
        }
    }
}
