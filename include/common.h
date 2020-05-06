#ifndef _COMMON_H_
#define _COMMON_H_
#include <cstdlib>
#include <time.h>
#include <string>
#include <iterator>
#include <algorithm>
typedef size_t coord_t;

struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

const int lifespan = 40;
const int newPreyGeneration = 10;
const int newPredatorGeneration = 20;
#endif