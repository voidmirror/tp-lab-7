#include "object.h"

Object::Object(Cell* _cell) {
	cell = _cell;
	live_time = 0;
};

void Object::setCell(Cell* _cell) {
	cell = _cell;
}

Cell* Object::getCell() {
	return cell;
}

int Object::getLiveTime() {
	return live_time;
}

void Object::setLiveTime(int live_time) {
	this->live_time = live_time;
}