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
        string type;
        vector<vector<string>> data;
        int level;
        string sprite;
        vector<string> attacks;
    public:
        Pokemon();
        Pokemon(string pokemonName, vector<vector<string>> database);
        string getpokemonName();
        vector<vector<string>> getData();
        int getRowPos(vector<vector<string>> database);
        int getRow();
        string findVariableData(string input);
        void setLevel(int level);
        int getLevel();
        string getSprite();
        int getHealth();
        void setHealth();
        void setAttacks(const vector<string>& attackList);
        vector<Attack> getAttacks();
        string getType();
        void setType();
};
#endif