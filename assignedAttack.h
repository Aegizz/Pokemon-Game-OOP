#ifndef ASSIGNEDATTACK_H
#define ASSIGNEDATTACK_H

#include "pokemon.h"
#include "attack.h"
#include <vector>

class assignedAttack : public Pokemon {
private:
    std::vector<Attack> moveSet;

public:
    assignedAttack(std::string _name, std::vector<std::vector<std::string>> _database)
        : Pokemon(_name, _database) {
        assignMoves();
    }

    void assignMoves();
    std::vector<Attack> getMoves() const;
};

#endif // ASSIGNEDATTACK_H