#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int pokemonDatabase()
{
    // Open the CSV file
    std::ifstream file("FirstGenPokemon.csv");

    // Check if the file was opened successfully
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file!" << std::endl;
        return 1;
    }

    // Create a vector to store the rows of the CSV file
    std::vector<std::vector<std::string>> rows;

    // Read the file line by line and store each row as a vector of strings
    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::string> row;
        std::stringstream ss(line);
        std::string cell;
        while (std::getline(ss, cell, ',')) {
            row.push_back(cell);
        }
        rows.push_back(row);
    }
    // Print the value of cell A2 (second row, first column)
    return 0;
}
