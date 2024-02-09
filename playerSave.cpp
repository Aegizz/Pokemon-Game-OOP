#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "playerSave.h"
using namespace std;

playerSave::playerSave(){
    poke = new const char*[6];
    pokeSize = 0;
}

void playerSave::saveState(vector<string> Pokemon){
    poke = new string[Pokemon.size()];
    for (int i = 0; i< Pokemon.size(); i++){
        poke[i] = Pokemon[i];
    }
    ofstream saveFile;
    saveFile.open("Save.csv");
    for (int i = 0;  i < pokeSize; i++){
        saveFile << (string)poke[i] << ", ";
    }
    saveFile.close();
    delete []poke;
}
vector<string> playerSave::readPlayerSave()
{
    // Open the CSV file
    ifstream file("Save.csv");

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open file!" << std::endl;
        vector<string> error = {{"error"}};
        return error;
    }

    // Create a vector to store the rows of the CSV file
    string line;
    // Read the file line by line and store each row as a vector of strings
    vector<string> row;
    stringstream ss(line);
    string cell;
    while (getline(ss, cell, ',')) {
        row.push_back(cell);
    }
    
    return row;
}
vector<string> playerSave::getPlayerSave(){
    vector<string> Pokemon = readPLayerSave();
    poke = new string[Pokemon.size()];

    for (int i = 0; i < Pokemon.size(); i++){
        poke[i] = Pokemon[i];

    }
    
}
