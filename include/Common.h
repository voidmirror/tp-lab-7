#pragma once

#include <iostream>
using namespace std;

typedef size_t coord_t;

struct Pair {
	coord_t x; // 0...rows-1
	coord_t y; // 0...cols-1
};

const size_t rows = 40;
const size_t cols = 60;

const int kPreyLifeTime = 30;
const int kPredLifeTime = 40;
const int kReproTime = 10;
const int kHungryLevel = 20;