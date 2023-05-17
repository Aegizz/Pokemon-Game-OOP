#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

using namespace std;
extern vector<vector<string>> pokemonDatabase(); 

int main(){
    vector<vector<string>> database = pokemonDatabase();
    string poke;
    cout << "\nWhich pokemon is this? ";
    cin >> poke;
    Pokemon Poke1 = Pokemon(poke, database);
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    sf::Music music;
    if (!music.openFromFile("pokemon_title_screen.ogg")){
        return -1; // error
    }
    music.play();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }
        sf::Texture texture;
        if (!texture.loadFromFile(Poke1.getSprite()))
        {
            return -1;
        }
        sf::Sprite sprite;
        sprite.setTexture(texture);

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
        // window.draw(...);
        window.draw(sprite);

        // end the current frame
        window.display();
    }

   
    return 0;
}
