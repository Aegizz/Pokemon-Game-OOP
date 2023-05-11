#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
#include <SFML/Graphics.hpp>

using namespace std;
extern vector<vector<string>> pokemonDatabase(); 

int main(){
    vector<vector<string>> database = pokemonDatabase();
    string poke;
    cout << "\nWhich pokemon is this? ";
    cin >> poke;
    Pokemon Poke1 = Pokemon(poke, database);

    return 0;
}
