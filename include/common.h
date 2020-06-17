#pragma once
#include <iostream>
#include <list>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <ctime>
#include <time.h>

typedef unsigned int uint;
typedef size_t coord_t;

struct Pair
{
    size_t x; // 0..M-1
    size_t y; // 0..N-1
};

const size_t N = 30;
const size_t M = 30;

const uint attempts = 8;
const uint reproduce_time = 3;

const uint prey_lim = 15;
const uint predator_lim = 12;
const uint stone_lim = 500;



