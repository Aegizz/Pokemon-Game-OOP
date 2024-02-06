#include "Menu.h"
#include <vector>
using namespace std;
Menu::Menu(){

}
Menu::Menu(float _width, float _height){
    menuBoxTex.loadFromFile("pokemonSprites/text.png");
    menuBox.setTexture(menuBoxTex);
    if (!font.loadFromFile("PKMN RBYGSC.ttf"))
    {
        //handle error
    }
    width = _width;
    height = _height;
    menuBox.setScale(sf::Vector2f(1.0f, 1.0f));
    menuItems[0].setFont(font);
    menuItems[0].setFillColor(sf::Color::Black);
    menuItems[0].setString("Pokedex");
    menuItems[0].setPosition(sf::Vector2f(width/2, height/(NUMBER_OF_MENU_ITEMS)));

    menuItems[1].setFont(font);
    menuItems[1].setFillColor(sf::Color::Yellow);
    menuItems[1].setString("Map");
    menuItems[1].setPosition(sf::Vector2f(width/2, height/(NUMBER_OF_MENU_ITEMS*2)));

    selectedItemIndex = 1;
}

void Menu::draw(sf::RenderWindow &window){

    window.draw(menuBox);

    for (int i =0; i < NUMBER_OF_MENU_ITEMS; i++){
        window.draw(menuItems[i]);
    }
}
void Menu::moveDown(){
    if  (selectedItemIndex +1 < NUMBER_OF_MENU_ITEMS){
            menuItems[selectedItemIndex].setFillColor(sf::Color::Black);
            selectedItemIndex++;
            menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}
void Menu::moveUp(){
    if (selectedItemIndex -1 >= 0){
        menuItems[selectedItemIndex].setFillColor(sf::Color::Black);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setFillColor(sf::Color::Yellow);
    }
}
void Menu::setPosition(int _width, int _height){
    width = _width;
    height = _height;
    menuBox.setPosition(sf::Vector2f((float)_width, (float)_height));
    for (int i = 0; i < NUMBER_OF_MENU_ITEMS; i++){
        menuItems[i].setPosition(sf::Vector2f((float)_width +50.0f, (float)_height+(30.0f)*(i+1)));
    }
}
vector<int> Menu::getPosition(){
    vector<int> positions;
    positions.insert(positions.begin(), width);
    positions.insert(positions.end(), height);
    return positions;
}