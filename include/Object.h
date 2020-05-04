//
// Created by iddoroshenko on 26.03.2020.
//

#ifndef LAB7_OBJECT_H
#define LAB7_OBJECT_H
#include "Common.h"
#include "Ocean.h"
#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'P'

enum class ObjType {STONE,CORAL,PREY,PREDATOR};
class Ocean;
class Cell;
class Object
{
protected:
    Cell *cell;
    ObjType objType;
    bool _isDead;
public:
    Object(ObjType);
    virtual ~Object();
    virtual void live() = 0;
    void setCell(Cell*);
    ObjType getObjType() const;
    bool isDead() const;
    void killObj();
};
#endif //LAB7_OBJECT_H
