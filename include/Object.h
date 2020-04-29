#pragma once

#include <iostream>
#include <vector>
#include <random>

using namespace std;

#define StonePower 1000
#define PreyLife 20
#define PredatorLife 30
#define PreyRepTm 5
#define PredatorRep 30
#define PerdatorSatiety 15

enum ObjType{EMPTY, ROCK, PREY, PREDATOR};

enum ObjStat{DIED, NoCHANGES, REPROD, MOVED};

class Cell;

class Object {
protected:
	ObjType type;
	int power;
	int etnum = 0;
	Cell* cell;
public:
	virtual ObjStat live(vector<Cell*> &ngbs) = 0;
	void incDnum(int k = 1);
	Cell* getCell();
	void setCell(Cell* cl);
	int getPower();
	ObjType getObjectType();
};

class Rock : public Object {

public:
	Rock(int pwr = StonePower);
	ObjStat live(vector<Cell*> &ngbs) override;
};

class Prey : public Object {
private:
	int reptm = PreyRepTm;
	int repctr = PreyRepTm + rand() % 3 - 1;
protected:
	int livctr = PreyLife;
public:
	Prey();
	virtual ObjStat live(vector<Cell*> &ngbs) override;
};

class Predator : public Prey {
private:
	int repnum = PredatorRep;
public:
	Predator();
	ObjStat live(vector<Cell*> &ngbs) override;
};
