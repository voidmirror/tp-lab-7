#pragma once //fix

typedef size_t coord_t;

const size_t N = 50;
const  size_t M = 50;

struct Pair{
	int x; // 0..M-1
	int	y; // 0..N-1
};

const int PreyLifeTime = 30;
const int PredatorLifeTime = 20;
const int StoneLifeTime = 10000;