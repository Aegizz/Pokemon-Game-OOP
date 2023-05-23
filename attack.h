#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class Attack {
protected:
    std::string attackName;
    int accuracy;
    int power;
    int remainingPP;

public:
    Attack();
    Attack(const std::string& attackName, int power, int accuracy, int pp);

    std::string getAttackName() const;
    int getAccuracy() const;
    int getPower() const;
    int getRemainingPP() const;
    //void useAttack(Pokemon& target);
};

#endif // ATTACK_H