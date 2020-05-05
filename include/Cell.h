#ifndef CELL_H
#define CELL_H

#include "common.h"
#include "Object.h"
#include "Ocean.h"

class Cell
{
    friend Ocean;
private:
    Coords crd;
    Object *object;
    Ocean *ocean;
public:
    explicit Cell(Coords p = { 0, 0 }, Ocean* oc = NULL) :
            crd(p),
            object(NULL),
            ocean(oc) {}
    void init(Coords p, Ocean* oc);
    Object* getObject();
    Ocean* getOcean();
    void setObject(Object*);
    void killMe();
    Cell* getFreeCellAround();
    Cell* getPreyAround();

};
#endif
