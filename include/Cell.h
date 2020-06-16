#pragma once

#include "Object.h"


class Prey;
class Predator;
class Ocean;

class Cell
{
private:
	friend Prey;
	friend Predator;
	friend Ocean;
	Pair coordinates;
	Object *object;
	Ocean *ocean;
public:
	explicit Cell(Pair coordinates = { 0, 0 }, Ocean* ocean = nullptr) :
		coordinates(coordinates),
		object(nullptr),
		ocean(ocean) {}

	void Init(Pair pair, Ocean* ocean);
	void SetObject(Object* object);
	void SelfDelete();
};