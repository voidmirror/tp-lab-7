#include <cassert>  
#include"Object.h"
#include"Prey.h"
#include"Predator.h"
#include"Stone.h"

void Object::setCell(Cell* cell) {
	this->cell = cell;
}


void Object::setType(ObjType type){
	this->type = type;
}


void Object::setId(int id) {
	this->id = id;
}


int Object::getId() {
	if (this==nullptr) {
		std::cout << "ERROR\n";
		return this->id;
	}
	else {
		return this->id;
	}
	
}



ObjType Object::getType() const {
	return type;
}


Object* Object::createObject(ObjType type){
	Object * newObj;
	switch (type)
	{
	case ObjType::PREY:
		newObj = new Prey();
		break;
	case ObjType::PREDATOR:
		newObj = new Predator();
		break;
	case ObjType::STONE:
		newObj = new Stone();
		break;
	default:
		newObj = nullptr;
	}
	return newObj;
}