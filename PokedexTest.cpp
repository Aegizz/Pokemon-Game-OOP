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

    // Load the Pokemon database
    vector<vector<string>> database = pokemonDatabase();

    // Boolean flags to control drawing of menu and Pokedex
    bool drawMenu = false;
    bool drawPokedex = false;

    int pagePokedex = 1;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Menu Test");

    // Create an instance of Menu
    Menu menu(0, 0);
    //Set clock for checking time since opened
    sf::Clock clock;

    // Create an instance of Pokedex
    Pokedex Pokedex(database, 0, 0);

    while (window.isOpen()){

        // Check if 'M' key is pressed to toggle the menu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawMenu ^= true; // Toggle the drawMenu flag
                clock.restart(); //Reset clock
            }
        }

        // Check if Escape key is pressed to hide the menu and Pokedex
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            drawMenu = false;
            drawPokedex = false;
        }

        // Check if Enter key is pressed and the menu is drawn
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawMenu) && (menu.getItemIndex() == 0)){
            drawPokedex ^= true; // Toggle the drawPokedex flag
            drawMenu ^= true; // Toggle the drawMenu flag
        }

        // Handle window events
        sf::Event event;
        while (window.pollEvent(event)){
            switch(event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            if (drawMenu == true){
                                menu.moveUp(); // Move the selection up in the menu
                            }
                            if((pagePokedex -1 > 0) && drawPokedex){
                                cout << Pokedex.getItemIndex();//Testing before
                                Pokedex.PositionChange(); // Adjust the position of the items in the Pokedex
                                pagePokedex--; //Change page
                                cout << Pokedex.getItemIndex(); //Testing change

                            }
                            break;
                        case sf::Keyboard::Down:
                            if (drawMenu == true){
                                menu.moveDown(); // Move the selection down in the menu
                            }
                            if ((pagePokedex + 1 < (151)) && drawPokedex){
                                cout << Pokedex.getItemIndex(); //Testing before
                                Pokedex.PositionChange(); // Adjust the positions of items in the Pokedex
                                pagePokedex++; //Change page
                                cout << Pokedex.getItemIndex(); //Testing after changes

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

        // Draw the menu if the flag is set
        if (drawMenu){
            menu.setPosition(0, 450);
            menu.draw(window);
        }

        // Draw the Pokedex if the flag is set
        if (drawPokedex){
            //Output the current position to test the change
            cout << "Current Pos = "<< Pokedex.getPosition()[0];
            cout << "Current Pos" <<Pokedex.getPosition()[1];
            Pokedex.setPosition(0,450);
            cout << "Current Pos = "<< Pokedex.getPosition()[0];
            cout << "Current Pos = " <<Pokedex.getPosition()[1];
            //Draw the pokedex dependant on the page
            Pokedex.draw(window, pagePokedex);

        }
        //Display the window
        window.display();
    }
    return 0;
}