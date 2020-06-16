#pragma once
#include <cstdlib>
#include <ctime>
#include<vector>
#include"Cell.h"
#include"Ocean.h"
#include"Object.h"


class Animal : public Object {
public:
	Animal(Cell *cell = nullptr) : Object(cell) {}
protected:
	int restLifetime;
};
