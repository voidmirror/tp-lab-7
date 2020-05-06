#pragma once
#include "Common.h"
#include "Ocean.h"

class Object;

class Cell {
	friend Ocean;

private:

	Pair coordinates;
	Object* object;
	Ocean* ocean;

public:
	Cell();

	Pair getCoordinates();

	Object* getObject();

	Ocean* getOcean();

	void create(Pair coordinates, Ocean* ocean);

	void setObject(Object* object);

	void setCoordinates(Pair coordinates);

	void deleteItem();
};
