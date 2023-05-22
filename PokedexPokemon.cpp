#include "PokedexPokemon.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

PokedexPokemon::PokedexPokemon(){

}
PokedexPokemon::PokedexPokemon(vector<vector<string>> _data, int _width, int _height, int pokemonPos){
    database = _data;
    font.loadFromFile("PKMN RBYGSC.ttf");
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));
    for (int i = 0; i < 70; i=i+2){
        entriesInfo[i].setString(database[pokemonPos][0]);
        entriesInfo[i].setFillColor(sf::Color::Black);
        entriesInfo[i].setFont(font);
        entriesInfo[i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f)));

        entriesInfo[i+1].setString(database[pokemonPos][i]);
        entriesInfo[i+1].setFillColor(sf::Color::Black);
        entriesInfo[i+1].setFont(font);
        entriesInfo[i+1].setPosition(sf::Vector2f(width+ 15.0f, height+(60.0f)));
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
