#pragma once

class Object;

class Cell
{
	int x;
	int y;
	Object* object;

public:
	Cell(int x, int y);
	int get_x();
	int get_y();
	void set_object(Object* object);
	Object* get_object();
};

