#include <iostream>
#include <vector>
using namespace std;

// Function to take input for rolls
void inputRolls(vector<int>& rolls) {
    int pins;
    int frame = 1;

    while (frame <= 10) {
        cout << "Frame " << frame << ", Roll 1: ";
        cin >> pins;
        while (pins < 0 || pins > 10) {
            cout << "Invalid. Enter a number between 0 and 10: ";
            cin >> pins;
        }
        rolls.push_back(pins);

        int second = 0;

        // Frame 10 always takes second roll, even if strike
        if (frame < 10 && pins == 10) {
            frame++;
            continue;
        }

        cout << "Frame " << frame << ", Roll 2: ";
        cin >> second;
        while (second < 0 || (frame < 10 && pins + second > 10)) {
            cout << "Invalid. Total pins in one frame can't exceed 10. Re-enter: ";
            cin >> second;
        }

        rolls.push_back(second);

        // Frame 10: Check for bonus roll
        if (frame == 10 && (pins == 10 || pins + second == 10)) {
            int bonus;
            cout << "Frame 10 Bonus Roll: ";
            cin >> bonus;
            while (bonus < 0 || bonus > 10) {
                cout << "Invalid. Enter a number between 0 and 10: ";
                cin >> bonus;
            }
            rolls.push_back(bonus);
        }

        frame++;
    }
}

// Utility functions
bool isStrike(const vector<int>& rolls, int index) {
    return rolls[index] == 10;
}

bool isSpare(const vector<int>& rolls, int index) {
    return rolls[index] + rolls[index + 1] == 10;
}

int strikeBonus(const vector<int>& rolls, int index) {
    return rolls[index + 1] + rolls[index + 2];
}

int spareBonus(const vector<int>& rolls, int index) {
    return rolls[index + 2];
}

int sumOfBallsInFrame(const vector<int>& rolls, int index) {
    return rolls[index] + rolls[index + 1];
}

// Score calculation and output
void calculateScore(const vector<int>& rolls) {
    int score = 0;
    int index = 0;

    for (int frame = 0; frame < 9; ++frame) {
        if (isStrike(rolls, index)) {
            score += 10 + strikeBonus(rolls, index);
            cout << "Frame " << frame + 1 << " Score: " << score << " (Strike)" << endl;
            index += 1;
        } else if (isSpare(rolls, index)) {
            score += 10 + spareBonus(rolls, index);
            cout << "Frame " << frame + 1 << " Score: " << score << " (Spare)" << endl;
            index += 2;
        } else {
            score += sumOfBallsInFrame(rolls, index);
            cout << "Frame " << frame + 1 << " Score: " << score << " (Open)" << endl;
            index += 2;
        }
    }

    // Frame 10
    int r1 = rolls[index];
    int r2 = rolls[index + 1];
    int r3 = (index + 2 < rolls.size()) ? rolls[index + 2] : 0;

    int frame10Score = r1 + r2 + r3;
    score += frame10Score;

    string type10 = (r1 == 10) ? "Strike" : (r1 + r2 == 10) ? "Spare" : "Open";
    cout << "Frame 10 Score: " << score << " (" << type10 << ") Rolls: " << r1 << ", " << r2;
    if (r3 > 0 || (r1 == 10 || r1 + r2 == 10)) {
        cout << ", Bonus: " << r3;
    }
    cout << endl;

    cout << "\nTotal Score: " << score << endl;
}

// Main function
int main() {
    vector<int> rolls;
    inputRolls(rolls);
    calculateScore(rolls);
    return 0;
}
