//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#ifndef LAB7_COMMON_H
#define LAB7_COMMON_H


#include <cstdio>

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

typedef size_t coord_t;

struct Pair
{
    coord_t x;
    coord_t y;
};

const size_t N = 20;
const size_t M = 50;

const int LIFETIME_PREY = 10;
const int LIFETIME_PREDATOR = 10;
const int LIFETIME_STONE = 9999;

const int REPRODUCE_TIME_PREY = 5;
const int REPRODUCE_TIME_PREDATOR = 5;

const int TRIES_TO_FIND_SOMETHING = 5;


#endif //LAB7_COMMON_H
