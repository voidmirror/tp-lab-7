#pragma once
#ifndef _COMMON_H_
#define _COMMON_H_

#define STONE_N 's'
#define PREY_N 'f'
#define PREDATOR_N 'x'

#include <iostream>
using namespace std;



typedef size_t coord_t;

const size_t N = 30;
const size_t M = 60;

const int stones = 10;
const int preys = 10;
const int predators = 10;

const int preyLifetime = 10;
const int preyReproducetime = 5;

const int predatorLifetime = 15;
const int predatorReproducetime = 5;
const int predatorHungerlevel = 4;
const int speed = 10;

struct Pair {
	coord_t x; // 0...M-1
	coord_t y; // 0...N-1
};

#endif