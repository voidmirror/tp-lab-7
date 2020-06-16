#ifndef _CELL_H
#define _CELL_H

#include "Object.h"
#include <iostream>

class Ocean;

enum tokens {emptiness = '.', stone = '#', prey = 'f', predator = 'F'};


class Cell
{
private:
    unsigned int x;
    unsigned int y;
    Object *obj;
    Ocean *oc;
    char token;
public:
    Cell(unsigned int x, unsigned int y, Ocean*);
    ~Cell();
    unsigned int getX() const;
    unsigned int getY() const;
    char getToken() const;
    Object* getObject() const;
    Ocean* getOcean() const;
    bool isEmpty();
    void addRandomObject();
    void setObject(char token,Object*);
    void clearCell();
};

#endif