#pragma once

struct Pair{
	int x; // 0..M-1
	int y; // 0..N-1
};

const int N = 8;
const int M = 8;

enum Dir {LEFT, RIGHT, UP, DOWN};

const int lifetime_prey_base = 30;
const int dividetime_prey_base = 10;
const int lifetime_predator_base = 50;
const int stomach_predator_cap = 5;
const int hunger_predator_cap = 10;