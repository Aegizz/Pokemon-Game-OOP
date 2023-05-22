#include "Pokedex.h"
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
using namespace std;


Pokedex::Pokedex(){

};

Pokedex::Pokedex(vector<vector<string>> _data, int _width, int _height){
    width = _width;
    height = _height;
    stagger = 0;
    for (int i = 0; i < 152; i++){
        data.insert(data.end(),_data[i][1]);
    }
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


    font.loadFromFile("PKMN RBYGSC.ttf");
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));

}
void Pokedex::PositionChange(){
    stagger ^= true;
    for (int i = 1; i < 151; i = i+2){
        pokedexEntries[i].setString(data[i]);
        pokedexEntries[i].setFillColor(sf::Color::Black);
        pokedexEntries[i].setFont(font);
        pokedexEntries[i].setPosition(sf::Vector2f(width+ 15.0f, height+(30.0f  + (30.0f * stagger))));

        pokedexEntries[i+1].setString(data[i+1]);
        pokedexEntries[i+1].setFillColor(sf::Color::Black);
        pokedexEntries[i+1].setFont(font);
        pokedexEntries[i+1].setPosition(sf::Vector2f(width+ 15.0f, height+60.0f - (30.0f * stagger)));
        selectedItemIndex=i;

    }
}

void Pokedex::draw(sf::RenderWindow &window, int page){
    window.draw(menuBox);
    for (int i = page; i < page + 2; i=i+2){
        pokedexEntries[i].setFillColor(sf::Color::Yellow);
        window.draw(pokedexEntries[i]);
        window.draw(pokedexEntries[i+1]);
    }
}

