#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Pokedex.h"
using namespace std;

extern vector<vector<string>> pokemonDatabase(); 

int main(){

    vector<vector<string>> database = pokemonDatabase();

    bool drawMenu = false;
    bool drawPokedex = false;

    int pagePokedex = 1;

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test");

    Menu menu(0,0);

    sf::Clock clock;

    Pokedex Pokedex(database, 0, 0);


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


        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawMenu) && (menu.getItemIndex() == 0)){
            drawPokedex ^= true;
            drawMenu ^= true;
        }

        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            if (drawMenu == true){
                                menu.moveUp();
                            }
                            if((pagePokedex -1 > 0) && drawPokedex){
                                cout << Pokedex.getItemIndex();
                                Pokedex.PositionChange();
                                pagePokedex--;
                                cout << Pokedex.getItemIndex();

                            }
                            break;
                        case sf::Keyboard::Down:
                            if (drawMenu == true){
                                menu.moveDown();
                            }
                            if ((pagePokedex + 1 < (151)) && drawPokedex){
                                cout << Pokedex.getItemIndex();
                                Pokedex.PositionChange();
                                pagePokedex++;
                                cout << Pokedex.getItemIndex();

                            }
                            break;
                        default:
                            break;
                    }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
            }
        }

        window.clear(sf::Color::White);

        if (drawMenu){
            menu.setPosition(0, 450);
            menu.draw(window);
        }

        if (drawPokedex){
            cout << "Current Pos = "<< Pokedex.getPosition()[0];
            cout << "Current Pos" <<Pokedex.getPosition()[1];
            Pokedex.setPosition(0,450);
            cout << "Current Pos = "<< Pokedex.getPosition()[0];
            cout << "Current Pos = " <<Pokedex.getPosition()[1];
            Pokedex.draw(window, pagePokedex);

        }
        window.display();
    }
    return 0;
}