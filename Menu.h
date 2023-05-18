#ifndef MENU_H
#define MENU_H
#include "SFML/Graphics.hpp"


#define NUMBER_OF_MENU_ITEMS 2
class Menu{
    private:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menuItems[NUMBER_OF_MENU_ITEMS];

    public:
        Menu(float width, float height);
        Menu();

        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();

};

#endif