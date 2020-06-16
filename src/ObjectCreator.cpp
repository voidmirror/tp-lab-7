//
// Created by fiskirton on 08.04.2020.
//

#include "Animate.h"
#include "Inanimate.h"
#include "ObjectCreator.h"

Object *FishCreator::createObject() {
    return new Fish();
}

Object *PredatorFishCreator::createObject() {
    return new PredatorFish();
}

Object *StoneCreator::createObject() {
    return new Stone();
}
