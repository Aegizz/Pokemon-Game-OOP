#include "pokemonFamily.h"
#include <vector>
#include <string>
using namespace std;
pokemonFamily::pokemonFamily(){

};

pokemonFamily::pokemonFamily(vector<string> _evolutions){
    evolutions = _evolutions
}
vector<string> pokemonFamily::getEvolutions(){
    return evolutions;
}