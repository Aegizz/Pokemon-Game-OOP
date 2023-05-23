#include "Menu.h"
#include <vector>
using namespace std;
Menu::Menu(){
    //Default constructor
}
Menu::Menu(float _width, float _height){
    // Constructor that takes width and height as parameters
    //Load texture from file
    //Set texture to menubox item
    menuBoxTex.loadFromFile("pokemon/text.png");
    menuBox.setTexture(menuBoxTex);
    //Init array size
    arraySize = 2;
    if (!font.loadFromFile("PKMN RBYGSC.ttf"))
    {
        // Handle error if font loading fails
    }
    //Init height and width
    width = _width;
    height = _height;
    //Set the scaling of the menu
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));

    // Initialize the first menu item
    menuItems[0].setFont(font);
    menuItems[0].setFillColor(sf::Color::Yellow);
    menuItems[0].setString("Pokedex");
    menuItems[0].setPosition(sf::Vector2f(width, height/(arraySize)));

    // Initialize the second menu item
    menuItems[1].setFont(font);
    menuItems[1].setFillColor(sf::Color::Black);
    menuItems[1].setString("Map");
    menuItems[1].setPosition(sf::Vector2f(width, height/(arraySize*2)));

    selectedItemIndex = 0; // Set the initial selected item index
}

void Menu::draw(sf::RenderWindow &window){
    // Draw the menu box
    window.draw(menuBox);
    // Draw all the menu items
    for (int i =0; i < arraySize; i++){
        window.draw(menuItems[i]);
    }
}
void Menu::moveDown(){
    // Move the selection down
    //Check array bounds
    if  (selectedItemIndex +1 < arraySize){
        //Change text colour
        menuItems[selectedItemIndex].setFillColor(sf::Color::Black);
        //Iterate array pos
        selectedItemIndex++;
        //Change text colour
        menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}
void Menu::moveUp(){
    // Move the selection up
    //Check array bounds
    if (selectedItemIndex -1 >= 0){
        // Set the current item's color to black
        menuItems[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        // Set the new selected item's color to yellow
        menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}
void Menu::setPosition(int _width, int _height){
    // Set the position of the menu
    //Change the width and height value
    width = _width;
    height = _height;
    //set the position of the menu box using SFML's function
    menuBox.setPosition(sf::Vector2f((float)_width, (float)_height));
    for (int i = 0; i < arraySize; i++){
        //Set the position of array elements using SFML's function
        menuItems[i].setPosition(sf::Vector2f((float)_width + 50.0f, (float)_height + (30.0f) * (i + 1)));
    }
}
vector<int> Menu::getPosition(){
    // Get the position of the menu
    //Init vector to hold positions
    vector<int> positions;
    //Insert the positions using vector functions
    positions.insert(positions.begin(), width);
    positions.insert(positions.end(), height);
    //Return the vector
    return positions;
}
int Menu::getItemIndex(){
    // Get the index of the currently selected item
    return selectedItemIndex;
}

void Menu::setItemIndex(int index){
    // Set the index of the currently selected item
    selectedItemIndex = index;
}