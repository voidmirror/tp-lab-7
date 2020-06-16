#include "Predator.h"
#include "Cell.h"
 
Predator::Predator(Cell* cell, ObjType type) : Prey(cell, type)
{
	this->hungry = true;
	this->setLifespan(lifeOfPredator);
	this->reproduce_timeout = reproduceTimeoutOfPredator;
	this->starvation = starvationOfPredator;

}

char Predator::getChar()
{
	return 'S';
}

bool Predator::live()
{
	if (this->lifespan == 0 || this->starvation == 0)
	{
		return false;
	}
	else
	{
		if (this->reproduce_timeout == 0 && this->hungry == false)
		{
			if (this->reproduce())
			{
				this->reproduce_timeout = reproduceTimeoutOfPrey;
				this->hungry = true;
			}
		}
		else
		{
			if (this->eat())
			{
				this->hungry = false;
				this->starvation = starvationOfPredator;
			}
			else
			{
				this->move();
				this->hungry = true;
				this->starvation--;
			}

			if (this->reproduce_timeout != 0)
				this->reproduce_timeout--;
		}
		this->lifespan--;
		return true;
	}
}

bool Predator::reproduce()
{
	Cell* newCell = this->getCell()->findEmptyCell();
	if (newCell != nullptr)
	{
		Predator* predator = new Predator(newCell, ObjType::PREDATOR);
		newCell->setObject(predator);
		newCell->getOcean()->addStuff(predator);
		return true;
	}
	return false;
}

bool Predator::eat()
{
	Cell* newCell = this->getCell()->findPreyCell();
	if (newCell != nullptr)
	{
		newCell->getObject()->setLifespan(0);
		return true;
	}
	return false;
}