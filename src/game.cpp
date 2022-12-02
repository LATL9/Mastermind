#include "raylib.h"

#include <stdlib.h>
#include <random>
#include <iostream>

#include "game.h"

#define PATTERN_SIZE 5

Game::Game()
{
    // FIX RANDOMNESSS **TODO**
    srand(0);

    Board = std::vector<Pattern> (12);
    guessPattern = {};
    currentPattern = 0;

    for (int i = 0; i < PATTERN_SIZE; ++i)
    {
        guessPattern.add_peg(rand() % PATTERN_SIZE + 1);
    }
};

void Game::Update()
{
    if (IsKeyPressed(KEY_ONE)) { Board[currentPattern].add_peg(1); }
    if (IsKeyPressed(KEY_TWO)) { Board[currentPattern].add_peg(2); }
    if (IsKeyPressed(KEY_THREE)) { Board[currentPattern].add_peg(3); }
    if (IsKeyPressed(KEY_FOUR)) { Board[currentPattern].add_peg(4); }
    if (IsKeyPressed(KEY_FIVE)) { Board[currentPattern].add_peg(5); }
    if (Board[currentPattern].get_filledPegs() == PATTERN_SIZE)
    {
        updateFeedback();
        ++currentPattern;
    }
};

void Game::Draw()
{
    for (int i = 0; i < 12; ++i)
    {
        Board[i].Draw(32, (i + 1) * 32, 32, 32, 24, 24);
    }
    guessPattern.Draw(32, 416, 32, 32, 24, 24);
};

void Game::updateFeedback()
{
    bool matchColour;
    bool matchPosition;

    for (int i = 0; i < PATTERN_SIZE; ++i)
    {
        std::cout << i << ' ';
        matchColour = false;
        matchPosition = false;

        for (int j = 0; j < PATTERN_SIZE; ++j)
        {
            if (Board[currentPattern].get_peg(i) == guessPattern.get_peg(j))
            {
                matchColour = true;
                if (i == j)
                {
                    matchPosition = true;
                    Board[currentPattern].set_feedbackPeg(i, 1);
                    break;
                }
            }
        }

        if (!matchPosition)
        {
            switch (matchColour)
            {
                case true:
                    Board[currentPattern].set_feedbackPeg(i, 2);
                    break;

                default:
                    Board[currentPattern].set_feedbackPeg(i, 3);
                    break;
            }
        }
    }
};


void Game::add_peg(int index, int type)
{
	Board[index].add_peg(type);
	++currentPattern;
}
