#ifndef POKEMON_H
#define POKEMON_H
#include <string>
#include <vector>
using namespace std;

class Pokemon{
    protected:
        string pokemonName;
        int row;
        int health;
        vector<vector<string>> data;
        int level;
        string type;
    public:
        Pokemon();
        Pokemon(string pokemonName, vector<vector<string>> database);
        string getpokemonName();
        vector<vector<string>> getData();
        int getRowPos(vector<vector<string>> database);
        int getRow();
        string findVariableData(string input);
        void setHealth(int _health);
        int getHealth();
        void setLevel(int level);
        int getLevel();
        string getType();
        void setType(string _type);

};
#endif