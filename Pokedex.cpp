#include "Pokedex.h"
#include <string>
#include <vector>
using namespace std;


Pokedex::Pokedex(){

};

Pokedex::Pokedex(vector<string> _data, int _width, int _height){
    data = _data;
    width = _width;
    height = _height;
}
