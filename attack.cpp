//Implementation for attack class
#include "attack.h"

Attack::Attack() {
    // Default constructor
}

Attack::Attack(const std::string& attackName, int power, int accuracy, int pp)
    : attackName(attackName), power(power), accuracy(accuracy), remainingPP(pp) {
    // Constructor with parameters to initialize attack properties
}

std::string Attack::getAttackName() const {
    // Get the name of the attack
    return attackName;
}

int Attack::getAccuracy() const {
    // Get the accuracy of the attack
    return accuracy;
}

int Attack::getPower() const {
    // Get the power of the attack
    return power;
}

int Attack::getRemainingPP() const {
    // Get the remaining PP (Power Points) of the attack
    return remainingPP;
}