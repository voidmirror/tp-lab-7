#include "prey.h"

Prey::Prey(Cell* cell) :Object(cell)
{
	this->cell = cell;
	this->lifetime = preyLifetime;
	this->reproducetime = preyReproducetime;
}

void Prey::live()
{
	if (lifetime > 0)
	{
		this->move();
		if(reproducetime==0) this->reproduce();
		lifetime--;
		reproducetime--;
	}
	else
	{
		this->suicide();
	}
}

void Prey::move()
{
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr)
	{
		newcell->setObject(this);
		this->cell->clearCell();
		this->setCell(newcell);
		
	}
}

void Prey::reproduce()
{
	reproducetime = 2;
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr)
	{
		Prey* newprey = new Prey(newcell);
		newcell->setObject(newprey);
		this->cell->getOcean()->addObject(newprey);
	}
}

char Prey::getName()
{
	return this->name;
}

void Prey::suicide()
{
	this->cell->getOcean()->deleteObject(this);
}

