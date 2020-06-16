#include "Ocean.h"
#include <time.h>
#include <string>

Ocean::Ocean(int hght, int wdth) {
	h = hght;
	w = wdth;
	srand(time(0));
	cells = new Cell*[h];
	for (int i = 0; i < h; i++) {
		cells[i] = new Cell[w];
	}
}

void Ocean::addObjects() {
	Couple c;
	int a;
	Object* obj;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			a = rand() % 1000;
			c = { i, j };
			if (a < 50) {
				obj = new Rock;
				obj->setCell(&cells[i][j]);
			}
			else if (a < 55) {
				obj = new Predator;
				obj->setCell(&cells[i][j]);
				predCtr++;
			}
			else if (a < 90) {
				obj = new Prey;
				obj->setCell(&cells[i][j]);
				preyCtr++;
			}
			else {
				obj = nullptr;
			}
			if(obj != nullptr) stuff.push_back(obj);
			cells[i][j].init(c, obj);
		}
	}
}

void Ocean::printNumbers() {
	cout << "Objects: " << stuff.size() << " Prey number: " << preyCtr << " Predator number: " << predCtr << endl;
}

Couple Ocean::getNumbers() {
	return { preyCtr, predCtr };
}

void Ocean::print() {
	string str;
	for (int i = 0; i < w + 2; i++) {
		str += '#';
	}
	str += '\n';
	for (int i = 0; i < h; i++) {
		str += '#';
		for (int j = 0; j < w; j++) {
			switch (cells[i][j].getObjectType())
			{
			case ROCK:
				str += '#';
				break;
			case PREY:
				str += '*';
				break;
			case EMPTY:
				str += ' ';
				break;
			case PREDATOR:
				str += '&';
				break;
			default:
				break;
			}
		}
		str += "#\n";
	}
	for (int i = 0; i < w + 2; i++) {
		str += '#';
	}
	str +=  '\n';
	system("cls");
	cout << str;
}

void Ocean::step() {
	int size = stuff.size();
	int power;
	Object* obj;
	Couple c;
	ObjType type; ////
	ObjStat status;
	vector<Cell*> veccel;
	int i = 0;
	while(i < size) {
		c = stuff[i]->getCell()->getCouple();
		power = stuff[i]->getPower();
		type = stuff[i]->getObjectType();////
		if (type == ROCK) {
			i++;
			continue;
		}
		//top
		if (c.x > 0) {
			if (cells[c.x - 1][c.y].getObject() == nullptr || cells[c.x - 1][c.y].getObject()->getPower() < power) {
				veccel.push_back(&cells[c.x - 1][c.y]);
			}
		}
		//bot
		if (c.x < h - 1) {
			if (cells[c.x + 1][c.y].getObject() == nullptr || cells[c.x + 1][c.y].getObject()->getPower() < power) {
				veccel.push_back(&cells[c.x + 1][c.y]);
			}
		}
		//left
		if (c.y > 0) {
			if (cells[c.x][c.y - 1].getObject() == nullptr || cells[c.x][c.y - 1].getObject()->getPower() < power) {
				veccel.push_back(&cells[c.x][c.y - 1]);
			}
		}
		//right
		if (c.y < w - 1) {
			if (cells[c.x][c.y + 1].getObject() == nullptr || cells[c.x][c.y + 1].getObject()->getPower() < power) {
				veccel.push_back(&cells[c.x][c.y + 1]);
			}
		}

		switch (stuff[i]->live(veccel))
		{
		case MOVED:
			obj = veccel[1]->getObject();
			if (obj != nullptr && obj->getPower() < power) {
				stuff[i]->incDnum(FishWeight);
				for (int k = 0; k < stuff.size(); k++) {
					if (obj == stuff[k]) {
						delete stuff[k];
						stuff.erase(stuff.begin() + k);
						size--;
						preyCtr--; //optional
						if (k < i) i--;
						break;
					}
				}
			}
			veccel[0]->setObject(nullptr);
			veccel[1]->setObject(stuff[i]);
			break;
		case REPROD:
			obj = veccel[1]->getObject();
			if (obj != nullptr && obj->getPower() < power) {
				stuff[i]->incDnum(FishWeight);
				for (int k = 0; k < stuff.size(); k++) {
					if (obj == stuff[k]) {
						delete stuff[k];
						stuff.erase(stuff.begin() + k);
						size--;
						preyCtr--; //optional
						if (k < i) i--;
						break;
					}
				}
			}
			veccel[0]->setObject(nullptr);
			veccel[1]->setObject(stuff[i]);

			obj = veccel[2]->getObject();
			stuff.push_back(veccel[2]->createObj(stuff[i]->getObjectType()));
			
			if (obj != nullptr) {
				veccel[2]->getObject()->incDnum(FishWeight);
				for (int k = 0; k < stuff.size(); k++) {
					if (obj == stuff[k]) {
						delete stuff[k];
						stuff.erase(stuff.begin() + k);
						size--;
						preyCtr--; //optional
						if (k < i) i--;
						break;
					}
				}
			}
			if (type == PREY) {////
				preyCtr++;
			}
			else if (type == PREDATOR) {
				predCtr++;
			}
			break;
		case DIED:
			veccel[0]->setObject(nullptr);
			stuff.erase(stuff.begin() + i);
			i--;
			size--;
			if (type == PREY) {////
				preyCtr--;
			}
			else if (type == PREDATOR) {
				predCtr--;
			}
			break;
		default:
			break;
		}
		veccel.clear();
		i++;
	}
}

int Ocean::getObjNum() {
	return stuff.size();
}

Ocean::~Ocean() {
	int size = stuff.size();
	for (int i = 0; i < size; i++) {
		delete stuff[size - i - 1];
		stuff.pop_back();
	}
	for (int i = 0; i < h; i++) {
		delete cells[i];
	}
	delete cells;
}
