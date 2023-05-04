#ifndef POKEMONFAMILY_H
#define POKEMONFAMILY_H
#include "pokemon.h"
#include <vector>
#include <string>
using namespace std;

class pokemonFamily:public Pokemon{
    protected:
        vector<string> evolutions;

    public:
        pokemonFamily();
        pokemonFamily(vector<string> evolutions);
        vector<string> getEvolutions();
        

};
#endif