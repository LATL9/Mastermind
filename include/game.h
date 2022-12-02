#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include <stdlib.h>
#include <vector>

#include "pattern.h"

class Game
{
    public:
        Game();
        void Update();
        void Draw();
        void updateFeedback();

    private:
        std::vector<Pattern> Board;
        Pattern guessPattern;
        int currentPattern;
};

#endif
