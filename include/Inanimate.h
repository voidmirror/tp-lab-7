//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_INANIMATE_H
#define OCEAN_INANIMATE_H

#include "Object.h"


class Inanimate: public Object {
public:
    ~Inanimate() override;
};

class Stone: public Inanimate{

protected:
    void init() override;
    void kill() override;
    void update() override;

public:
    Stone();
    ~Stone() override;

};


#endif //OCEAN_INANIMATE_H
