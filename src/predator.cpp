#include "predator.h"

Predator::Predator(Cell* cell) : Prey(cell)
{
	this->cell = cell;
	this->lifetime = predatorLifetime;
	this->hungerlevel = predatorHungerlevel;
	this->reproducetime = predatorReproducetime;
}

void Predator::live()
{
	if (lifetime > 0)
	{
		if(!this->hunt()) this->move();
		if(reproducetime==0 && hungerlevel>=2) this->reproduce();
		lifetime--;
		hungerlevel--;
		reproducetime--;
	}
	else
	{
		this->suicide();
	}
}

void Predator::reproduce()
{
	reproducetime = 5;
	hungerlevel = 0;
	Cell* newcell = this->cell->getOcean()->getFreeCell(this->cell->getCoord());
	if (newcell != nullptr)
	{
		Predator* newprey = new Predator(newcell);
		newcell->setObject(newprey);
		this->cell->getOcean()->addObject(newprey);
	}
}

bool Predator::hunt()
{
	Cell* preycell = this->cell->getOcean()->getPreyCell(this->cell->getCoord());
	if (preycell != nullptr)
	{
		preycell->getOcean()->deleteObject(preycell->getObject());
		this->cell->clearCell();
		preycell->setObject(this);
		this->setCell(preycell);
		this->hungerlevel = this->hungerlevel + 3;
		return true;
	}
	else
	{
		return false;
	}
	
}

char Predator::getName()
{
	return this->name;
}