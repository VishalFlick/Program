#ifndef BOWLINGGAME_H
#define BOWLINGGAME_H

#include "Frame.h"
#include <string>
#include <vector>
#include <memory>

class BowlingGame {
private:
    std::vector<int> rolls;
    std::vector<std::shared_ptr<Frame>> frames;

public:
    void parseInput(const std::string& input);
    void buildFrames();
    void printScores();
};

#endif


