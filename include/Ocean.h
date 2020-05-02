#pragma once
#include <vector>
#include <string>
#include "Object.h"
#include "Cell.h"

class Ocean
{
	int width;
	int height;
	std::vector<std::vector<Cell*>> field;
	std::vector<Object*> objects;
	int prey_amount;
	int predator_amount;
	int predator_capacity;
	int predator_initial_fullness;
	int predator_fullness_to_reproduce;
	int predator_fullness_by_prey;
	int prey_age_to_reproduce; 
	int prey_age_to_die; 
	int prey_chance_to_reproduce;

public:
	Ocean(int width, int height, int prey_amount, int predator_amount, int stone_chance,
		int predator_capacity, int predator_initial_fullness, int predator_fullness_to_reproduce, int predator_fullness_by_prey,
		int prey_age_to_reproduce, int prey_age_to_die, int prey_chance_to_reproduce);
	~Ocean();
	std::string get_state();
	void update();
	void run();
};

