#pragma once
typedef size_t coord_t;

#define FREE_CELL_N '.'
#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

struct Pair
{
	Pair(int x = 0, int y = 0) : x(x), y(y) {}
	coord_t x;
	coord_t y;
};

struct Move {
	Move(int x, int y) : x(x), y(y) {}
	int x;
	int y;
};


const size_t N = 20;
const size_t M = 50;
const size_t PREDATOR_LT = 6;
const size_t PREDATOR_LT_WITHOUT_EAT = 4;
const size_t PREY_LT = 8;
const size_t REPR_PERIOD = 2;