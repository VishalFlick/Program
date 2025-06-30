#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include "ScoreBoardFactory.h"
#include "Player.h"

std::vector<int> parseInputToRolls(const std::string& input) {
    std::vector<int> rolls;
    std::istringstream iss(input);
    std::string token;
    int previous = -1;

    while (iss >> token) {
        if (token == "|") continue;
        if (token == "X") {
            rolls.push_back(10);
            previous = -1;
        }
        else if (token == "/") {
            if (previous == -1) {
                std::cerr << "Error: Spare without previous roll." << std::endl;
                continue;
            }
            rolls.push_back(10 - previous);
            previous = -1;
        }
        else {
            try {
                int pins = std::stoi(token);
                rolls.push_back(pins);
                previous = pins;
            }
            catch (...) {
                std::cerr << "Invalid input token: " << token << std::endl;
            }
        }
    }
    return rolls;
}

int main() {
    std::string name;
    int playerId;
    std::cout << "Enter Player ID: ";
    std::cin >> playerId;
    std::cin.ignore();
    std::cout << "Enter Player Name: ";
    std::getline(std::cin, name);

    ScoreBoard* sb = ScoreBoardFactory::createScoreBoard("default");
    if (!sb) {
        std::cerr << "Failed to create ScoreBoard instance." << std::endl;
        return 1;
    }

    Player player(playerId, name, sb);

    std::string input;
    std::cout << "Enter bowling input string: ";
    std::getline(std::cin, input);

    std::vector<int> rolls = parseInputToRolls(input);
    for (int pins : rolls) {
        sb->roll(pins);
    }

    std::cout << player << std::endl;

    // Toggle: Frame-by-frame breakdown
    char verboseInput;
    std::cout << "Show frame-by-frame breakdown? (y/n): ";
    std::cin >> verboseInput;
    bool verbose = (verboseInput == 'y' || verboseInput == 'Y');

    player.getScoreBoard()->printFrameDetails(verbose);

    delete sb;
    return 0;
}
