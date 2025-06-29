#include "BowlingGame.h"

int main() {
    std::string input = "1 4 | 4 5 | 6 / | 5 / | X | 0 1 | 7 / | 6 / | X | 2 / 6";

    BowlingGame game;
    game.parseInput(input);
    game.buildFrames();
    game.printScores();

    return 0;
}
