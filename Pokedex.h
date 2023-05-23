#include "Menu.h"
#ifndef POKEDEX_H
#define POKEDEX_H
#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Pokedex : public Menu{
    protected:
        vector<string> data;
        sf::Text pokedexEntries[152];
        bool stagger;
    public:
        Pokedex();
        Pokedex(vector<vector<string>> data, int width, int height);
        void draw(sf::RenderWindow &window, int page);
        void PositionChange();
        void setPosition(int width, int height);



};
#endif