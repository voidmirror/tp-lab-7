//
// Created by artem on 05.04.2020.
//

#ifndef OCEANEMULATOR_CELL_H
#define OCEANEMULATOR_CELL_H

#include "Object.h"

class Ocean;

class Cell {
private:
    Ocean* ocean = nullptr;
    Object* object = nullptr;
public:
    Cell();

    void setOcean(Ocean* ocean);

    Ocean* getOcean();

    void setObject(Object* object);

    Object *getObject() const;

    char getView();


};


#endif //OCEANEMULATOR_CELL_H
