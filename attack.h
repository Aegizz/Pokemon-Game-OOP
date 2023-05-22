#ifndef ATTACK_H
#define ATTACK_H

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "pokemon.h"

using namespace std;

class Attack {
protected:
    string attackName;
    int accuracy;
    int power;
    int remainingPP;
    int health;

public:
    Attack();
    Attack(string attackName, int power, int accuracy, int pp);

    int getAttackName();
    int getAccuracy();
    int getPower();
    int getRemainingPP();
    void useAttack(Pokemon& target);
};

#endif // ATTACK_H
