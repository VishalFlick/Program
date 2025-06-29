#ifndef STRATEGY_FACTORY_HPP
#define STRATEGY_FACTORY_HPP

#include "Bonus.h"
#include "Strategy.h"
#include "StrikeStrategy.h"
#include "SpareStrategy.h"
#include "DefaultStrategy.h"

class StrategyFactory {
public:
    static Strategy* getStrategy(Bonus bonusType) {
        switch (bonusType) {
        case Bonus::STRIKE:
            return new StrikeStrategy();
        case Bonus::SPARE:
            return new SpareStrategy();
        default:
            return new DefaultStrategy();
        }
    }
};

#endif
