#include "BowlingGame.h"
#include "FrameFactory.h"
#include <sstream>
#include <iostream>

void BowlingGame::parseInput(const std::string& input) {
    rolls.clear();
    std::istringstream ss(input);
    std::string token;
    int prev = 0;

    while (ss >> token) {
        if (token == "|") continue;

        if (token == "X") {
            rolls.push_back(10);
            prev = 10;
        }
        else if (token == "/") {
            rolls.push_back(10 - prev);
            prev = 10 - prev;
        }
        else if (token.size() == 2 && token[1] == '/') {
            int first = token[0] - '0';
            rolls.push_back(first);
            rolls.push_back(10 - first);
            prev = 10 - first;
        }
        else {
            int val = std::stoi(token);
            rolls.push_back(val);
            prev = val;
        }
    }
}

void BowlingGame::buildFrames() {
    frames.clear();
    int index = 0;
    for (int i = 1; i <= 10; ++i) {
        auto frame = FrameFactory::createFrame(rolls, index, i);
        frames.push_back(frame);
        index += frame->getAdvance();
    }
}

void BowlingGame::printScores() {
    int total = 0;
    for (size_t i = 0; i < frames.size(); ++i) {
        int score = frames[i]->getScore(rolls);
        total += score;
        std::cout << "Frame " << (i + 1) << ": Total = " << total << std::endl;
    }
    std::cout << "Final Score: " << total << std::endl;
}
