#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
using namespace std;
extern vector<vector<string>> pokemonDatabase();
int main(){
    vector<vector<string>> database = pokemonDatabase();
    string var = "";
    while (true){
        string poke;
        cout << "\nWhich pokemon is this? ";
        cin >> poke;
        Pokemon Poke1 = Pokemon(poke, database);
        while (var != "newPokemon"){
            cout << "\nDetail? ";
            cin >> var;
            cout << Poke1.findVariableData(var) << endl;
        }
    }
}