#include <iostream>
#include <vector>
#include <string>
#include "pokemonAbstract.h"

int main() {
    ElectricPokemon pikachu("Pikachu");
    PsychicPokemon mewtwo("Mewtwo");

    pikachu.displayInfo();
    mewtwo.displayInfo();

    return 0;
}
