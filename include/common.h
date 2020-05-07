#pragma once
struct pair {
	int x;
	int y;

};

const int rows = 40;
const int columns = 120;


const int preyLifetime = 20;
const int breedTimecommon = 10;
const int predatorLifeTime = 50;
const int commonfull = 30;

enum class ObjType { STONE, PREY, PREDATOR};
