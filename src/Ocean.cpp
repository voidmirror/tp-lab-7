#include "Common.h"
#include "Object.h"
#include "Ocean.h"
#include "Cell.h"
#include <iostream>
using namespace std;
Ocean::Ocean() {
	cells = new Cell*[M];
	for (int i = 0; i < M; i++) {
		cells[i] = new Cell[N];
	}
		
	for (coord_t i = 0; i < M; i++) { //заполняем клетками
		for (coord_t j = 0; j < N; j++) {
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
			if ((cells[i][j].obj) != nullptr)
				switch ((cells[i][j].obj)->getsymbol())
				{
				case('#'):{
					cout << "#";
					break;
				}
				case('f'):{
					cout << "f";
					break;
				}
				case('S'):{
					cout << "S";
					break;
				}
				}
			else cout << " ";
		}
		cout << endl;
	}
}


void Ocean::addObjects(int num_object, ObjType type) {
	for (int i = 1; i <= num_object; i++) {

		int x = rand() % M;
		int y = rand() % N;

		if (((cells[x][y]).obj) == nullptr)
		{
			switch (type)
			{
			case ObjType::STONE: {
				Stone * _stone = new Stone(&cells[y][x]);
				cells[x][y].setObject(_stone);
				stuff.push_back(_stone);
				break;
			}
				
			case ObjType::PREY: {
				Prey * _prey = new Prey(&cells[y][x]);
				cells[x][y].setObject(_prey);
				stuff.push_back(_prey);
				break;
			}
			case ObjType::PREDATOR: {
				Predator * _predator = new Predator(&cells[y][x]);
				cells[x][y].setObject(_predator);
				stuff.push_back(_predator);
				break;
			}
				
			}
		}
	}
}

void Ocean::move() {
	for (Object* obj : stuff)
	{
		if ((obj->type) != ObjType::STONE)
		{ 
			
			int new_x = ((obj->getObject())->cell)->crd.x + rand() % 3 - 1;  //перемещение
			int new_y = ((obj->getObject())->cell)->crd.y + rand() % 3 - 1;
			if (((new_x) < M)&&((new_x) >= 0) && ((new_y) < N)&&((new_x) >= 0) && (cells[new_x][new_y].obj == nullptr)) 
			{
				obj->cell->killMe();// убиваем на предидушей клетке
				obj->setCell(&cells[new_x][new_y]); // вставляем на новую
				cells[new_x][new_y].setObject(obj);
			}
			obj->live();
		}

	}
}

void Ocean::eat() {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			if (((cells[i][j].obj) != nullptr) && ((cells[i][j].obj->type) == ObjType::PREDATOR))
			{
				if (((i + 1) < M) && (cells[i + 1][j].obj != nullptr) && (cells[i + 1][j].obj->type == ObjType::PREY))
				{
					cells[i + 1][j].obj->lifetime = lifespan;

				}
				if (((i - 1) >= 0) && (cells[i - 1][j].obj != nullptr) && (cells[i - 1][j].obj->type == ObjType::PREY))
				{
					cells[i - 1][j].obj->lifetime = lifespan;

				}
				if (((j + 1) < N) && (cells[i][j + 1].obj != nullptr) && (cells[i][j + 1].obj->type == ObjType::PREY))
				{
					cells[i][j + 1].obj->lifetime = lifespan;

				}
				if (((j - 1) >= 0) && (cells[i][j - 1].obj != nullptr) && (cells[i][j - 1].obj->type == ObjType::PREY))
				{
					cells[i][j - 1].obj->lifetime = lifespan;

				}
			}
		}
	}
}

void Ocean::die() {
	for (auto it = stuff.begin(); it != stuff.end();)
	{
		if (((*it)->lifetime)>=lifespan)
		{
			(*it)->cell->killMe();
			delete *it;
			it = stuff.erase(it);
		}
		else ++it;
	}
}

void Ocean::reproduce() {
	for (auto it = stuff.begin(); it != stuff.end(); it++)
	{
		if (((*it)->lifetime) == newPreyGeneration)
		{
			if ((*it)->type == ObjType::PREY)
			{
				int x = rand() % M;
				int y = rand() % N;
				Prey* _prey = new Prey(&cells[x][y]);
				cells[x][y].setObject(_prey);
				stuff.push_back(_prey);
			}
		}
		if (((*it)->lifetime) == newPredatorGeneration) {
			if ((*it)->type == ObjType::PREDATOR)
			{
				int x = rand() % M;
				int y = rand() % N;
				Predator* _predator = new Predator(&cells[x][y]);
				cells[x][y].setObject(_predator);
				stuff.push_back(_predator);
			}
		}
	}
}