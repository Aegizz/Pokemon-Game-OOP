#include "PokedexPokemon.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <iostream>
PokedexPokemon::PokedexPokemon(){
    //Default constructor
}
PokedexPokemon::PokedexPokemon(vector<vector<string>> _data, int _width, int _height){
    // Constructor that initializes the PokedexPokemon object with database, position, and position

    //Init variables
    width = _width;
    height = _height - 125;
    database = _data;
    display = false;
    page = 1;
    //Load the fonts and menuBox and menuBox texture
    font.loadFromFile("PKMN RBYGSC.ttf");
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    //set the scale to default
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));
    menuBox.setPosition(width, height);
    // Populate the entriesInfo array with the name of each data element from the database, skipping each so the data can be added in after 
    for (int i = 0; i < 35; i++){
        entriesInfo[2*i].setString(database[0][i]);
        //Init font, colour and position
        entriesInfo[2*i].setFillColor(sf::Color::Black);
        entriesInfo[2*i].setFont(font);
        entriesInfo[2*i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f)));
    }
    this->entry(0);
}
void PokedexPokemon::draw(sf::RenderWindow &window){
    // Draw the Pokedex on the specified window, showing the specified page
    if (display){
        //Draw menuBox
        window.draw(menuBox);
        for (int i = page; i < page + 2; i=i+2){
            //Draw each entry that fits on the page
            window.draw(entriesInfo[i]);
            window.draw(entriesInfo[i+1]);
            
        }
    }

}
void PokedexPokemon::entry(int pokemonPos){
    //Init the data for a given pokemon entry e.g. Charizard based upon its number in the pokedex
    for (int i = 0; i < 35; i++){
        //Make sure the array elements do no go over the allocated space
        if (2*i + 1 < 70){
            //Set the data stored in the element of the text array from the databse
            entriesInfo[(2*i+1)].setString(database[pokemonPos+1][i]);
            //Set the colour, font and position of the data
            entriesInfo[(2*i+1)].setFillColor(sf::Color::Black);
            entriesInfo[(2*i+1)].setFont(font);
            entriesInfo[(2*i+1)].setPosition(sf::Vector2f(width+ 15.0f, height+(60.0f)));
        }
    }
}
void PokedexPokemon::setDisplay(bool _display){
    display = _display;
}
void PokedexPokemon::toggleDisplay(){
    display ^= true;
}
bool PokedexPokemon::getDisplay(){
    return display;
}
void PokedexPokemon::moveUp(){
    if (page - 1 > -1){
        page--;
    }
}
void PokedexPokemon::moveDown(){
    if (page + 1 <  69){
        page++;
    }

}