#ifndef DEFAULT_STRATEGY_HPP
#define DEFAULT_STRATEGY_HPP

#include "Strategy.h"

class DefaultStrategy : public Strategy {
public:
    int bonus() const override;
};

#endif
