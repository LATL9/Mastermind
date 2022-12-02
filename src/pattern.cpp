#include "raylib.h"

#include <stdlib.h>
#include <iostream>

#include "pattern.h"

#define PATTERN_SIZE 5

Pattern::Pattern()
{
    pegs = std::vector<int>(PATTERN_SIZE);
    feedbackPegs = std::vector<int>(PATTERN_SIZE);
};
void Pattern::Reset()
{
    pegs = std::vector<int>(PATTERN_SIZE);
    feedbackPegs = std::vector<int>(PATTERN_SIZE);
    filledPegs = 0;
}

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
bool Pattern::set_feedbackPeg(int index, int type)
{
    if (index >= 0 && index <= PATTERN_SIZE && type >= 0 && type <= 3)
    {
        feedbackPegs[index] = type;
        return true;
    }
    else { return false; }
};
int Pattern::get_filledPegs() { return filledPegs; }
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
    Color feedbackColour;

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
        switch (feedbackPegs[i])
        {
            case 0:
                feedbackColour = GRAY;
                break;

            case 1:
                feedbackColour = GREEN;
                break;

            case 2:
                feedbackColour = ORANGE;
                break;

            case 3:
                feedbackColour = RED;
                break;
        }
        DrawRectangle(
            x + i * w,
            y,
            w,
            h,
            feedbackColour
        );
        DrawRectangle(
            x + (float)(w - fillW) / 2 + i * w,
            y + (float)(h - fillH) / 2,
            fillW,
            fillH,
            pegColour
        );
    }
    return true;
};
