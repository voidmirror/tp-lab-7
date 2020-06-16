#include "Cell.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"


Cell::Cell(unsigned int x, unsigned int y, Ocean *oc = nullptr)
{
    this->x = x;
    this->y = y;
    this->token = emptiness;
    this->oc = oc;
}

Cell::~Cell()
{
}

char Cell::getToken() const
{
    return this->token;
}

Object* Cell::getObject() const 
{
    return this->obj;
}

Ocean* Cell::getOcean() const
{
    return this->oc;
}

unsigned int Cell::getX() const
{
    return this->x;
}

unsigned int Cell::getY() const
{
    return this->y;
}

bool Cell::isEmpty()
{
    if (this->token == '.')
    {
        return true;
    }
    else
    {
        return false;
    }
}


void Cell::addRandomObject() 
{
    int corona = rand() % 20;
    if (8 <= corona && corona <= 11)
    {
        this->token = stone;
        this->obj = new Stone(this);
    }
    else if (12 <= corona && corona <= 18)
    {
        this->token = prey;
        this->obj = new Prey(this);
    }
    else if (19 <= corona && corona <= 19)
    {
        this->token = predator;
        this->obj = new Predator(this);
    }
}

void Cell::setObject(char token, Object* obj)
{
    this->token = token;
    this->obj = obj;
}

void Cell::clearCell()
{
    this->token = emptiness;
    this->obj = nullptr;
}
