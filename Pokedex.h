#ifndef POKEDEX_H
#define POKEDEX_H
#include <vector>
#include <string>
using namespace std;

class Pokedex:public Menu{
    private:
        vector<vector<string>> data;
    public:
        Pokedex::Pokedex();
        Pokedex::Pokedex(vector<vector<string>> data);
        

}