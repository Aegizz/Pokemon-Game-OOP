 #include "assignedAttack.h"

void assignedAttack::assignMoves() {
    std::string type = getType(); // Get the type of the Pokémon

    if (type == "fire") {
        moveSet = {
            Attack("Ember", 40, 100, 20),
            Attack("Fire Blast", 110, 85, 20),
            Attack("Flamethrower", 90, 100, 20),
            Attack("Fire Spin", 35, 85, 20)
        };
    } else if (type == "water") {
        moveSet = {
            Attack("Water Gun", 40, 100, 20),
            Attack("Hydro Pump", 110, 85, 20),
            Attack("Surf", 90, 100, 20),
            Attack("Bubble Beam", 35, 85, 20)
        };
    } else if (type == "grass") {
        moveSet = {
            Attack("Vine Whip", 45, 100, 20),
            Attack("Solar Beam", 120, 85, 20),
            Attack("Razor Leaf", 55, 95, 20),
            Attack("Seed Bomb", 80, 100, 20)
        };
    } else if (type == "electric") {
        moveSet = {
            Attack("Thunder Shock", 40, 100, 20),
            Attack("Thunderbolt", 90, 100, 20),
            Attack("Thunder", 110, 70, 20),
            Attack("Zap Cannon", 120, 50, 20)
        };
    } else {
        // Default moves for other types
        moveSet = {
            Attack("Tackle", 40, 100, 20),
            Attack("Scratch", 40, 100, 20),
            Attack("Bite", 60, 100, 20),
            Attack("Growl", 0, 100, 20)
        };
    }
}

std::vector<Attack> assignedAttack::getMoves() const {
    return moveSet;
}