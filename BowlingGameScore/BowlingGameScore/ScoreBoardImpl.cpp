#include "ScoreBoardImpl.h"
#include<iostream>

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

void ScoreBoardImpl::printFrameDetails(bool verbose) const {
    if (!verbose) return;

    int frameIndex = 0;
    int cumulativeScore = 0;

    std::cout << "\n--- Frame-by-frame breakdown ---\n";
    for (int frame = 0; frame < AppConstants::TOTAL_SETS; ++frame) {
        std::cout << "Frame " << (frame + 1) << ":\n";

        if (isStrike(frameIndex)) {
            int bonus1 = rolls[frameIndex + 1];
            int bonus2 = rolls[frameIndex + 2];
            int frameScore = 10 + bonus1 + bonus2;
            cumulativeScore += frameScore;
            std::cout << "  Frame score is 10 (Strike)\n";
            std::cout << "  Total score is " << cumulativeScore
                << " (10 + " << bonus1 << " + " << bonus2
                << " bonus + score of previous frames)\n";
            frameIndex += 1;
        }
        else if (isSpare(frameIndex)) {
            int first = rolls[frameIndex];
            int bonus = rolls[frameIndex + 2];
            int frameScore = 10 + bonus;
            cumulativeScore += frameScore;
            std::cout << "  Frame score is 10 (Spare)\n";
            std::cout << "  Total score is " << cumulativeScore
                << " (10 + " << bonus << " bonus + score of previous frames)\n";
            frameIndex += 2;
        }
        else {
            int first = rolls[frameIndex];
            int second = rolls[frameIndex + 1];
            int frameScore = first + second;
            cumulativeScore += frameScore;
            std::cout << "  Frame score is " << frameScore << " (" << first << "+" << second << ")\n";
            std::cout << "  Total score is " << cumulativeScore << "\n";
            frameIndex += 2;
        }
    }
}



