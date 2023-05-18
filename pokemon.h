#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

extern std::vector<std::vector<std::string>> pokemonDatabase();

class Pokemon {
private:
    std::string pokemonName;
    int row;
    int health;
    std::vector<std::vector<std::string>> data;

public:
    Pokemon();
    Pokemon(std::string pokemonName, std::vector<std::vector<std::string>> database);
    std::string getpokemonName();
    std::vector<std::vector<std::string>> getData();
    int getRowPos(std::vector<std::vector<std::string>> database);
    int getRow();
    std::string findVariableData(std::string input);
};

#endif
