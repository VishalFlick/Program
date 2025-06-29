#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
using namespace std;

// ------------------- Frame Base Class -------------------
class Frame {
protected:
    int index;
public:
    Frame(int idx) : index(idx) {}
    virtual int getScore(const vector<int>& rolls) = 0;
    virtual int getAdvance() = 0;
    virtual ~Frame() = default;
};

// ------------------- Frame Types -------------------
class StrikeFrame : public Frame {
public:
    StrikeFrame(int idx) : Frame(idx) {}
    int getScore(const vector<int>& rolls) override {
        return 10 + rolls[index + 1] + rolls[index + 2];
    }
    int getAdvance() override {
        return 1;
    }
};

class SpareFrame : public Frame {
public:
    SpareFrame(int idx) : Frame(idx) {}
    int getScore(const vector<int>& rolls) override {
        return 10 + rolls[index + 2];
    }
    int getAdvance() override {
        return 2;
    }
};

class OpenFrame : public Frame {
public:
    OpenFrame(int idx) : Frame(idx) {}
    int getScore(const vector<int>& rolls) override {
        return rolls[index] + rolls[index + 1];
    }
    int getAdvance() override {
        return 2;
    }
};

class TenthFrame : public Frame {
public:
    TenthFrame(int idx) : Frame(idx) {}
    int getScore(const vector<int>& rolls) override {
        return rolls[index] + rolls[index + 1] + (index + 2 < rolls.size() ? rolls[index + 2] : 0);
    }
    int getAdvance() override {
        return 3;
    }
};

// ------------------- Factory -------------------
class FrameFactory {
public:
    static shared_ptr<Frame> createFrame(const vector<int>& rolls, int index, int frameNum) {
        if (frameNum == 10) {
            return make_shared<TenthFrame>(index);
        } else if (rolls[index] == 10) {
            return make_shared<StrikeFrame>(index);
        } else if (rolls[index] + rolls[index + 1] == 10) {
            return make_shared<SpareFrame>(index);
        } else {
            return make_shared<OpenFrame>(index);
        }
    }
};

// ------------------- BowlingGame -------------------
class BowlingGame {
private:
    vector<int> rolls;
    vector<shared_ptr<Frame>> frames;

public:
    void parseInput(const string& input) {
        rolls.clear();
        istringstream ss(input);
        string token;
        int prev = 0;

        while (ss >> token) {
            if (token == "|") continue;

            if (token == "X") {
                rolls.push_back(10);
                prev = 10;
            } else if (token == "/") {
                rolls.push_back(10 - prev);
                prev = 10 - prev;
            } else if (token.length() == 2 && token[1] == '/') {
                int first = token[0] - '0';
                rolls.push_back(first);
                rolls.push_back(10 - first);
                prev = 10 - first;
            } else if (isdigit(token[0])) {
                int val = stoi(token);
                rolls.push_back(val);
                prev = val;
            }
        }
    }

    void buildFrames() {
        frames.clear();
        int index = 0;
        for (int i = 1; i <= 10; ++i) {
            auto frame = FrameFactory::createFrame(rolls, index, i);
            frames.push_back(frame);
            index += frame->getAdvance();
        }
    }

    void printScores() {
        int total = 0;
        for (size_t i = 0; i < frames.size(); ++i) {
            int score = frames[i]->getScore(rolls);
            total += score;
            cout << "Frame " << (i + 1) << ": Total = " << total << endl;
        }
        cout << "Final Score: " << total << endl;
    }
};

// ------------------- Main -------------------
int main() {
    string input = "1 4 | 4 5 | 6 / | 5 / | X | 0 1 | 7 / | 6 / | X | 2 / 6";

    BowlingGame game;
    game.parseInput(input);
    game.buildFrames();
    game.printScores();

    return 0;
}
