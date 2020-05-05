//
// Created by Оксана on 04.05.2020.
//

#ifndef TASK1_CELL_H
#define TASK1_CELL_H

#include "common.h"
//#include "object.h"
//#include "ocean.h"

class Ocean;
class Object;


class Cell
{
    friend Ocean;
private:
    Pair coordinates; //координаты на ячейку
    Object* object{}; //ссылка на объект
    Ocean* ocean; //ссылка на океан, в котором она находится
public:
    explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
    ~Cell();
    void init(Pair coordinates, Ocean* ocean);
    Object* getObject() const;
    Pair getCoordinates() const;
    void setObject(Object* object);
    Cell* findEmptyCellNear() const;
    Cell* findPredatorNear() const;
    Cell* findPreyNear() const;
    Ocean* getOcean() const;
    //getInformCell();

    /*explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr) :
            crd(p),
            obj(nullptr),
            ocean(oc) {}*/

};

#endif //TASK1_CELL_H
