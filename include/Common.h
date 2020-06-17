#pragma once

struct Pair {
	int x;
	int y;
};

const int M = 15;
const int N = 15; 

enum ObjectType { STONE = 0, PREY, PREDATOR };
enum Directions { UP, DOWN, RIGHT, LEFT, HALT};