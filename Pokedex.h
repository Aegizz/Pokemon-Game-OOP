#include "Menu.h"
#ifndef POKEDEX_H
#define POKEDEX_H

#include <vector>
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;

class Pokedex : public Menu{
    protected:
        vector<string> data; // Vector to store the Pokedex data
        sf::Text pokedexEntries[152]; // Array of Text objects to display Pokedex entries
        bool stagger; // Flag to determine the staggered display of Pokedex entries when moving through the array
        bool display;
        int page;
    public:
        Pokedex(); // Default constructor
        Pokedex(vector<vector<string>> data, int width, int height); // Constructor that takes Pokedex data, width, and height
        void draw(sf::RenderWindow &window); // Method to draw the Pokedex entries on the window for a specific page
        void PositionChange(); // Method to change the position of the Pokedex entries when moving through the list
        void setPosition(int width, int height); // Method to set the position of the Pokedex
        bool getDisplay();
        void setDisplay(bool _display);
        void toggleDisplay();
        void moveDown();
        void moveUp();
        int getPage();
};

#endif
