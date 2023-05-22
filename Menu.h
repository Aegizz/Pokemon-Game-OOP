#ifndef MENU_H
#define MENU_H
#include "SFML/Graphics.hpp"
using namespace std;

#define NUMBER_OF_MENU_ITEMS 2
class Menu{
    protected:
        int selectedItemIndex;
        sf::Font font;
        sf::Text menuItems[NUMBER_OF_MENU_ITEMS];
        int width;
        int height;
        sf::Sprite menuBox;
        sf::Texture menuBoxTex;
    public:
        Menu(float width, float height);
        Menu();

        void draw(sf::RenderWindow &window);
        void moveUp();
        void moveDown();
        void setPosition(int width, int height);
        vector<int> getPosition();
        int getItemIndex();

};

#endif