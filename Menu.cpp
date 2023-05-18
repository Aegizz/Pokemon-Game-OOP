#include "Menu.h"


Menu::Menu(){

}
Menu::Menu(float width, float height){
    if (!font.loadFromFile("PKMN RBYGSC.ttf"))
    {
        //handle error
    }
    menuItems[0].setFont(font);
    menuItems[0].setColor(sf::Color::Yellow);
    menuItems[0].setString("Pokedex");
    menuItems[0].setPosition(sf::Vector2f(width/2, height/(NUMBER_OF_MENU_ITEMS)));

    menuItems[1].setFont(font);
    menuItems[1].setColor(sf::Color::Black);
    menuItems[1].setString("Map");
    menuItems[1].setPosition(sf::Vector2f(width/2, height/(NUMBER_OF_MENU_ITEMS*2)));

    selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow &window){
    for (int i =0; i < NUMBER_OF_MENU_ITEMS; i++){
        window.draw(menuItems[i]);
    }
}
void Menu::moveDown(){
    if  (selectedItemIndex +1 < NUMBER_OF_MENU_ITEMS){
            menuItems[selectedItemIndex].setColor(sf::Color::White);
            selectedItemIndex++;
            menuItems[selectedItemIndex].setColor(sf::Color::Yellow);
    }
}
void Menu::moveUp(){
    if (selectedItemIndex -1 >= 0){
        menuItems[selectedItemIndex].setColor(sf::Color::White);
        selectedItemIndex--;
        menuItems[selectedItemIndex].setColor(sf::Color::Yellow);
    }
}