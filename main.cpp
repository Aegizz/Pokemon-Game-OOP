#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include <unistd.h>
#include "Pokedex.h"
#include "PokedexPokemon.h"

using namespace std;
extern vector<vector<string>> pokemonDatabase();

int main(){
    // Load the Pokemon database
    vector<vector<string>> database = pokemonDatabase();

    // Boolean flags to control drawing of menu, Pokedex, and Pokedex entry
    bool drawMenu = false;
    bool drawPokedex = false;
    bool drawPokedexEntry = false;

    int pagePokedex = 1;
    int pagePokedexEntry = 0;

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Music music;

    // Load and play background music
    if (!music.openFromFile("pokemon_title_screen.ogg")){
        return -1; // Error occurred while loading music
    }
    music.play();

    // Create instances of Menu, Pokedex, and PokedexPokemon
    Menu menu(404, 250);
    Pokedex Pokedex(database, 0, 450);
    PokedexPokemon pokedexEntry(database, 0, 450, 2);
    //Clock for accidental multiple inputs
    sf::Clock clock;
    // Run the program as long as the window is open

    while (window.isOpen()){
        // Check if 'M' key is pressed to toggle the menu
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawMenu ^= true; // Toggle the drawMenu flag
                clock.restart();
            }
        }
        // Check if Enter key is pressed and the menu is drawn and check pokedex is selected
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawMenu) && (menu.getItemIndex() == 0)){
            drawPokedex ^= true; // Toggle the drawPokedex flag
            drawMenu ^= true; // Toggle the drawMenu flag
        }

        // Check if Enter key is pressed and the Pokedex is drawn and set the entry to the selected pokemon
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawPokedex){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawPokedex ^= true; // Toggle the drawPokedex flag
                drawPokedexEntry ^= true; // Toggle the drawPokedexEntry flag
                pokedexEntry.entry(Pokedex.getItemIndex()); // Update the Pokedex entry based on selected Pokemon
                Pokedex.setItemIndex(1); // Reset the selected item index in the Pokedex
            }
        }

        // Check if Escape key is pressed to reset flags and pages
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            drawPokedex = false;
            drawMenu = false;
            drawPokedexEntry = false;
            pagePokedex = 1;
            pagePokedexEntry = 1;
        }

        // Handle window events
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            if (drawMenu == true){
                                menu.moveUp(); // Move the selection up in the menu if up arrow is pressed
                            }
                            if((pagePokedex -1 > 0/*Check it doesnt exit the array*/) && drawPokedex){
                                Pokedex.PositionChange(); //Change the positions of text placement
                                pagePokedex--;// Move the selection up in the pokedex if up arrow is pressed
                            }
                            if ((pagePokedexEntry -2 > 0/*Check it doesnt exit the array*/) && drawPokedexEntry){
                                pagePokedexEntry = pagePokedexEntry -2;
                                //Change the page of the pokedex entry
                            }
                            break;
                        case sf::Keyboard::Down:
                            if (drawMenu == true){
                                menu.moveDown();// Move the selection down in the menu if down arrow is pressed
                            }
                            if ((pagePokedex + 1 < (151)/*Check it doesnt exit the array*/) && drawPokedex){
                                Pokedex.PositionChange();//Change position of the elements
                                pagePokedex++; //Change the page of the pokedex
                            }
                            if ((pagePokedexEntry + 1 < 68 /*Check it doesnt exit the array*/) && drawPokedexEntry){
                                //Change the page of the pokedex entry
                                pagePokedexEntry = pagePokedexEntry+2;
                            }
                            break;
                        default: //default do nothing to fix warnings
                            break;
                        }
                    break;
                case sf::Event::Closed:
                //if the event window closed, close the window
                    window.close();
                    break;
                default:
                //default to fix warnings
                    break;
            }
        }

        // clear the window with white color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
        // if flag is true, draw window
        if (drawMenu){
            menu.setPosition(0, 450);
            menu.draw(window);
        }
        if (drawPokedex){
            Pokedex.setPosition(0,450);
            Pokedex.draw(window, pagePokedex);
        }
        if (drawPokedexEntry){
            pokedexEntry.setPosition(0,450);
            pokedexEntry.draw(window, pagePokedexEntry);
        }
        //display window
        window.display();
    }

   
    return 0;
}
