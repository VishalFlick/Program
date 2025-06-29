#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class ScoreBoard {
public:
    virtual void roll(int pins) = 0;
    virtual int score() = 0;
    virtual ~ScoreBoard() = default;
};

#endif

