#include "Common.h"
#include "Object.h"
#include "Ocean.h"
#include "Cell.h" 
#include <iostream>
#include <vector>
using namespace std;


Ocean::Ocean()
{
	cells = new Cell * [M];
	for (int i = 0; i < M; i++)
	{
		cells[i] = new Cell[N];
	}
	for (size_t i = 0; i < M; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			cells[i][j].init(Pair{ i,j }, this);
		}
	}
}

Ocean::~Ocean() {
	for (int i = 0; i < M; i++)
		delete[] cells[i];
	delete[] cells;
	stuff.clear();
}

void Ocean::print()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((cells[i][j].object) != nullptr) 
			{
				if (cells[i][j].getObject()->gettype() == ObjectType::PREY) {
					cout << PREY_N;
				}
				if (cells[i][j].getObject()->gettype() == ObjectType::STONE) {
					cout << STONE_N;
				}
				if (cells[i][j].getObject()->gettype() == ObjectType::PREDATOR) {
					cout << PREDATOR_N;
				}
			}
			else
			{
				cout << "-";
				continue; 
			}
		}
		cout << endl;
	}
}


void Ocean::addObjects(int counter, ObjectType objectType)
{
	for (int i = 0; i < counter; i++)
	{
		
		int x = rand() % M;
		int y = rand() % N;
		Cell* thisCell = &cells[x][y];

		while (thisCell->object != nullptr)
		{
			x = rand() % M;
			y = rand() % N;
			if ((x >= 0) && (y >= 0) && (y < N) && (x < M))
			{
				thisCell = &cells[x][y];
			}
		}

		switch (objectType)
		{
		case (ObjectType::STONE):
		{
			Stone* object = new Stone(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		case (ObjectType::PREY):
		{
			Prey* object = new Prey(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		case (ObjectType::PREDATOR):
		{
			Predator* object = new Predator(thisCell);
			thisCell->setObject(object);
			stuff.push_back(object);
			break;
		}
		default:
			break;
		}
	}
}

void Ocean::setstuff(Object* object)
{
	stuff.push_back(object);
}

void Ocean::run()
{
	for (auto i = 0; i < stuff.size(); i++)
	{
		if (stuff[i]->live()==false)
		{
			deleteObject(stuff[i]->getObject());
			stuff.erase(stuff.begin()+i);
		}
	}

}


Cell* Ocean::Empty(Pair crd) {
	vector<int> v{ 1, 2, 3, 4, 5, 6, 7, };
	while (v.size() != 0) {
		int i = rand() % v.size();
		int value = v[i];
		v.erase(v.begin() + i);
		int x = 0;
		int y = 0;
		switch (value){
		case 1:
			if ((crd.x >= 1) && (crd.y >= 1))
				if (cells[crd.x - 1][crd.y - 1].getObject() == nullptr)
					return &cells[crd.x - 1][crd.y - 1];
			break;
		case 2:
			if (crd.y >= 1)
				if (cells[crd.x][crd.y - 1].getObject() == nullptr)
					return &cells[crd.x][crd.y - 1];
			break;
		case 3:
			if ((crd.y < (M+1)) && (crd.y >= 1))
				if (cells[crd.y - 1][crd.y - 1].getObject() == nullptr)
					return &cells[crd.y - 1][crd.y - 1];
			break;
		case 4:
			if (crd.x < (M-1))
				if (cells[crd.x + 1][crd.y].getObject() == nullptr)
					return &cells[crd.x + 1][crd.y];
			break;
		case 5:
			if ((crd.x < (M-1)) && (crd.y < (N-1)))
				if (cells[crd.x + 1][crd.y + 1].getObject() == nullptr)
					return &cells[crd.x + 1][crd.y + 1];
			break;
		case 6:
			if (crd.y < (N-1))
				if (cells[crd.x][crd.y + 1].getObject() == nullptr)
					return &cells[crd.x][crd.y + 1];
			break;
		case 7:
			if ((crd.x >= 1) && (crd.y < (N-1)))
				if (cells[crd.x - 1][crd.y + 1].getObject() == nullptr)
					return &cells[crd.x - 1][crd.y + 1];
			break;
		case 8:
			if (crd.x >= 1)
				if (cells[crd.x - 1][crd.y].getObject() == nullptr)
					return &cells[crd.x - 1][crd.y];
			break;
		default:
			return nullptr;
		}
	}
}


Cell* Ocean::Prey1(Pair crd) {
	vector<int> vctims;
	for (size_t i = 1; i <= 8; i++) {
		int x = 0;
		int y = 0;
		switch (i) {
		case 1:
			
			if ((crd.x >= 1) && (crd.y >= 1))
				if (cells[crd.x - 1][crd.y - 1].getObject())
					if (cells[crd.x - 1][crd.y - 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x - 1][crd.y - 1];
			break;
		case 2:
			if (crd.y >= 1)
				if (cells[crd.x][crd.y - 1].getObject())
					if (cells[crd.x][crd.y - 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x][crd.y - 1];
			break;
		case 3:
			if ((crd.y < (M + 1)) && (crd.y >= 1))
				if (cells[crd.y - 1][crd.y - 1].getObject())
					if (cells[crd.y - 1][crd.y - 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.y - 1][crd.y - 1];
			break;
		case 4:
			if (crd.x < (M - 1))
				if (cells[crd.x + 1][crd.y].getObject())
					if (cells[crd.x + 1][crd.y].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x + 1][crd.y];
			break;
		case 5:
			if ((crd.x < (M - 1)) && (crd.y < (N - 1)))
				if (cells[crd.x + 1][crd.y + 1].getObject())
					if (cells[crd.x + 1][crd.y + 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x + 1][crd.y + 1];
			break;
		case 6:
			if (crd.y < (N - 1))
				if (cells[crd.x][crd.y + 1].getObject())
					if (cells[crd.x][crd.y + 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x][crd.y + 1];
			break;
		case 7:
			if ((crd.x >= 1) && (crd.y < (N - 1)))
				if (cells[crd.x - 1][crd.y + 1].getObject())
					if (cells[crd.x - 1][crd.y + 1].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x - 1][crd.y + 1];
			break;
		case 8:
			if (crd.x >= 1)
				if (cells[crd.x - 1][crd.y].getObject())
					if (cells[crd.x - 1][crd.y].getObject()->gettype() == ObjectType::PREY)
						return &cells[crd.x - 1][crd.y];						
			break;
		}
	}
}

void Ocean::deleteObject(Object* object)
{
	object->getCell()->killMe();
}


