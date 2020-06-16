#include "Context.h"
#include "Ocean.h"


Ocean::Ocean()
{
	cells = new Cell*[height];
	for (int i = 0; i < height; i++) 
	{
		cells[i] = new Cell[width];
	}

	for (size_t i = 0; i < height; i++) 
	{
		for (size_t j = 0; j < width; j++) 
		{
			cells[i][j].Init(Pair{ i,j }, this);
		}
	}

	size = 0;
}

void Ocean::Print() const
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++) 
		{
			if (cells[i][j].object == nullptr)
			{
				std::cout << '.';
				continue;
			}
			switch (cells[i][j].object->GetType())
			{
			case (ObjType::STONE):
				std::cout << STONE_N;
				break;
			case (ObjType::CORAL):
				std::cout << CORAL_N;
				break;
			case (ObjType::PREY):
				std::cout << PREY_N;
				break;
			case (ObjType::PREDATOR):
				std::cout << PREDATOR_N;
				break;
			default:
				break;
			}
		}
		std::cout << std::endl;
	}
	COORD c = { 0,0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void Ocean::AddObjects(ObjType objectType, size_t counter)
{
	size += counter;
	for (size_t i = 0; i < counter; i++)
	{
		int x = std::rand() % height;
		int y = std::rand() % width;

		Cell *currentCell = &cells[x][y];

		while (currentCell->object != nullptr)
		{
			x = std::rand() % height;
			y = std::rand() % width;

			currentCell = &cells[x][y];
		}

		switch (objectType)
		{
		case (ObjType::STONE):
		{
			Stone *stone = new Stone(currentCell);
			currentCell->SetObject(stone);
			stuff.push_back(stone);
			break;
		}	
		case (ObjType::CORAL):
		{
			Coral *coral = new Coral(currentCell);
			currentCell->SetObject(coral);
			stuff.push_back(coral);
			break;
		}
		case (ObjType::PREY):
		{
			Prey *prey = new Prey(currentCell);
			currentCell->SetObject(prey);
			stuff.push_back(prey);
			break;
		}
		case (ObjType::PREDATOR):
		{
			Predator *predator = new Predator(currentCell);
			currentCell->SetObject(predator);
			stuff.push_back(predator);
			break;
		}	
		default:
			break;
		}
	}
}

void Ocean::Run(size_t iters)
{
	for (size_t i = 0; i < iters; i++)
	{
		for (size_t i = 0; i < size; i++)
		{
			if (stuff[i]->GetType() != ObjType::CORAL && stuff[i]->GetType() != ObjType::STONE) 
			{
				Pair currentCoordinates = stuff[i]->cell->coordinates;
				size_t newX = (currentCoordinates.x + std::rand() % 3 - 1) % height;
				size_t newY = (currentCoordinates.y + std::rand() % 3 - 1) % width;

				if (cells[newX][newY].object == nullptr)
				{
					stuff[i]->cell->SelfDelete();
					cells[newX][newY].SetObject(stuff[i]);
					stuff[i]->SetCell(&cells[newX][newY]);
				}
			}
			stuff[i]->Live();
		}
		Print();
		Sleep(delay);
		if (i % 10 == 0) MonitorSimulation();
	}
}

void Ocean::RemoveFromStuff(Cell* cell)
{
	for (auto it = stuff.begin(); it != stuff.end();)
	{
		if ((*it)->cell == cell)
		{
			(*it)->cell->SelfDelete();
			delete *it;
			it = stuff.erase(it);
			size--;
		}
		else 
		{
			it++;
		}
	}
}

void Ocean::MonitorSimulation()
{
	bool preyDisappeared = true;
	bool predatorDisappeared = true;

	for (auto& entity : stuff)
	{
		if (entity->GetType() == ObjType::PREDATOR) 
		{
			predatorDisappeared = false;
		}
		else if (entity->GetType() == ObjType::PREY)
		{
			preyDisappeared = false;
		}
	}

	if (predatorDisappeared || preyDisappeared) exit(0);
}

Ocean::~Ocean() 
{
	for (int i = 0; i < height; i++) delete[] cells[i];
	delete[] cells;
	stuff.clear();
}