#pragma once

#include "Context.h"


class Cell;
class Ocean;

class Object
{
private:
	friend Cell;
	friend Ocean;
protected:
	Cell *cell;
public:
	Object(Cell* cell = nullptr);

	void SetCell(Cell* cell);

	virtual void Live() = 0;
	virtual ObjType GetType() const = 0;

	virtual ~Object() {};

};

class Stone: public Object
{
private:
	ObjType type;
public:
	Stone(Cell* cell) : Object(cell) 
	{
		this->type = ObjType::STONE;
	};

	virtual void Live() override {};
	virtual ObjType GetType() const override;

	~Stone() {};
};

class Coral : public Object
{
private:
	ObjType type;
public:
	Coral(Cell * cell) : Object(cell)
	{
		this->type = ObjType::CORAL;
	}

	virtual void Live() override {};
	virtual ObjType GetType() const override;

	~Coral() {};
};