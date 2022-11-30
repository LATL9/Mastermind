#include "raylib.h"
#include <stdlib.h>
#include <iostream>

#include "pattern.h"

#define PATTERN_SIZE 5

Pattern::Pattern()
{
    pegs = std::vector<int>(PATTERN_SIZE);
};

int Pattern::get_peg(int index)
{
    if (index >= 0 && index <= PATTERN_SIZE) { return pegs[index]; }
    else { return -1; }
};
bool Pattern::add_peg(int type)
{
    if (filledPegs < PATTERN_SIZE && type > 0 && type <= PATTERN_SIZE)
    {
        pegs[filledPegs] = type;
        ++filledPegs;
        return true;
    } else { return false; }
};

bool Pattern::isEqual(Pattern p)
{
    for (int i = 0; i < PATTERN_SIZE; ++i)
    {
        if (pegs[i] != p.get_peg(i)) { return false; }
    }
    return true;
};

bool Pattern::Draw(int x, int y, int w, int h, int fillW, int fillH)
{
    Color pegColour;

    for (int i = 0; i < PATTERN_SIZE; ++i)
    {
        switch (pegs[i])
        {
            case 0:
                pegColour = GRAY;
                break;

            case 1:
                pegColour = RED;
                break;

            case 2:
                pegColour = ORANGE;
                break;

            case 3:
                pegColour = YELLOW;
                break;

            case 4:
                pegColour = GREEN;
                break;

            case 5:
                pegColour = BLUE;
                break;
        }
        DrawRectangle(
            x + (float)(w - fillW) / 2,
            y + (float)(h - fillH) / 2,
            fillW,
            fillH,
            pegColour
        );
    }
    return true;
};
