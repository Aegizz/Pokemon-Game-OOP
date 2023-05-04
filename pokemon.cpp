#include "pokemon.h"
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

Pokemon::Pokemon(){

};

Pokemon::Pokemon(string _name, string _pokemonName, vector<vector<string>> _database){
    name = _name;
    pokemonName = _pokemonName;
    data = _database;
    for (int i = 0; i < _database.size(); i++){
        for (int j = 0; j < _database[1].size(); j++){
            if (_database[i][j] == pokemonName){
                row  = i;
            }
        }
    }

};
string Pokemon::getName(){
    return name;
};
string Pokemon::getpokemonName(){
    return pokemonName;
};
vector<vector<string>> Pokemon::getData(){
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
int Pokemon::getRow(){
    return row;
}

string Pokemon::findVariableData(string input){
    for (int j = 0; j < data[1].size(); j++){
        if (data[0][j] == input){
                return data[row][j];

            }
        }
    return "Error";
}   