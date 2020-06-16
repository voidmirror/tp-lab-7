//
// Created by Anton Korkunov on 02/04/2020.
//

#ifndef LAB7_COMMON_H
#define LAB7_COMMON_H

#include <cstdio>

#define STONE_N "st"
#define PREY_N "pr*"
#define PREDATOR_N "PR"

typedef size_t coord_t;

struct Pair
{
    coord_t x; // 0..M-1
    coord_t y; // 0..N-1
};


//Ocean size

const size_t N = 20;
const size_t M = 20;

//Parameters for Prey

const size_t Plife = 6;
const size_t Preprod = 2;

//Parameters for Predator

const size_t PRlife = 9;
const size_t PRreprod = 3;
const size_t PRhunger=3;

#endif //LAB7_COMMON_H
