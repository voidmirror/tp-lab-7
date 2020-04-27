//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_OBJECTCREATOR_H
#define OCEAN_OBJECTCREATOR_H

#include "Object.h"

class ObjectCreator {
public:
    virtual Object  *createObject() = 0;
};

class FishCreator: public ObjectCreator {
    Object * createObject() override;
};

class PredatorFishCreator: public ObjectCreator {
    Object * createObject() override;
};

class StoneCreator: public ObjectCreator {
    Object * createObject() override;
};


#endif //OCEAN_OBJECTCREATOR_H
