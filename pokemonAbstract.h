#include <iostream>
#include <vector>
#include <string>

class PokemonAbstract {
public:
    PokemonAbstract(const std::string& _name, const std::string& _type) : name(_name), type(_type) {}
    virtual ~PokemonAbstract() {}

    std::string getName() const {
        return name;
    }

    std::string getType() const {
        return type;
    }

    virtual void displayInfo() const {
        std::cout << "Pokemon Name: " << getName() << std::endl;
        std::cout << "Type: " << getType() << std::endl;
        std::cout << "Moves: ";
        displayMoves();
        std::cout << std::endl;
    }

protected:
    virtual void displayMoves() const = 0;

private:
    std::string name;
    std::string type;
};

class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(const std::string& _name) : Pokemon(_name, "Electric") {}

protected:
    void displayMoves() const override {
        std::cout << "Thunder Shock, Thunderbolt, Quick Attack" << std::endl;
    }
};

class PsychicPokemon : public Pokemon {
public:
    PsychicPokemon(const std::string& _name) : Pokemon(_name, "Psychic") {}

protected:
    void displayMoves() const override {
        std::cout << "Confusion, Psybeam, Psychic" << std::endl;
    }
};

