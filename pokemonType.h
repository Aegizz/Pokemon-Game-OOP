#ifndef POKEMONTYPE_H
#define POKEMONTYPE_H
#include <string>

using namespace std;

class PokemonType{
    protected:
        string type;
    public:
        Type();
        void getWeakness();

};
#endif