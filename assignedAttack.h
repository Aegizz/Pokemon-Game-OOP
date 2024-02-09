//Attack Class Inherited from pokemon
#ifndef ASSIGNEDATTACK_H
#define ASSIGNEDATTACK_H

#include "Pokemon.h"
#include "attack.h"
#include <vector>


using namespace std;

class assignedAttack : public Pokemon {
private:
    vector<Attack> moveSet; // A vector to store the assigned attacks for the Pokemon.

public:
    assignedAttack(string _name, vector<vector<string>> _database)
        : Pokemon(_name, _database) {
        assignMoves();  // Constructor that assigns moves to the Pokemon upon creation.
    }

    void assignMoves();  // Function to assign moves to the Pokemon.

    vector<Attack> getMoves() const;  // Function to retrieve the assigned moves of the Pokemon.

    Attack& getRandomAttack();  // Function to get a random attack from the assigned move set.

};

#endif // ASSIGNEDATTACK_H
