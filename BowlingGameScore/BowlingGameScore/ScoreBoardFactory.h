#ifndef SCOREBOARD_FACTORY_H
#define SCOREBOARD_FACTORY_H

#include "ScoreBoard.h"
#include "ScoreBoardImpl.h"
#include <string>

class ScoreBoardFactory {
public:
    static ScoreBoard* createScoreBoard(const std::string& type) {
        if (type == "default") {
            return new ScoreBoardImpl();
        }
        return nullptr;
    }
};

#endif
