#include <iostream>
#include "Object.h"

using namespace std;

int Object::get_state() {
	return state;
}

int Object::get_hp() {
	return hp;
}

int Object::get_fertility() {
	return fertility;
}

void Object::set_state(int state) {
	this->state = state;
}

void Object::set_hp(int hp) {
	this->hp = hp;
}

void Object::set_fertility(int fertility) {
	this->fertility = fertility;
}

Object::Object()
{
	set_state(rand() % 4);
}

Object::Object(int state) {
	this->state = state;
	if (state == 0 || state == 1) {
		this->hp = 1;
	}
	if (state == 2) {
		this->hp = 4;
	}
	if (state == 3) {
		this->hp = 6;
	}
	this->fertility = 0;
}

Object::~Object()
{
}