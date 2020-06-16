#include "Fish.h"

Fish::Fish(unsigned int mintime, Cell* cell = nullptr):
    Object(cell)
{
    this->maxlivetime = mintime + rand() % 5;
    this->livetime = 0;
}

Fish::~Fish()
{
}
