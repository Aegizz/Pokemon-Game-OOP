//attack class
#ifndef ATTACK_H
#define ATTACK_H

#include <string>

class Attack {
protected:
    std::string attackName; // Name of the attack
    int accuracy; // Accuracy of the attack
    int power; // Power of the attack
    int remainingPP; // Remaining Power Points (PP) of the attack

public:
    /**
     * Default constructor for Attack class.
     */
    Attack();

    /**
     * Parameterized constructor for Attack class.
     * @param attackName The name of the attack.
     * @param power The power of the attack.
     * @param accuracy The accuracy of the attack.
     * @param pp The remaining Power Points (PP) of the attack.
     */
    Attack(const std::string& attackName, int power, int accuracy, int pp);

    /**
     * Get the name of the attack.
     * @return The name of the attack.
     */
    std::string getAttackName() const;

    /**
     * Get the accuracy of the attack.
     * @return The accuracy of the attack.
     */
    int getAccuracy() const;

    /**
     * Get the power of the attack.
     * @return The power of the attack.
     */
    int getPower() const;

    /**
     * Get the remaining Power Points (PP) of the attack.
     * @return The remaining Power Points (PP) of the attack.
     */
    int getRemainingPP() const;

};

#endif // ATTACK_H
