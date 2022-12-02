#ifndef PATTERN_H
#define PATTERN_H

#include <stdlib.h>
#include <vector>

// Pattern: -1 = error, 0 = none, 1-5 = colours
// pegs: 0 = empty, 1-5 = colours
// feedbackPegs: 0 = empty, 1 = correct colour and correct location, 2 = correct colour only, 3 = both incorrect colour and location

class Pattern
{
    public:
        Pattern();
        void Reset();

        int get_peg(int index);
        bool add_peg(int type);
        bool set_feedbackPeg(int index, int type);
        int get_filledPegs();
        bool isEqual(Pattern p);

        bool Draw(int x, int y, int w, int h, int fillW, int fillH);

    private:
        std::vector<int> pegs;
        std::vector<int> feedbackPegs;
        int filledPegs;
};

#endif
