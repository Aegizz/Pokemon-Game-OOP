#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Menu.h"
#include <unistd.h>
using namespace std;
extern vector<vector<string>> pokemonDatabase(); 

int main(){
    vector<vector<string>> database = pokemonDatabase();
    bool drawMenu = false;
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Music music;


    if (!music.openFromFile("pokemon_title_screen.ogg")){
        return -1; // error
    }
    music.play();

    Menu menu(window.getSize().x, window.getSize().y);
    // run the program as long as the window is open
    sf::Clock clock;

    while (window.isOpen())
    {

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::M)){
            if ((int)((clock.getElapsedTime()).asSeconds()) << 1){
                drawMenu ^= true;
                clock.restart();
            }
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
                            break;
                        case sf::Keyboard::Down:
                            menu.moveDown();
                            break;
                    }
                case sf::Event::Closed:
                    window.close();
            }
        }

        // clear the window with black color
        window.clear(sf::Color::White);

        // draw everything here...
        // window.draw(...);
        if (drawMenu){

            menu.draw(window);
        }
        // end the current frame
        window.display();
    }

   
    return 0;
}
