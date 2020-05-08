#ifndef _CARNIVOROUSFISH_H_
#define _CARNIVOROUSFISH_H_

#include <cstdint>

#include "HerbivorousFish.h"
#include "OceanObject.h"

class CarnivorousFish : public OceanObject
{
private:
    static constexpr char c_marker = 'C';
    static constexpr int32_t c_baseFullness = 2000;
    static constexpr int32_t c_reproductionFullnessRequired = 4000;
    static constexpr int32_t c_reproductionFullnessCost = 2000;
    static constexpr int32_t c_minDeathAge = 2000;
    static constexpr int32_t c_maxDeathAge = 4000;

    int32_t m_age;
    int32_t m_deathAge;
    int32_t m_fullness;

    void EatHerbivorousFish(HerbivorousFish *herbivorousFish);

public:
    CarnivorousFish(Ocean *ocean, OceanCell *cell);

    virtual void Update() override;
    virtual char Draw() override;
};

#endif // _CARNIVOROUSFISH_H_
