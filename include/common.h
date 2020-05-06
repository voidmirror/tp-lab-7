#pragma once
#include <cstddef>

typedef size_t coord_t;

struct Pair
{
    coord_t row;
    coord_t col;
};

const size_t N = 20;
const size_t M = 20;

const size_t PREY_MAX_AGE = 10;
const size_t PREY_SPAWN_TIME = 2;

const size_t PREDATOR_MAX_AGE = 10;
const size_t PREDATOR_MAX_STARVING_TIME = 5;
const size_t PREDATOR_MIN_HUNGER_TIME = 0;
const size_t PREDATOR_SPAWN_TIME = 1;

