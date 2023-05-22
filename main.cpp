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
    vector<vector<string>> database = pokemonDatabase();
    bool drawMenu = false;
    bool drawPokedex = false;
    bool drawPokedexEntry = false;
    int pagePokedex = 1;
    int pagePokedexEntry = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Music music;

    if (!music.openFromFile("pokemon_title_screen.ogg")){
        return -1; // error
    }
    music.play();

    Menu menu(404, 250);
    Pokedex Pokedex(database,0,450);
    PokedexPokemon pokedexEntry(database, 0, 450, 2);


    // run the program as long as the window is open
    sf::Clock clock;

    while (window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawMenu ^= true;
                clock.restart();
            }
        }
        if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawMenu) && (menu.getItemIndex() == 0)){
            drawPokedex ^= true;
            drawMenu ^= true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && drawPokedex){
            if ((int)((clock.getElapsedTime()).asSeconds()) > 1){
                drawPokedex ^= true;
                drawPokedexEntry ^= true;
                pokedexEntry.Entry(Pokedex.getItemIndex());
                Pokedex.setItemIndex(1);
            }
        }
 
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            drawPokedex = false;
            drawMenu = false;
            drawPokedexEntry = false;
            pagePokedex = 1;
            pagePokedexEntry = 1;
        }


        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {   
            switch (event.type){
                case sf::Event::KeyReleased:
                    switch (event.key.code){
                        case sf::Keyboard::Up:
                            menu.moveUp();
                            if((pagePokedex -1 > 0) && drawPokedex){
                                Pokedex.PositionChange();
                                pagePokedex--;
                            }
                            if ((pagePokedexEntry -1 > 0) && drawPokedexEntry){
                                pagePokedexEntry = pagePokedexEntry -2;
                            }
                            break;
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            if ((pagePokedex + 1 < (151)) && drawPokedex){
                                Pokedex.PositionChange();
                                pagePokedex++;
                            }
                            if ((pagePokedexEntry + 1 < 68) && drawPokedexEntry){
                                pagePokedexEntry = pagePokedexEntry+2;
                            }
                            break;
                        }
                    break;
                case sf::Event::Closed:
                    window.close();
                    break;
            }
        }

        // clear the window with white color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
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
        // end the current frame
        window.display();
    }

   
    return 0;
}
