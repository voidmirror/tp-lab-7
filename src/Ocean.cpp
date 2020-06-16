#include "Ocean.h"
#include "Stone.h"
#include "Predator.h"
#include "Prey.h"

Ocean::Ocean()
{
	cells = new Cell * [N];
	for (size_t x = 0; x < N; x++)
	{
		cells[x] = new Cell[M];
		for (size_t y = 0; y < M; y++)
			cells[x][y].init({ x, y }, this);
	}
}

Ocean::~Ocean()
{
	for (auto object : stuff)
		delete object;
	for (size_t x = 0; x < N; x++)
			delete[] cells[x];
	delete[] cells;	
}

Cell* Ocean::findEmptyCellNear(Pair crd)
{
	vector<Pair> pos_c = { {crd.x, crd.y - step_prey}, {crd.x, crd.y + step_prey}, {crd.x + step_prey, crd.y}, {crd.x - step_prey, crd.y} };
	for (Pair i : pos_c)
		if (i.x < M && i.y < N)
			if (cells[i.x][i.y].getObject() == nullptr)
				return &cells[i.x][i.y];
	return nullptr;
}

Cell* Ocean::findFoodNear(Pair crd)
{
	vector<Pair> pos_c = { {crd.x, crd.y - step_prey}, {crd.x, crd.y + step_prey}, {crd.x + step_prey, crd.y}, {crd.x - step_prey, crd.y} };
	for (Pair i : pos_c)
		if (i.x < M && i.y < N)
			if (cells[i.x][i.y].getObject() != nullptr)
				if (cells[i.x][i.y].getObject()->getSpecies() == ObjType::PREY)
					return &cells[i.x][i.y];
	return nullptr;
}

int Ocean::countPreys()
{
	int cnt = 0;
	for (auto sea_creature : stuff)
		if (sea_creature != nullptr)
			if (sea_creature->getSpecies() == ObjType::PREY)
				cnt++;
	return cnt;
}

int Ocean::countPredators()
{
	int cnt = 0;
	for (auto sea_creature : stuff)
		if (sea_creature != nullptr)
			if (sea_creature->getSpecies() == ObjType::PREDATOR)
				cnt++;
	return cnt;
}

void Ocean::print() const
{
	for (int x = 0; x < M; x++)
	{
		for (int y = 0; y < N; y++)
			if (cells[x][y].getObject() != nullptr)
				cout << cells[x][y].getObject()->getSymb();
			else
				cout << '.';
		cout << "\n";
	}
	cout << "-------------------" << endl;
}


bool Ocean::deleteObject(Object* object)
{
	if (!object->isAlive())
	{
		object->getCell()->killMe();
		return true;
	}
	return false;
}

void Ocean::run()
{
	while ((this->countPredators() != 0) && (this->countPreys() != 0))
	{
		print();
		for (auto i = stuff.begin(); i != stuff.end(); i++)
			if (deleteObject(*i))
				stuff.erase(i++);
			else
				(*i)->live();
	}
}

void Ocean::addObject(Object* object)
{
	stuff.push_back(object);
}



void Ocean::addObjects(ObjType species, int amount)
{
	int cnt = 0;
	while (cnt < amount)
	{
		int x = rand() % (N-1);
		int y = rand() % (M-1);
		if (cells[x][y].getObject() == nullptr)
		{
			Object* sea_creature = nullptr;
			switch (species)
			{
			case ObjType::PREDATOR:
				sea_creature = new Predator(&cells[x][y]);
				break;
			case ObjType::PREY:
				sea_creature = new Prey(&cells[x][y]);
				break;
			case ObjType::STONE:
				sea_creature = new Stone(&cells[x][y]);
				break;
			}
			cells[x][y].setObject(sea_creature);
			stuff.push_back(sea_creature);
			cnt++;
		}
	}

}
