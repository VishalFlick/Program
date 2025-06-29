#ifndef FRAME_H
#define FRAME_H

#include <vector>

class Frame {
protected:
    int index;
public:
    Frame(int idx);
    virtual int getScore(const std::vector<int>& rolls) = 0;
    virtual int getAdvance() = 0;
    virtual ~Frame() = default;
};

class StrikeFrame : public Frame {
public:
    StrikeFrame(int idx);
    int getScore(const std::vector<int>& rolls) override;
    int getAdvance() override;
};

class SpareFrame : public Frame {
public:
    SpareFrame(int idx);
    int getScore(const std::vector<int>& rolls) override;
    int getAdvance() override;
};

class OpenFrame : public Frame {
public:
    OpenFrame(int idx);
    int getScore(const std::vector<int>& rolls) override;
    int getAdvance() override;
};

class TenthFrame : public Frame {
public:
    TenthFrame(int idx);
    int getScore(const std::vector<int>& rolls) override;
    int getAdvance() override;
};

#endif
