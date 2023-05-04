#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ifstream file("FirstGenPokemon.csv");  // Open the CSV file
    vector<vector<int>> data;   // Create a vector of vectors to store the data

    string line;
    while (getline(file, line)) {
        vector<int> row;
        stringstream ss(line);  // Create a stringstream from the line

        string cell;
        while (getline(ss, cell, ',')) {
            row.push_back(stoi(cell));  // Convert the cell string to an integer and add it to the row vector
        }

        data.push_back(row);  // Add the row vector to the data vector
    }

    file.close();  // Close the CSV file

    // Do something with the data vector...
}