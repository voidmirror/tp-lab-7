#pragma once //fix
using namespace std;

#include <list> 

#include "Cell.h"
#include "Object.h"

class Ocean {
private:
	Cell** cells;
	list <Object*> stuff;
public:
	Ocean();
	~Ocean();
	void AddStuff(Object* obj);
	void AddObjects(unsigned int n, ObjectType type);
	bool DeleteStuff(Object* obj);
	void Print() const;
	void Run();
	Cell* FindEmptyCell(Pair cords);
	Cell* FindPreyCell(Pair cords);
};
