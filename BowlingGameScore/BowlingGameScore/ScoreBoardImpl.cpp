#include "ScoreBoardImpl.h"

void ScoreBoardImpl::roll(int pins) {
    rolls.push_back(pins);
}

int ScoreBoardImpl::score() {
    int totalScore = 0;
    int frameIndex = 0;

    for (int frame = 0; frame < AppConstants::TOTAL_SETS; frame++) {
        if (isStrike(frameIndex)) {
            totalScore += 10 + rolls[frameIndex + 1] + rolls[frameIndex + 2];
            frameIndex += 1;
        }
        else if (isSpare(frameIndex)) {
            totalScore += 10 + rolls[frameIndex + 2];
            frameIndex += 2;
        }
        else {
            totalScore += rolls[frameIndex] + rolls[frameIndex + 1];
            frameIndex += 2;
        }
    }
    return totalScore;
}

bool ScoreBoardImpl::isStrike(int frameIndex) const {
    return rolls[frameIndex] == 10;
}

bool ScoreBoardImpl::isSpare(int frameIndex) const {
    return rolls[frameIndex] + rolls[frameIndex + 1] == 10;
}

int ScoreBoardImpl::strikeBonus(int frameIndex) const {
    return rolls[frameIndex + 1] + rolls[frameIndex + 2];
}

int ScoreBoardImpl::spareBonus(int frameIndex) const {
    return rolls[frameIndex + 2];
}
