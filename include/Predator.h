#ifndef PREDATOR_H
#define PREDATOR_H


#include "Prey.h"

class Predator : public Prey
{
    public:
        Predator();
        void live();
        Cell* findPreyNear();
    protected:

    private:
        int preysInside;
};

#endif // PREDATOR_H
