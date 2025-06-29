#ifndef SPARE_STRATEGY_HPP
#define SPARE_STRATEGY_HPP

#include "Strategy.h"

class SpareStrategy : public Strategy {
public:
    int bonus() const override;
};

#endif

