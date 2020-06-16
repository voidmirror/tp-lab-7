#ifndef _COMMON_H_
#define _COMMON_H_

#define STONE_TILE 's'
#define PREY_TILE 'f'
#define PREDATOR_TILE 'x'

#include <iostream>

const size_t N = 30;
const size_t M = 60;

const int stones = 20;
const int preys = 15;
const int predators = 10;

const int preyLifetime = 5;
const int preyReproducetime = 5;

const int predatorLifetime = 15;
const int predatorReproducetime = 5;
const int predatorHungerLevel = 5;
const int speed = 15;

struct Pair {
	size_t x;
	size_t y;
};

#endif 