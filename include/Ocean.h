#pragma once

#include "Object.h"
#include "Cell.h"
#include "Object.h"
#include "Inhabitant.h"
#include <vector>
#include <iostream>
#include <Windows.h>


class Ocean
{
private:
	friend Prey;
	friend Predator;
	Cell **cells;
	std::vector<Object*> stuff;
	size_t size;

public:
	Ocean();
	~Ocean();
	void Print() const;
	void AddObjects(ObjType objectType, size_t counter);
	void RemoveFromStuff(Cell*);
	void MonitorSimulation();
	void Run(size_t iters);
};