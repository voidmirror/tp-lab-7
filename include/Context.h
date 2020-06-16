#pragma once

#include <cstddef>

#define STONE_N '#'
#define CORAL_N '*'
#define PREY_N 'f'
#define PREDATOR_N 'S'

enum class ObjType { STONE, CORAL, PREY, PREDATOR };

struct Pair
{
	size_t x; // 0..height - 1
	size_t y; // 0..width - 1
};

const size_t height = 30; // rows
const size_t width = 120; // columns

const int dx[4] = { 0, 0, 1, -1};
const int dy[4] = { 1, -1, 0, 0};

const size_t delay = 100;
const size_t iters = 100;
const size_t preyCounter = 1000;
const size_t predatorsCounter = 100;
const size_t objectsCounter = 200;

const size_t lifeTimeLimit = 7;
const size_t reproduceTimeLimit = 5;
const size_t hungerLevelLimit = 5;
const int hungerLevelLimitForReproduction = 5;
const int hungerLevelChange = 1;