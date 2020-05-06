#pragma once
#include "Object.h"

class Stone :
        public Object
{
public:
    Stone(Coordinates Coordinates, Ocean* ocean);
    std::string getName() override;
};