#ifndef OCEAH_H
#define OCEAN_H

#include <vector>
#include <utility>
#include <list>

#include "Additional.h"

using namespace std;

class Cell;
class Object;

class Ocean {
public:
	Ocean(int n, int m, int stones, int preys, int preds);
	~Ocean();
	void print() const;
	void addObject(std::pair<int, int> crd, ObjectType type);
	void run(int epochs);
	void decPrey();
	void decPred();
	void incPrey();
	void incPred();
	void addObjects(int num, ObjectType type);
	void genesis(int stones, int preys, int preds);
	std::pair<int, int> getFreeCell();
	std::pair<int, int> getSize() const;
	bool isEmpty(std::pair<int, int> crd) const;
	Cell* getCell(std::pair<int, int> crd) const;
	void moveObject(Object* obj, std::pair<int, int> from, std::pair<int, int> to);
private:
	std::vector<std::vector<Cell*>> cells;
	std::list <Object*> objects;
	std::pair<int, int> size;
	int countPred;
	int countPrey;
};

#endif