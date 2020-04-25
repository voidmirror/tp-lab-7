#ifndef _OBJECT_H
#define _OBJECT_H


#include <iostream>
#include <vector>


class Cell;

class Object
{
protected:
    Cell* cell;
    bool alive;
public:
    Object(Cell* cell);
    ~Object();
    Cell* getCell() const;
    void setCell(Cell* cell);
	virtual void live(std::vector< std::vector<Cell*> > cells) = 0;
    void die();
    bool isAlive();
};

#endif