#ifndef SCOREBOARD_H
#define SCOREBOARD_H

class ScoreBoard {
public:
    virtual void roll(int pins) = 0;
    virtual int score() = 0;
    virtual ~ScoreBoard() = default;
    //virtual void printFrameDetails() const = 0;
    virtual void printFrameDetails(bool verbose = true) const = 0;


};

#endif

