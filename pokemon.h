#ifndef POKEMON_H
#define POKEMON_H
#include <string>
using namespace std;

class Pokemon{
    protected:
        string name;
        string pokemonName;
        int health;
        int data [40];
    public:
        Pokemon();
        Pokemon(string name, string pokemonName);
        string getName();
        string getpokemonName();
                

};
#endif