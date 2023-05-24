//Passed Test: Tested for retrieving the Pokemon database, creating an assignedAttack object and disp their properties
#include <vector>
#include <cstdlib> // Include the <cstdlib> header for the rand() function
#include <ctime>   // Include the <ctime> header for seeding the random number generator
#include "assignedAttack.h"
#include "pokemon.h"
#include "attack.h"
#include <iostream>
#include <cstdlib>

extern std::vector<std::vector<std::string>> pokemonDatabase();

int main() {
    std::vector<std::vector<std::string>> database = pokemonDatabase();


    assignedAttack pikachu("Pikachu", database);

    // Retrieve and display the moves of Pikachu
    std::vector<Attack> moves = pikachu.getMoves();
    std::cout << "Pikachu's moves:" << std::endl;
    for (const Attack& move : moves) {
        std::cout << "Move Name: " << move.getAttackName() << std::endl;
        std::cout << "Power: " << move.getPower() << std::endl;
        std::cout << "Accuracy: " << move.getAccuracy() << std::endl;
        std::cout << "Remaining PP: " << move.getRemainingPP() << std::endl;
        std::cout << std::endl;
    }


    // Get a random attack
    Attack& randomAttack = pikachu.getRandomAttack();

    // Display the attack details
    std::cout << "Random Attack:\n";
    std::cout << "Name: " << randomAttack.getAttackName() << "\n";
    std::cout << "Power: " << randomAttack.getPower() << "\n";
    std::cout << "Accuracy: " << randomAttack.getAccuracy() << "\n";
    std::cout << "PP: " << randomAttack.getRemainingPP() << "\n";

    return 0;
}
