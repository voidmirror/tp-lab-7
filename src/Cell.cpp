#include "Common.h"
#include "Ocean.h"
#include "Cell.h"
using namespace std;

class Object;
class Ocean;

Cell::Cell()
{
	crd = { 0, 0 };
	ocean = nullptr;
}

void Cell::init(Pair p, Ocean* oc)
{
	crd = p;
	ocean = oc;
	obj = nullptr;
}

Object* Cell::getObject()
{
	return obj;
}

void Cell::setObject(Object* NewObj)
{
	obj = NewObj;
}

void Cell::killMe()
{
	obj = nullptr;
}