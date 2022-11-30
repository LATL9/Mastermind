#ifndef PATTERN_H
#define PATTERN_H

#include <stdlib.h>
#include <vector>

// -1 = error, 0 = none, 1-5 = colours
class Pattern
{
    public:
        Pattern();
        int get_peg(int index);
        bool add_peg(int type);
        bool isEqual(Pattern p);
        bool Draw(int x, int y, int w, int h, int fillW, int fillH);

    private:
        std::vector<int> pegs;
        int filledPegs;
};

#endif
