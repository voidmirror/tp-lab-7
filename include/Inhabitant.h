#pragma once

#include "Object.h"
#include "Cell.h"
#include "Ocean.h"


class IInhabitant
{
public:
	virtual void Reproduce() = 0;
	virtual void Die() = 0;
};

class IPredator
{
public:
	virtual void Eat(size_t x, size_t y) = 0;
};

class Prey: public Object, public IInhabitant
{
private:
	ObjType type;
protected:
	size_t lifeTime;
	size_t reproduceTime;
public:
	Prey(Cell * cell);

	virtual void Live() override;
	virtual void Reproduce() override;
	virtual void Die() override;
	virtual ObjType GetType() const override;

	~Prey() {};
};

class Predator : public Prey, public IPredator
{
private:
	ObjType type;
protected:
	int hungerLevel;
public:
	Predator(Cell * cell);

	virtual void Live() override;
	virtual void Reproduce() override;
	virtual void Die() override;
	virtual void Eat(size_t x, size_t y) override;
	virtual ObjType GetType() const override;

	~Predator() {};
};