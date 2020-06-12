//
// Created by Ivan Razzhivin  on 15.05.2020.
//

#ifndef UNTITLED_COMMON_H
#define UNTITLED_COMMON_H
#include <cstdlib>
typedef size_t coord_t;
struct Pair
{
    coord_t x;
    coord_t y;
    Pair(size_t _x, size_t _y){
        x = _x;
        y = _y;
    }
};

struct AliveAndHierarchy
{
    unsigned int alive = 0;
    unsigned int hierarchy = 0;
    AliveAndHierarchy() = default;
    explicit AliveAndHierarchy(unsigned int _hierarchy){
        hierarchy = _hierarchy;
    }
};

#endif 