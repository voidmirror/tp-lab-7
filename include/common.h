#ifndef COMMON_H
#define COMMON_H

#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <time.h>
#include <iterator>
#include <algorithm>
#include <string>
#include <random>

typedef size_t coord_t;

enum class Type {STONE,CORAL,PREY,PREDATOR};

struct Coords
{
    size_t x;
    size_t y;
};

const size_t STONELIFETIME = 500;
const size_t REPRODUCETIME = 3;
const size_t PREDATORLIFETIME = 12;
const size_t PREYLIFETIME = 15;

#endif //COMMON_H
