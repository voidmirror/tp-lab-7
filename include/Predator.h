#ifndef PREDATOR_H
#define PREDATOR_H

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"
#include "common.h"
#include "Fish.h"

class Predator : public Fish
{
private:
    bool fed = false;
public:
    Predator(Cell* cell);
    bool live();
    void reproduce();
    bool eatTo();

};
#endif //PREDATOR_H
