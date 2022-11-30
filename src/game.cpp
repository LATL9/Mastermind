#include <stdlib.h>
#include <random>
#include "raylib.h"
#include "game.h"

Game::Game()
{
    // FIX RANDOMNESSS **TODO**
    srand(0);
    
    Board = std::vector<Pattern> (12);
    Pattern guessPattern = {};

    for (int i = 0; i < 5; ++i)
    {
        guessPattern.add_peg(rand() % 5 + 1);
    }
};

void Game::Update()
{
    if (IsKeyPressed(KEY_ONE)) { Board[0].add_peg(1); }
    if (IsKeyPressed(KEY_TWO)) { Board[0].add_peg(2); }
    if (IsKeyPressed(KEY_THREE)) { Board[0].add_peg(3); }
    if (IsKeyPressed(KEY_FOUR)) { Board[0].add_peg(4); }
    if (IsKeyPressed(KEY_FIVE)) { Board[0].add_peg(5); }
};

void Game::Draw()
{
    for (int i = 0; i < 12; ++i)
    {
        Board[i].Draw(32, (i + 1) * 32, 32, 32, 24, 24);
    }
    guessPattern.Draw(32, 400, 32, 32, 24, 24);
};
