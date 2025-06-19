#include <iostream>
#include <vector>
using namespace std;

class BowlingGame {
private:
    vector<int> rolls;

public:
    void addRolls(const vector<int>& inputRolls) {
        rolls = inputRolls;
    }

    void calculateScore() {
        int score = 0;
        int rollIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(rollIndex)) {
                score += 10 + strikeBonus(rollIndex);
                cout << "Frame " << frame + 1 << " Score: " << score << endl;
                rollIndex += 1;
            } else if (isSpare(rollIndex)) {
                score += 10 + spareBonus(rollIndex);
                cout << "Frame " << frame + 1 << " Score: " << score << endl;
                rollIndex += 2;
            } else {
                score += sumOfBallsInFrame(rollIndex);
                cout << "Frame " << frame + 1 << " Score: " << score << endl;
                rollIndex += 2;
            }
        }

        cout << "Total Score: " << score << endl;
    }

private:
    bool isStrike(int rollIndex) {
        return rolls[rollIndex] == 10;
    }

    bool isSpare(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1] == 10;
    }

    int strikeBonus(int rollIndex) {
        return rolls[rollIndex + 1] + rolls[rollIndex + 2];
    }

    int spareBonus(int rollIndex) {
        return rolls[rollIndex + 2];
    }

    int sumOfBallsInFrame(int rollIndex) {
        return rolls[rollIndex] + rolls[rollIndex + 1];
    }
};

int main() {
    BowlingGame game;

    // Rolls for all 10 frames (with bonus roll in 10th frame)
    vector<int> inputRolls = {
        1, 4,    // Frame 1
        4, 5,    // Frame 2
        6, 4,    // Frame 3 (Spare)
        5, 5,    // Frame 4 (Spare)
        10,      // Frame 5 (Strike)
        0, 1,    // Frame 6
        7, 3,    // Frame 7 (Spare)
        6, 4,    // Frame 8 (Spare)
        10,      // Frame 9 (Strike)
        2, 8, 6  // Frame 10 (Spare + bonus)
    };

    game.addRolls(inputRolls);
    game.calculateScore();

    return 0;
}