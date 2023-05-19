#ifndef POKEDEX_H
#define POKEDEX_H
#include <vector>
#include <string>
using namespace std;

class Pokedex:public Menu{
    private:
        vector<string> data;
        int width;
        int height;
    public:
        Pokedex::Pokedex();
        Pokedex::Pokedex(vector<string> data, int width, int height);
        

}