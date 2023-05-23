#include <iostream>
#include "assignedAttack.h"

extern vector<vector<string>> pokemonDatabase();
int main() {
    
    std::vector<std::vector<std::string>> pikachuDatabase = {
        { "Pikachu", "Electric" }
    };
    assignedAttack pikachu("Pikachu", pikachuDatabase);

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


    return 0;
}