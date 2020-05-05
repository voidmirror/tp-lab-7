#pragma once
#include <limits.h>
#include <iostream>
typedef size_t coord_t;

struct Pair {
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};
const size_t N = 50;
const size_t M = 100;
