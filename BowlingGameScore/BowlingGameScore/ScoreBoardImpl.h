#ifndef SCOREBOARD_IMPL_HPP
#define SCOREBOARD_IMPL_HPP

#include "ScoreBoard.h"
#include "AppConstants.h"
#include "Bonus.h"
#include <vector>

class ScoreBoardImpl : public ScoreBoard {
private:
    std::vector<int> rolls;

    bool isStrike(int frameIndex) const;
    bool isSpare(int frameIndex) const;
    int strikeBonus(int frameIndex) const;
    int spareBonus(int frameIndex) const;

public:
    void roll(int pins) override;
    int score() override;
};

#endif
