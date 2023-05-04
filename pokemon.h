#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <vector>
using namespace std;

class Pokemon{
    protected:
        string name;
        string pokemonName;
        int row;
        int health;
        vector<vector<string>> data;
    public:
        Pokemon();
        Pokemon(string name, string pokemonName, vector<vector<string>> database);
        string getName();
        string getpokemonName();
        vector<int> getData();
        int getRowPos(vector<vector<string>> database);
                

};
#endif