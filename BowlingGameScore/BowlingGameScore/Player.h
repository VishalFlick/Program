#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include <iostream>
#include "ScoreBoard.h"

class Player {
private:
    int id;
    std::string name;
    ScoreBoard* scoreBoard;
    bool isWin = false;

public:
    Player(int id, const std::string& name, ScoreBoard* sb)
        : id(id), name(name), scoreBoard(sb) {
    }

    std::string getName() const { return name; }
    ScoreBoard* getScoreBoard() const { return scoreBoard; }
    void setWin(bool win) { isWin = win; }
    bool getWin() const { return isWin; }

    friend std::ostream& operator<<(std::ostream& os, const Player& p) {
        os << "Player { id=" << p.id << ", name=" << p.name
            << ", score=" << p.scoreBoard->score()
            << ", isWin=" << (p.isWin ? "true" : "false") << " }";
        return os;
    }
};

#endif
