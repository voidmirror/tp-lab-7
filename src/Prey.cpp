#include "Prey.h"
#include "Cell.h"

Prey::Prey(Cell*cell, ObjType type) : Object(cell, type)
{
	this->setLifespan(lifeOfPrey);
	this->reproduce_timeout = reproduceTimeoutOfPrey;
}

void Prey::setLifespan(int timeOut)
{
	this->lifespan = timeOut;
}

char Prey::getChar()
{
	return 'f';
}

bool Prey::live()
{
	if (this->lifespan == 0)
	{
		return false;
	}
	else
	{
		if (this->reproduce_timeout == 0)
		{
			if (this->reproduce())
				this->reproduce_timeout = reproduceTimeoutOfPrey;
		}
		else
		{
			this->move();
			this->reproduce_timeout--;
		}
		this->lifespan--;
		return true;
	}
}

void Prey::move()
{
	Cell* newCell = this->getCell()->findEmptyCell();
	if (newCell != nullptr)
	{
		this->getCell()->setObject(NULL);
		newCell->setObject(this);

		this->setCell(newCell);
	}
}

bool Prey::reproduce()
{
	Cell* newCell = this->getCell()->findEmptyCell();
	if (newCell != nullptr)
	{
		Prey* prey = new Prey(newCell, ObjType::PREY);
		newCell->setObject(prey);
		newCell->getOcean()->addStuff(prey);
		return true;
	}
	return false;
}