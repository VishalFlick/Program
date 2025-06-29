#include "Frame.h"

Frame::Frame(int idx) : index(idx) {}

StrikeFrame::StrikeFrame(int idx) : Frame(idx) {}

int StrikeFrame::getScore(const std::vector<int>& rolls) {
    return 10 + rolls[index + 1] + rolls[index + 2];
}
int StrikeFrame::getAdvance() { return 1; }

SpareFrame::SpareFrame(int idx) : Frame(idx) {}

int SpareFrame::getScore(const std::vector<int>& rolls) {
    return 10 + rolls[index + 2];
}
int SpareFrame::getAdvance() { return 2; }

OpenFrame::OpenFrame(int idx) : Frame(idx) {}

int OpenFrame::getScore(const std::vector<int>& rolls) {
    return rolls[index] + rolls[index + 1];
}
int OpenFrame::getAdvance() { return 2; }

TenthFrame::TenthFrame(int idx) : Frame(idx) {}

int TenthFrame::getScore(const std::vector<int>& rolls) {
    return rolls[index] + rolls[index + 1] + ((index + 2 < rolls.size()) ? rolls[index + 2] : 0);
}
int TenthFrame::getAdvance() { return 3; }
