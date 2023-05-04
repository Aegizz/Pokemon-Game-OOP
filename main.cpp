#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"
using namespace std;
extern vector<vector<string>> pokemonDatabase();
int main(){
    vector<vector<string>> database = pokemonDatabase();
    Pokemon Bulbasaur = Pokemon("Pokemon Label", "Bulbasaur", database);
    while (true){
        string var;
        cin >> var;
        cout << Bulbasaur.findVariableData(var) << endl;
    }


}