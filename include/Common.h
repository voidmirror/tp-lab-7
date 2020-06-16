//
// Created by iddoroshenko on 26.03.2020.
//

#ifndef LAB7_COMMON_H
#define LAB7_COMMON_H

#include <cstdio>

typedef std::size_t coord_t;

struct Pair
{
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};

const std::size_t N = 10;
const std::size_t M = 25;

const std::size_t PREY_LIVE_TIME = 3;
const std::size_t PREDATOR_LIVE_TIME = 3;
const std::size_t PREDATOR_DEFAULT_HUNGRY_TIME = 0;
#endif //LAB7_COMMON_H
