#include "Ocean.h"
#include <vector>

Ocean::Ocean(int n, int m)
{
	iteration = 0;
	amount = 0;
	predatorsAmount = 0;
	preysAmount = 0;
	this->m = m;
	this->n = n;
	matrix = new Cell* [m * n];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			Cordinate cord = { i,j };
			matrix[i * m + j] = new Cell(this,cord);
		}

	}
}

Ocean::~Ocean()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{	
			delete matrix[i * m + j];
		}

	}
	delete[] matrix;
}

void Ocean::init(int preys, int predators, int stones)
{
//	amount = preys + predators + stones;
//	predatorsAmount = predators;
//	preysAmount = preys;
	while ((preys > 0) || (predators > 0) || (stones > 0))
	{
		if (preys > 0)
		{
			preys--;
			Cell* buf = findRandEmpty();
			Prey* bufPrey = new Prey(buf, TIME_TO_LIVE_PREY, TIME_TO_BORN_PREY);
			buf->addObject(bufPrey);
			
		}
		if (predators > 0)
		{
			predators--;
			Cell* buf = findRandEmpty();
			Predator* bufPredator = new Predator(buf, TIME_TO_LIVE_PREDATOR, TIME_TO_BORN_PREDATOR, 4);
			buf->addObject(bufPredator);
		}
		if (stones > 0)
		{
			stones--;
			Cell* buf = findRandEmpty();
			Stone* bufStone = new Stone(buf);
			buf->addObject(bufStone);
		}
	}
}

void Ocean::startSimulation()
{
	if (amount < 1)
	{
		cout << "U should init first" << endl;
		return;
	}
	while (true)
	{

		nextIteration();
		cout << "iteration: ";
		cout << iteration << endl;
		print();
		if ((preysAmount == 0) || (predatorsAmount == 0))
		{
			cout << "END OF SIMULATION" << endl;
			return;
		}
		cout << "\n\n Continue? Y|n" << endl;
		char answ;
		cin >> answ;
		if ((answ == 'n') || (answ == 'N')) break;
	}
}

void Ocean::startSimulation(int nIterations)
{
	if (amount < 1)
	{
		cout << "U should init first" << endl;
		return;
	}
	while (iteration < nIterations)
	{

		nextIteration();
		cout << "iteration: ";
		cout << iteration << endl;
		print();
		if ((preysAmount == 0) || (predatorsAmount == 0))
		{
			cout << "END OF SIMULATION" << endl;
			return;
		}
	}
}

void Ocean::print() const
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[i * m + j]->objIcon();
		}
		cout << endl;
	}
	cout << endl;
}

void Ocean::addObject(Object* object, Cordinate cord)
{
	matrix[cord.i * m + cord.j]->addObject(object);
	objects.push_back(object);
}

Cell* Ocean::getCell(Cordinate cord)
{
	if (checkCord(cord)) return matrix[cord.i * m + cord.j];
	return nullptr;
}

void Ocean::addToList(Object* obj)
{
	amount++;
	char flag = obj->getIcon();
	switch (flag)
	{
	case 'S': predatorsAmount++;
		break;
	case 'f': preysAmount++;
		break;
	default:
		break;
	}
	objects.push_back(obj);
}

void Ocean::deleteFromList(Object* obj)
{
	char flag = obj->getIcon();
	amount--;
	switch (flag)
	{
	case 'S': predatorsAmount--;
		break;
	case 'f': preysAmount--;
		break;
	default:
		break;
	}
	//objects.remove(obj);
	objToDelete.push_back(obj);
}

bool Ocean::checkCord(Cordinate cord)
{
	if (cord.i >= 0 && cord.j >= 0) {
		if (cord.i < n && cord.j < m) {
			return true;
		}
	}
	return false;
}

Cell* Ocean::findRandEmpty()
{
	Cordinate cord = { rand() % n, rand() % m };
	Cell* res = getCell(cord);
	while (!res->isEmpty())
	{
		if (cord.i == n && cord.j == m)
		{
			cord = { 0, 0 };
		}
		if (cord.j < m - 1 ) cord.j++;
		else
		{
			cord.j = 0;
			cord.i++;
		}
		res = getCell(cord);
	}
	return res;
}

void Ocean::nextIteration()
{
	iteration++;
	for (Object* obj : objects) {
		if (!obj->amIDead()) obj->live();
	}
	while (!objToDelete.empty()) {
		Object* buf = objToDelete.front();
		objects.remove(buf);
		objToDelete.remove(buf);
		delete buf;
	}
}


//________________________________________________________________________


Cell::Cell(Ocean* ocean, Cordinate cord)
{
	this->cord = cord;
	this->ocean = ocean;
	object = nullptr;
}

Cell::~Cell()
{
	if (!isEmpty()) {
		delete object;
	}
}

void Cell::killObject()
{
	ocean->deleteFromList(object);
	//delete object;
	object->becomeDead();
	object = nullptr;
}

void Cell::addObject(Object* object)
{
	if (isEmpty()) {
		this->object = object;
		if (object->getLiveTime() == 0) ocean->addToList(object);
	}
}

bool Cell::isEmpty()
{
	if (object == nullptr) return true;
	return false;
}

//bool Cell::Empty(Cell* cell)
//{
//	if (cell->isEmpty()) return true;
//	return false;
//}
//
//
//bool Cell::Prey(Cell* cell)
//{
//	if (cell->object->getIcon() == 'f') return true;
//	return false;
//}
//
//bool Cell::NotPredator(Cell* cell)
//{
//	if (cell->object->getIcon() != 'S') return true;
//	return false;
//}

Cell* Cell::findNear(bool condition(Cell*))
{
	Cordinate cords[4] = { {cord.i, cord.j - 1}, {cord.i, cord.j + 1}, {cord.i - 1, cord.j},{cord.i + 1, cord.j} };
	vector<Cell*> cells;
	cells.clear();
	for (int i = 0; i < 4; i++)
	{
		Cell* temp = ocean->getCell(cords[i]);
		if ((temp != nullptr) && (temp->objIcon() != '@') && (condition(temp))) {
			cells.push_back(temp);
		}
	}
	int size = cells.size();
	if (size > 1) {
		return cells.at(rand() % size);
	}
	if (size == 1) return cells.at(0);
	return nullptr;
}

void Cell::fishSwimAway()
{
	object = nullptr;
}

char Cell::objIcon()
{
	if (isEmpty()) return '.';
	return object->getIcon();
}


