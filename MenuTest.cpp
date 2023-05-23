#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    bool drawMenu = false; // Flag to determine whether to draw the menu

    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test"); // Create the window
    
    Menu menu(0,0); // Create an instance of the Menu class
    sf::Clock clock; // Clock for timing

    while (window.isOpen()){
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            // Toggle the drawMenu flag if 'M' key is pressed
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                //Check the key has not been pressed recently
                //Toggle the boolean
                drawMenu ^= true;
                //Restart clock
                clock.restart();
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            // Turn off the drawMenu flag if 'Escape' key is pressed
            drawMenu = false;
        }

        sf::Event event;
        //Init event
        while (window.pollEvent(event)){
            //Poll event
            switch(event.type){
                //Switch case for if key released
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            if (drawMenu == true){
                                // Move the menu selection up and print the item index to confirm the position is correct
                                cout <<"Item Index = "<<menu.getItemIndex();
                                menu.moveUp();
                                cout << "Item Index = "<<menu.getItemIndex();
                            }
                            break;
                        case sf::Keyboard::Down:
                            if (drawMenu == true){
                                // Move the menu selection down and print the item index to confirm position is correct
                                cout <<"Item Index = "<<menu.getItemIndex();
                                menu.moveDown();
                                cout << "Item Index = "<<menu.getItemIndex();
                            }
                            break;
                        //Default do nothing (removes warnings in code)
                        default:
                            break;
                    }
                //Default is do nothing (removes warning in code)
                default:
                    break;
            }
        }

        window.clear(sf::Color::White);

        if (drawMenu){
            // Print and set the menu position to test if it was changed correctly, then draw the menu
            cout << "Current Pos = "<< menu.getPosition()[0];
            cout << "Current Pos = " <<menu.getPosition()[1];

            menu.setPosition(0, 450);
            cout <<"Current Pos = " << menu.getPosition()[0];
            cout <<"Current Pos = " << menu.getPosition()[1];

            menu.draw(window);
        }

        window.display();
    }

    return 0;
}