#include "pokemon.h"
#include <vetcor>
#include <string>
using namespace std;

Pokemon::Pokemon(){

};

Pokemon::Pokemon(string _name, string _pokemonName, vector<vector<string>> _database){
    name = _name;
    pokemonName = _pokemonName;
    database = _database;
    row = getRowPos();

};
string Pokemon::getName(){
    return name;
};
string Pokemon::getpokemonName(){
    return pokemonName;
};
vector<int> Pokemon::getData(){
    return data;
};

int Pokemon::getRowPos(vector<vector<string>> database){
    for (int i = 0; i < database.size(); i++){
        for (int j = 0; j < database[1].size(); j++){
            if (database[i][j] == pokemonName){
                row  = i;
            }
        }
    }
    return row;
}