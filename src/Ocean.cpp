#include "Ocean.h"

Ocean::Ocean()
{
	cells = new Cell * [weidth];

	for (int x = 0; x < weidth; x++)
	{
		cells[x] = new Cell[height];
	}

	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < weidth; x++)
		{
			this->cells[x][y].crd.x = x;
			this->cells[x][y].crd.y = y;
			this->cells[x][y].ocean = this;
		}
	}
}

void Ocean::addObjects(ObjType type, int number)
{
	int ObjectX, ObjectY;

	for (int i = 0; i < number; i++)
	{
		while (true)
		{
			ObjectX = rand() % weidth;
			ObjectY = rand() % height;

			if (this->cells[ObjectX][ObjectY].getObject() == NULL)
				break;
		}

		Cell* cell = &cells[ObjectX][ObjectY];

		if (type == ObjType::STONE)
		{
			Stone* stone = new Stone(cell, type);
			cell->setObject(stone);
			this->cells[ObjectX][ObjectY] = *cell;
			this->addStuff(stone);
		}
		else if (type == ObjType::PREY)
		{
			Prey* prey = new Prey(cell, type);
			cell->setObject(prey);
			this->cells[ObjectX][ObjectY] = *cell;
			this->addStuff(prey);
		}
		else if (type == ObjType::PREDATOR)
		{
			Predator* predator = new Predator(cell, type);
			cell->setObject(predator);
			this->cells[ObjectX][ObjectY] = *cell;
			this->addStuff(predator);
		}
	}
}

void Ocean::addStuff(Object* object)
{
	this->stuff.push_front(object);
}

void Ocean::print()
{
	system("cls");
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < weidth; x++)
		{
			if (this->cells[x][y].getObject() == NULL)
				std::cout << " ";
			else
				std::cout << this->cells[x][y].getObject()->getChar();
		}
		std::cout << "|" << std::endl;
	}
	for (int i = 0; i < weidth; i++)
	{
		std::cout << "-";
	}
}

void Ocean::deleteObject(Object* object)
{
	object->getCell()->killMe();
}

Cell* Ocean::findEmpty(Cell* cell)
{
	int x = cell->getPair().x;
	int y = cell->getPair().y;
	std::vector<Cell*> neightboring;

	if (x + 1 < weidth)
		if (cells[x + 1][y].getObject() == NULL)
			neightboring.push_back(&cells[x + 1][y]);

	if (x - 1 >= 0)
		if (cells[x - 1][y].getObject() == NULL)
			neightboring.push_back(&cells[x - 1][y]);

	if (y + 1 < height)
		if (cells[x][y + 1].getObject() == NULL)
			neightboring.push_back(&cells[x][y + 1]);

	if (y - 1 >= 0)
		if (cells[x][y - 1].getObject() == NULL)
			neightboring.push_back(&cells[x][y - 1]);

	if (neightboring.size() == 0)
	{
		return nullptr;
	}
	else
	{
		int random = rand() % neightboring.size();
		return neightboring[random];
	}
}

Cell* Ocean::findPrey(Cell* cell)
{
	int x = cell->getPair().x;
	int y = cell->getPair().y;
	std::vector<Cell*> neightboring;

	if (x + 1 < weidth)
		if (cells[x + 1][y].getObject() != NULL)
			if (cells[x + 1][y].getObject()->getType() == ObjType::PREY)
				neightboring.push_back(&cells[x + 1][y]);

	if (x - 1 >= 0)
		if (cells[x - 1][y].getObject() != NULL)
			if (cells[x - 1][y].getObject()->getType() == ObjType::PREY)
				neightboring.push_back(&cells[x - 1][y]);

	if (y + 1 < height)
		if (cells[x][y + 1].getObject() != NULL)
			if (cells[x][y + 1].getObject()->getType() == ObjType::PREY)
				neightboring.push_back(&cells[x][y + 1]);

	if (y - 1 >= 0)
		if (cells[x][y - 1].getObject() != NULL)
			if (cells[x][y - 1].getObject()->getType() == ObjType::PREY)
				neightboring.push_back(&cells[x][y - 1]);

	if (neightboring.size() == 0)
	{
		return nullptr;
	}
	else
	{
		int random = rand() % neightboring.size();
		return neightboring[random];
	}
}

void Ocean::run(int times)
{
	int countOfStone = 0, countOfPrey = 0, countOfPredator = 0;
	while (times != 0)
	{
		this->print();
		std::cout << std::endl;
		std::cout << "times: " << times << " | " << "stones: " << countOfStone << " | " << "prey: " <<
			countOfPrey << " | " << "predators: " << countOfPredator << std::endl;
		countOfStone = 0;
		countOfPrey = 0;
		countOfPredator = 0;
		for (auto it = stuff.begin(); it != stuff.end(); it++)
		{
			if ((*it)->getType() == ObjType::STONE)
			{
				countOfStone++;
			}
			if ((*it)->getType() == ObjType::PREY)
			{
				countOfPrey++;
			}
			if ((*it)->getType() == ObjType::PREDATOR)
			{
				countOfPredator++;
			}

			if (!(*it)->live())
			{
				deleteObject(*it);
				if (it == --stuff.end())
				{
					stuff.erase(it);
					break;
				}
				else
					stuff.erase(it++);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		times--;
	}
}

void Ocean::run()
{
	int times = 0, countOfStone = 0, countOfPrey = 0, countOfPredator = 0;

	do
	{
		this->print();
		std::cout << std::endl;
		std::cout << "times: " << times << " | " << "stones: " << countOfStone << " | " << "prey: " <<
						countOfPrey << " | " << "predators: " << countOfPredator << std::endl;
		countOfStone = 0;
		countOfPrey = 0;
		countOfPredator = 0;
		for (auto it = stuff.begin(); it != stuff.end(); it++)
		{
			if ((*it)->getType() == ObjType::STONE)
			{
				countOfStone++;
			}
			if ((*it)->getType() == ObjType::PREY)
			{
				countOfPrey++;
			}
			if ((*it)->getType() == ObjType::PREDATOR)
			{
				countOfPredator++;
			}

			if (!(*it)->live())
			{
				deleteObject(*it);
				if (it == --stuff.end())
				{
					stuff.erase(it);
					break;
				}
				else
					stuff.erase(it++);
			}
		}
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		times++;
	} while (countOfPrey != 0 && countOfPredator != 0);
}