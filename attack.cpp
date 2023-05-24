#include "attack.h"

Attack::Attack() {
}

Attack::Attack(const std::string& attackName, int power, int accuracy, int pp)
    : attackName(attackName), power(power), accuracy(accuracy), remainingPP(pp) {
}

std::string Attack::getAttackName() const {
    return attackName;
}

int Attack::getAccuracy() const {
    return accuracy;
}

int Attack::getPower() const {
    return power;
}

int Attack::getRemainingPP() const {
    return remainingPP;
}
