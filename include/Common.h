#pragma once

struct Pair {
	int x;
	int y;
};

const int M = 14;
const int N = 30; 

enum ObjType { STONE = 0, PREY, PREDATOR };
enum Directions { UP, DOWN, RIGHT, LEFT, HALT};