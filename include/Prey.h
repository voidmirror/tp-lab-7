//
// Created by iddoroshenko on 26.03.2020.
//

#ifndef LAB7_PREY_H
#define LAB7_PREY_H
#include <ctime>
#include <cstdlib>
#include <vector>
#include "Object.h"
#include "Coral.h"
class Ocean;
class Prey : public Object{

protected:
    void reproduce(ObjType);
    void move();
    std::size_t liveTime;
public:
    Prey(ObjType objType = ObjType::PREY, int _liveTime = PREY_LIVE_TIME) : Object(objType), liveTime(_liveTime) {}
    ~Prey() override = default;
    void live() override;
};
#endif //LAB7_PREY_H
