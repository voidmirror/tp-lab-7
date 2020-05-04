#ifndef CELL_H
#define CELL_H
#include <utility>

#include "Additional.h"

class Ocean;
class Object;

class Cell {
public:
	Cell();
	Cell(int x, int y, Ocean* ocean);
	Object* getObject() const;
	void setObject(Object* obj);
	Ocean* getOcean() const;
	std::pair<int, int> getCoordinates() const;
	void removeObject();
	void init(int x, int y, Ocean* ocean);
private:
	std::pair<int, int> crd;
	Object* obj;
	Ocean* ocean;
};

#endif