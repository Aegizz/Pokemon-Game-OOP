// Implementation for assignedAttack class
#include "assignedAttack.h"
#include <iostream>
using namespace std;
#include <cstdlib>


void assignedAttack::assignMoves() {
    string type = getType(); // Get the type of the Pokémon

    if (type == "fire") {   // Assign fire based moves if pokemonType==fire
        moveSet = {
            Attack("Ember", 5, 100, 20),
            Attack("Fire Blast", 6, 85, 20),
            Attack("Flamethrower", 7, 100, 20),
            Attack("Fire Spin", 8, 85, 20)
        };
    } else if (type == "water") {   // Assign water based moves if pokemonType==water
        moveSet = {
            Attack("Water Gun", 5, 100, 20),
            Attack("Hydro Pump", 6, 85, 20),
            Attack("Surf", 7, 100, 20),
            Attack("Bubble Beam", 8, 85, 20)
        };
    } else if (type == "grass") {      // Assign grass based moves if pokemonType==grass
        moveSet = {
            Attack("Vine Whip", 5, 100, 20),
            Attack("Solar Beam", 6, 85, 20),
            Attack("Razor Leaf", 7, 95, 20),
            Attack("Seed Bomb", 8, 100, 20)
        };
    } else if (type == "electric") {      // Assign grass based moves if pokemonType==grass
        moveSet = {
            Attack("Thunder Shock", 5, 100, 20),
            Attack("Thunderbolt", 6, 100, 20),
            Attack("Thunder", 7, 70, 20),
            Attack("Zap Cannon", 8, 50, 20)
        };
    } else {
        // Default moves for other types
        moveSet = {
            Attack("Tackle", 5, 100, 20),
            Attack("Scratch", 6, 100, 20),
            Attack("Bite", 7, 100, 20),
            Attack("Growl", 8, 100, 20)
        };
    }
}

// The getMoves() function returns the moveSet, which contains the assigned moves of the Pokemon.
vector<Attack> assignedAttack::getMoves() const {
    return moveSet;
}

// The getRandomAttack() function returns a random attack from the moveSet.
Attack& assignedAttack::getRandomAttack() {
    int randomIndex = rand() % moveSet.size();
    return moveSet[randomIndex];
}