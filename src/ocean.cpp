#include "ocean.h"
#include "stone.h"
#include "prey.h"
#include "predator.h"
#include "windows.h"

Ocean::Ocean() {
	cells = new Cell * [N];
	for (int i = 0; i < N; i++) cells[i] = new Cell[M];
}

void Ocean::init()
{
	for(int i=0;i<N;i++) for(int j=0;j<M;j++) cells[i][j].init(Pair{ (coord_t)j, (coord_t)i }, this);
}

Ocean::~Ocean() {
	for (int i = 0; i < N; i++) delete[] cells[i];
	delete[] cells;
	for (auto obj = stuff.begin(); obj != stuff.end(); obj++) delete* obj;
}

void Ocean::print() const {
	int preyNum = 0;
	int predatorNum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			if (cells[i][j].getObject())
			{
				cout << cells[i][j].getObject()->getName();
				if (cells[i][j].getObject()->getName() == PREY_N) preyNum++;
				if (cells[i][j].getObject()->getName() == PREDATOR_N) predatorNum++;
			}
			else
			{
				cout << " ";
			}
		cout << endl;
	}
	if (preyNum == 0)
	{
		system("cls");
		cout << "Predators won" << endl;
		getchar();
		exit(0);
	}
	if (predatorNum == 0)
	{
		system("cls");
		cout << "Preys won" << endl;
		getchar();
		exit(0);
	}
}

void Ocean::addObjects(int stoneNum, int preyNum, int predatorNum) {
	while (stoneNum || preyNum || predatorNum) 
	{
		if (stoneNum)
		{
			coord_t x = rand() % M;
			coord_t y = rand() % N;
			if (!cells[y][x].getObject())
			{
				
				Object* object = new Stone(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				stoneNum--;
			}
		}
		if (preyNum)
		{
			coord_t x = rand() % M;
			coord_t y = rand() % N;
			if (!cells[y][x].getObject())
			{
				
				Object* object =  new Prey(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				preyNum--;
			}
		}
		if (predatorNum)
		{
			coord_t x = rand() % M;
			coord_t y = rand() % N;
			if (!cells[y][x].getObject())
			{
			
				Object* object =  new Predator(&cells[y][x]);
				cells[y][x].setObject(object);
				stuff.push_back(object);
				predatorNum--;
			}
		}
	}
}



void Ocean::run(int speed) {
	while (1) {
		if (stuff.size() == 0)
			break;
		for (int i = 0; i < stuff.size(); i++)
			stuff[i]->live();
		Sleep(speed);
		system("cls");
		print();
	}
}



void Ocean::addObject(Object* object) {
	stuff.push_back(object);
}

void Ocean::deleteObject(Object* object)
{
	for (auto item = stuff.begin(); item != stuff.end();item++)
	{
		if (*item == object)
		{
			(*item)->getCell()->clearCell();
			delete *item;
			stuff.erase(item);
			break;
		}
	}
}

Cell* Ocean::getFreeCell(Pair coord)
{
	vector<char> x_arr = { 0,0,1,1,1,-1,-1,-1 };
	vector <char> y_arr = { -1,1,0,1,-1,0,1,-1 };
	while(x_arr.size())
	{
		char i = rand() % x_arr.size();
		if (coord.x + x_arr[i] >= 0 && coord.x + x_arr[i] < M && coord.y + y_arr[i] >= 0 && coord.y + y_arr[i] < N)
		{
			if (cells[coord.y + y_arr[i]][coord.x + x_arr[i]].getObject()==nullptr) return &cells[coord.y + y_arr[i]][coord.x + x_arr[i]];
		}
		x_arr.erase(x_arr.begin() + i);
		y_arr.erase(y_arr.begin() + i);
	}
	return nullptr;
}


Cell* Ocean::getPreyCell(Pair coord)
{
	vector<char> x_arr = { 0,0,1,1,1,-1,-1,-1 };
	vector <char> y_arr = { -1,1,0,1,-1,0,1,-1 };
	while (x_arr.size())
	{
		char i = rand() % x_arr.size();
		if (coord.x + x_arr[i] >= 0 && coord.x + x_arr[i] < M && coord.y + y_arr[i] >= 0 && coord.y + y_arr[i] < N)
		{
			if (cells[coord.y + y_arr[i]][coord.x + x_arr[i]].getObject() != nullptr && cells[coord.y + y_arr[i]][coord.x + x_arr[i]].getObject()->getName() == PREY_N) return &cells[coord.y + y_arr[i]][coord.x + x_arr[i]];
		}
		x_arr.erase(x_arr.begin() + i);
		y_arr.erase(y_arr.begin() + i);
	}
	return nullptr;
}
