#pragma once
#include <vector>
#include <ostream>
#include "common.h"

enum class ObjType{STONE, PREY, PREDATOR};
const std::vector<char> symbols{'#', 'f', 'S'};

class Cell;
class Object
{
    friend std::ostream& operator << (std::ostream& out, const Object& obj);
protected:
    Cell* cell;
    ObjType type;
    bool isEaten;
public:
    Object(Cell*  cell = nullptr) : cell{cell} { } ;
    virtual ~Object() = default;
    void setCell(Cell* new_cell);
    virtual bool live() = 0;

    Cell* getCell() const;
    ObjType getType() const;
};
