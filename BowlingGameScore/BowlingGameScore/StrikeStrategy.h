#ifndef STRIKE_STRATEGY_HPP
#define STRIKE_STRATEGY_HPP

#include "Strategy.h"

class StrikeStrategy : public Strategy {
public:
    int bonus() const override;
};

#endif