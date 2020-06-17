//
// Created by Илья on 001 01.05.20.
//

#ifndef TASK1_COMMON_H
#define TASK1_COMMON_H
#include <cstddef>
using std::size_t;

typedef size_t coord_t;

struct Pair
{
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};

const size_t N = 50;
const size_t M = 100;
const int PREY_DEATH = 10;  // how many iteration prey will live
const int PREY_REPRODUCE = 3;

const int PREDATOR_DEATH = 10;  // how many iteration predator will live
const int PREDATOR_REPRODUCE = 3;
const int PREDATOR_LIFE_WO_EATING = 7;
const int PREDATOR_REPRODUCE_WO_EATING = 5; // predator can't reproduce if it didn't eat for this number of iterations


#endif //TASK1_COMMON_H
