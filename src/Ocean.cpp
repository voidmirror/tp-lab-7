#include <iostream>
#include <sstream>
#include <fstream>
#include <utility>
//#include <windows.h>
#include "Ocean.h"
#include "Fishes.h"

vector<string> split(const string& s, char delimiter)
{
	vector<string> words;
	string word;
	istringstream wordStream(s);
	while (getline(wordStream, word, delimiter))
		words.push_back(word);
	return words;
}

Ocean::Ocean() 
{
	Pair tmp;
	cells.resize(N);
	for (size_t i = 0; i < 3; i++)
		counter[i] = 0;
	for (size_t i = 0; i < N; i++)
	{
		cells[i].resize(M);
		for (size_t j = 0; j < M; j++)
		{
			tmp.x = i;
			tmp.y = j;
			cells[i][j] = new Cell;
			cells[i][j]->init(tmp, this);
		}
	}
	
	ifstream fin("objects.txt");
	string buf;
	vector<string> words;
	while (getline(fin, buf))
	{
		words = split(buf, ' ');
		tmp.x = stoi(words[1]);
		tmp.y = stoi(words[2]);
		if (words[0] == "Stone")
			addObject(tmp, STONE);
		if (words[0] == "Prey")
			addObject(tmp, PREY);
		if (words[0] == "Predator") 
			addObject(tmp, PREDATOR);
	}
	cout << "Ocean completely generated" << endl;
}

Pair Ocean::findParamByPos(Pair pos, string param) const
{
	Pair crd;
	Pair Near[8] = { {pos.x, pos.y + 1}, {pos.x ,pos.y - 1},
					{pos.x + 1,pos.y}, {pos.x + 1,pos.y + 1}, {pos.x + 1,pos.y + 1},
					{pos.x - 1,pos.y }, {pos.x - 1,pos.y + 1}, {pos.x - 1,pos.y - 1} };
	for (auto delta : Near)
	{
		if ((delta.x < N) && (delta.x >= 0) && (delta.y < M) && (delta.y >= 0))
		{
			if (param == "Prey") {
				if (cells[delta.x][delta.y]->getObject() != nullptr)
					if (cells[delta.x][delta.y]->getObject()->getType() == PREY)
						return delta;
			}
			else if (param == "Free") {
				if (cells[delta.x][delta.y]->getObject() == nullptr)
					return delta;
			}
		}
	}
	return { 0, 0 };
}

Cell* Ocean::getCellbyPos(Pair pos)
{
	return cells[pos.x][pos.y];
}

void Ocean::addObject(Pair pos, ObjType type)
{
	Cell* freeCell = getCellbyPos(pos);
	//Object* ob = nullptr;
	switch (type)
	{
	case(STONE):
		objects.push_back(new Stone(freeCell));
		counter[0]++;
		break;
		//ob = new Stone(freeCell);
	case(PREY):
		objects.push_back(new Prey(freeCell));
		counter[1]++;
		break;
	case(PREDATOR):
		objects.push_back(new Predator(freeCell));
		counter[2]++;
		break;
	}
	freeCell->setObject(objects.back());
}

void Ocean::deleteObject(Pair pos)
{
	Object* toDel = cells[pos.x][pos.y]->getObject();
	size_t  it = 0;
	ObjType type = toDel->getType();
	switch (type)
	{
	case(STONE):
		counter[0]--;
		break;
	case(PREY):
		counter[1]--;
		break;
	case(PREDATOR):
		counter[2]--;
		break;
	}
	for (auto x : objects)
	{
		if (x == toDel)
			objects.erase(objects.begin() + it);
		else it++;
	}
	delete toDel;
	cells[pos.x][pos.y]->setObject(nullptr);
}

void Ocean::print() const
{
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			Object* tmp = cells[i][j]->obj;
			if (tmp == nullptr)
				cout << '.';
			else if (tmp->getType() == STONE)
				cout << '*';
			else if (tmp->getType() == PREY)
				cout << 'f';
			else if (tmp->getType() == PREDATOR)
				cout << 'S';
		}
		cout << endl;
	}
	cout << "Stones: " << counter[0] << endl;
	cout << "Preys: " << counter[1] << endl;
	cout << "Predators: " << counter[2] << endl;
}

bool Ocean::isDying() const
{
	if ((counter[1] * 4) < counter[2])
		return true;
	if (counter[1] > (counter[2] * 5))
		return true;
	return false;
}

void Ocean::run(size_t iter)
{
	for (size_t k = 0; k < iter; k++)
	{
		for (size_t i = 0; i < objects.size();i++)
		{
			objects[i]->live();
		}
		system("cls");
		print();
		if (this->isDying()) {
			cout << "Ocean became extinct" << endl;
			k = iter;
		}
	//	Sleep(500);
	}
	
}

Ocean::~Ocean()
{
	for (auto toDel : objects) {
		delete toDel;
	}
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < M; j++)
		{
			if (cells[i][j]->getObject() != nullptr)
				delete cells[i][j]->getObject();
			delete cells[i][j];
		}
	}
	cout << "Ocean completely deleted" << endl;
}