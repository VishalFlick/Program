#include "FrameFactory.h"

std::shared_ptr<Frame> FrameFactory::createFrame(const std::vector<int>& rolls, int index, int frameNum) {
    if (frameNum == 10) return std::make_shared<TenthFrame>(index);
    if (rolls[index] == 10) return std::make_shared<StrikeFrame>(index);
    if (rolls[index] + rolls[index + 1] == 10) return std::make_shared<SpareFrame>(index);
    return std::make_shared<OpenFrame>(index);
}
