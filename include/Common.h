#pragma once

#include <iostream>
#include <ctime>
#include <list>

using namespace std;

typedef size_t coord_t;
enum class ObjType { STONE, PREY, PREDATOR, CORAL };
struct Pair
{
	coord_t x; // 0..M-1
	coord_t y; // 0..N-1
};

const size_t N = 20;
const size_t M = 50;

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

#define TRY_ 6
#define TRY_HUNT 8

#define DAYS_OF_LIFE_PREDATOR 20
#define DAYS_OF_LIFE_PREY 10
#define DAYS_OF_LIFE_CORAL 200

#define REPRODUCE_TIME_PREY 3
#define REPRODUCE_TIME_PREDATOR 6
#define REPRODUCE_TIME_CORAL 100

#define MAX_TIME_WITHOUT_FOOD 2
#define MAX_COUNT_PREY_IN_PERIOD 10

#define MAX_DAYS 500
