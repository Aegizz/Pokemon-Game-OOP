#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;
vector<vector<string>> pokemonDatabase()
{
    // Open the CSV file
    ifstream file("FirstGenPokemon.csv");

    // Check if the file was opened successfully
    if (!file.is_open()) {
        cerr << "Error: Could not open file!" << std::endl;
        vector<vector<string>> error = {{"error"}};
        return error;
    }

    // Create a vector to store the rows of the CSV file
    vector<vector<string>> rows;

    // Read the file line by line and store each row as a vector of strings
    string line;
    while (std::getline(file, line)) {
        vector<std::string> row;
        stringstream ss(line);
        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        rows.push_back(row);
    }
    return rows;
}
