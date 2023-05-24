#ifndef PLAYERSAVE_H
#define PLAYERSAVE_H

#include "Player.h"
#include "pokemon.h"


class playerSave{
    private:
        const char** poke;
        int pokeSize;
    public:
        playerSave();
        void saveState(vector<string> pokemon);
        vector<string> readPlayerSave();
        vector<string> getPlayerSave();
};
#endif