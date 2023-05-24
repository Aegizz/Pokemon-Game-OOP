#include "Pokedex.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


Pokedex::Pokedex(){
    //Default constructor
};

Pokedex::Pokedex(vector<vector<string>> _data, int _width, int _height){
    //Init the width and height
    width = _width;
    height = _height;
    //Set the stagger to off first
    stagger = 0;
    //Add the all the pokemon names to the array data from the database
    for (int i = 0; i < 152; i++){
        data.insert(data.end(),_data[i][1]);
    }
    //Loop through and init each pokemon's name in the array to either a bottom position or top position also set the colour, font
    for (int i = 1; i < 151; i = i +2 ){
        pokedexEntries[i].setString(data[i]);
        pokedexEntries[i].setFillColor(sf::Color::Black);
        pokedexEntries[i].setFont(font);
        pokedexEntries[i].setPosition(sf::Vector2f(width + 15.0f, height+(30.0f)));
    
        pokedexEntries[i+1].setString(data[i+1]);
        pokedexEntries[i+1].setFillColor(sf::Color::Black);
        pokedexEntries[i+1].setFont(font);
        pokedexEntries[i+1].setPosition(sf::Vector2f(width+ 15.0f, height+60.0f));
        
    }

    //Init the text box and the font
    font.loadFromFile("PKMN RBYGSC.ttf");
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    //Set the scale to default
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));

}
void Pokedex::PositionChange(){
    //Function position change to switch the top and bottom items in the array when moving through the list
    stagger ^= true;
    for (int i = 1; i < 151; i = i+2){
        //change position of elements in this order depending on the state of the stagger
        pokedexEntries[i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f  + (30.0f * stagger))));
        pokedexEntries[i+1].setPosition(sf::Vector2f(width+ 15.0f, height+60.0f - (30.0f * stagger)));
    }
}

void Pokedex::draw(sf::RenderWindow &window, int page){
    //Draw the menu box
    window.draw(menuBox);
    for (int i = page; i < page + 2; i=i+2){
        //Set the current selected item to yellow
        pokedexEntries[i].setFillColor(sf::Color::Yellow);
        //Set the selected item index
        selectedItemIndex = i - 1;
        //Draw the selected item and the one below it
        window.draw(pokedexEntries[i]);
        window.draw(pokedexEntries[i+1]);
    }
}

void Pokedex::setPosition(int _width, int _height){
    //Set the width and height variables to the new ones
    width = _width;
    height = _height;
    //Set the position of the menuBox
    menuBox.setPosition(width, height);
    //Change the position of each item in the text array dependant on the stagger
    for (int i = 1; i < 151; i = i+2){
        pokedexEntries[i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f  + (30.0f * stagger))));
        pokedexEntries[i+1].setPosition(sf::Vector2f(width+ 15.0f, height+60.0f - (30.0f * stagger)));
    }
};
