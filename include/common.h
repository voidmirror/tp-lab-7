#pragma once
#include <iostream>
#include <list>
#include <vector>
#include <ctime>
#include <time.h>
#include <iterator>
#include <algorithm>
#include  <string>

typedef size_t coord_t;

struct Pair
{
    size_t x; 
    size_t y; 
};

const size_t N = 15;
const size_t M = 15;
const size_t LT_Stone = 500;
const size_t LT_Prey = 15;
const size_t LT_Predator = 12;
const size_t RT_Prey = 3;
const size_t RT_Predator = 5;
const size_t Search_Attempts = 8;