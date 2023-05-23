#ifndef MENU_H
#define MENU_H
#include "SFML/Graphics.hpp"
using namespace std;

class Menu{
    protected:
        int selectedItemIndex;
        sf::Font font;
        int arraySize;
        sf::Text menuItems[2];
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
        void setItemIndex(int index);

};

#endif