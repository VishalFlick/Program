#ifndef STRATEGY_H
#define STRATEGY_H

class Strategy {
public:
    virtual int bonus() const = 0;
    virtual ~Strategy() = default;
};

#endif