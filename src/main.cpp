#include<list>
#include<iostream>
#include<windows.h>
#include"Ocean.h"
#include"Object.h"


int main() {
	Ocean oc;
	std::list<Object*> objs;
	for (int i = 0; i < 60; ++i) {
		objs.push_back(Object::createObject(ObjType::PREY));
	}
	for (int i = 0; i < 18; ++i) {
		objs.push_back(Object::createObject(ObjType::PREDATOR));
	}
	for (int i = 0; i < 200; ++i) {
		objs.push_back(Object::createObject(ObjType::STONE));
	}
	oc.addObjects(objs);
	objs.clear();
	oc.randDistribution();
	oc.print();
	for (int i = 0; i < 200; ++i) {
		Sleep(150);
		system("cls");
		oc.run();
		std::cout << std::endl;
		oc.print();
	}

	system("pause");
	return 0;
}