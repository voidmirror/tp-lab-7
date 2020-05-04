//
// Created by sdanilov on 4/17/2020.
//

#ifndef TASK1_PRAY_H
#define TASK1_PRAY_H
#include "Fish.h"
#include "ocean.h"
#include <random>

class Prey: public Fish{
    Cell* self;
public:
	explicit Prey(Cell* current_cell) {
		self = current_cell;
		type = "prey";
	};
	void move(Ocean& ocean) override;
	void multiply(Ocean& ocean) override;
};


#endif //TASK1_PRAY_H
