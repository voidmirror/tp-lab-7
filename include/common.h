#pragma once
#ifndef _COMMON_H_
#define _COMMON_H_

#include <iostream>
using namespace std;

typedef size_t coord_t;

const size_t N = 25;
const size_t M = 60;

struct Pair {
	coord_t x; // 0...M-1
	coord_t y; // 0...N-1
};

#endif