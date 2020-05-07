#pragma once
#include "common.h"
#include "LivingObject.h"
#include <type_traits>

class Ocean {
private:
	unsigned objCounter = 0;
	unsigned cycle = 0;
	Cell** cells;
	std::list<LivingObject*> livingStuff;
	size_t height;
	size_t width;
	Pair* findFreeRandomCoord() const;
public:
	Ocean(size_t height = N, size_t width = M);
	// probably should have sticked to the rule of five, but according to the task
	// an Ocean object is not supposed to be moved or copied, so why bother, maybe later
	~Ocean();
	template<class T>
	void addNonLivingObjects(unsigned count);
	template<class T>
	void addLivingObjects(unsigned count);
	void run();
	void print() const;
};

template<class T>
void Ocean::addNonLivingObjects(unsigned count) {
	static_assert(std::is_base_of<Object, T>::value, 
		"Only objects of a class derived from Object can be added to an Ocean object.");
	static_assert(!std::is_base_of<LivingObject, T>::value, 
		"Please use addLivingObjects<T>(unsigned) for objects of class derived from LivingObject.");

	for (unsigned i = 0; i < count; i++) {
		Pair* randomCoord = findFreeRandomCoord();
		if (randomCoord == nullptr) {
			delete randomCoord;
			return;
		}
		cells[randomCoord->x][randomCoord->y].setObject(new T(&cells[randomCoord->x][randomCoord->y]));
		objCounter++;
		delete randomCoord;
	}
}

template<class T>
void Ocean::addLivingObjects(unsigned count) {
	static_assert(std::is_base_of<LivingObject, T>::value,
		"Only objects of a class derived from LivingObject can be added to an Ocean object by this method.");

	for (unsigned i = 0; i < count; i++) {
		Pair* randomCoord = findFreeRandomCoord();
		if (randomCoord == nullptr) {
			delete randomCoord;
			return;
		}
		T* newObj = new T(&cells[randomCoord->x][randomCoord->y]);
		cells[randomCoord->x][randomCoord->y].setObject(newObj);
		// yep, this is the only reason why two almost identical functions exist
		// (didn't know how to get rid of compilation error)
		livingStuff.push_back(newObj);
		objCounter++;
		delete randomCoord;
	}
}
