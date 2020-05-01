#ifndef CELL_H
#define CELL_H

#include "Common.h"
//#include "Object.h"
//#include "Ocean.h"

class Ocean;
class Object;

class Cell
{
	friend Ocean;
private:
	Pair coord;
	Object* object;
	Ocean* ocean;
public:
	explicit Cell(Pair p = { 0, 0 }, Ocean* oc = nullptr);
	~Cell();
	void init(Pair coord, Ocean* ocean);
	Object* getObject() const;
	void setObject(Object* object);
	Cell* getNeighbour(bool isPredator=false);
	Ocean* getOcean();
};

#endif // !CELL_H