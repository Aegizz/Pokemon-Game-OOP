#ifndef ASSIGNEDATTACK_H
#define ASSIGNEDATTACK_H

#include "pokemon.h"
#include "attack.h"
#include <vector>

using namespace std;

class assignedAttack : public Pokemon {
private:
    vector<Attack> moveSet;

public:
    assignedAttack(string _name, vector<vector<string>> _database)
        : Pokemon(_name, _database) {
        assignMoves();
    }

    void assignMoves();
    vector<Attack> getMoves() const;

    Attack& getRandomAttack();
};

#endif // ASSIGNEDATTACK_H
