#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
using namespace std;

typedef size_t coord_t;

struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

const size_t N = 10;
const size_t M = 10;

const int life_span_stone = 100;
const int life_span_prey = 10;
const int life_span_predator = 5;

const int spawn_freq_prey = 4;
const int spawn_freq_predator = 2;

const int step_prey = 1;
const int step_predator = 1;

const int without_eat = 3;

#endif