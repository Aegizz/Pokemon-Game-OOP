#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
using namespace std;
extern vector<vector<string>> pokemonDatabase();
int main(){
    vector<vector<string>> database = pokemonDatabase();
    Pokemon Bulbasaur = Pokemon("Pokemon Label", "Bulbasaur");
    

}