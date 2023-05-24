//Passed Test - Tested for retrieving the Pokemon database, creating an Attacj object and disp their properties
#include <iostream>
#include "attack.h"

int main() {
    // Create an Attack object
    Attack ember("Ember", 40, 100, 20);

    // Access and display the attack properties
    std::cout << "Attack Name: " << ember.getAttackName() << std::endl;
    std::cout << "Power: " << ember.getPower() << std::endl;
    std::cout << "Accuracy: " << ember.getAccuracy() << std::endl;
    std::cout << "Remaining PP: " << ember.getRemainingPP() << std::endl;

    return 0;
}
