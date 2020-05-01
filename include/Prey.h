#ifndef PREY_H
#define PREY_H

#include "Object.h"
#include "Ocean.h"
#include "Cell.h"

class Prey : public Object
{
    public:
        Prey();
        void live();
        Cell* getFreeNearSpot();
        int getAge(){return this->age;};
    protected:

    private:
};

#endif // PREY_H
