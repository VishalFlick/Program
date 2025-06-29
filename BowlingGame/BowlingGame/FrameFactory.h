#ifndef FRAMEFACTORY_HPP
#define FRAMEFACTORY_HPP

#include "Frame.h"
#include <memory>
#include <vector>

class FrameFactory {
public:
    static std::shared_ptr<Frame> createFrame(const std::vector<int>& rolls, int index, int frameNum);
};

#endif
