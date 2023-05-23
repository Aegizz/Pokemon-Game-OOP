#ifndef MENU_H
#define MENU_H

#include "SFML/Graphics.hpp"
using namespace std;

class Menu {
    protected:
        int selectedItemIndex; // Index of the currently selected menu item
        sf::Font font; // Font used for the menu text
        int arraySize; // Size of the menuItems array
        sf::Text menuItems[2]; // Array of menu item texts
        int width; // Width of the menu
        int height; // Height of the menu
        sf::Sprite menuBox; // Sprite for the menu background box
        sf::Texture menuBoxTex; // Texture for the menu background box

    public:
        Menu(float width, float height); // Constructor that takes width and height
        Menu(); // Default constructor

        void draw(sf::RenderWindow &window); // Method to draw the menu on a window
        void moveUp(); // Method to move the selection up
        void moveDown(); // Method to move the selection down
        void setPosition(int width, int height); // Method to set the position of the menu
        vector<int> getPosition(); // Method to get the position of the menu
        int getItemIndex(); // Method to get the index of the currently selected item
        void setItemIndex(int index); // Method to set the index of the currently selected item

};

#endif
