#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    bool drawMenu = false;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test");
    Menu menu(0,0);
    sf::Clock clock;
    while (window.isOpen()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawMenu ^= true;
                clock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            drawMenu = false;
        }
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            if (drawMenu == true){
                                cout <<"Item Index = "<<menu.getItemIndex();
                                menu.moveUp();
                                cout << "Item Index = "<<menu.getItemIndex();

                            }
                            break;
                        case sf::Keyboard::Down:
                            if (drawMenu == true){
                                cout <<"Item Index = "<<menu.getItemIndex();
                                menu.moveDown();
                                cout << "Item Index = "<<menu.getItemIndex();
                            }
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }

        window.clear(sf::Color::White);
        if (drawMenu){
            cout << "Current Pos = "<< menu.getPosition()[0];
            cout << "Current Pos" <<menu.getPosition()[1];

            menu.setPosition(0, 450);
            cout <<"Current Pos = " << menu.getPosition()[0];
            cout <<"Current Pos = " << menu.getPosition()[1];

            menu.draw(window);
        }
        window.display();
    }
    return 0;
}