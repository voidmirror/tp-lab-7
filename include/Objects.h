#pragma once
#include "Ocean.h"

class Cell;

class Object
{
protected:
	Cell* cell;
public:
	Object(Cell* cell);
	~Object();

	int getLiveTime();
	bool amIDead();
	void becomeDead();
	virtual void live();
	virtual char getIcon();

private:
	int liveTime;
	bool DeathFlag;

};

class Stone : public Object
{
public:
	Stone(Cell* cell) : Object(cell) {};
	~Stone();
	char getIcon();

private:
	const char icon = '@';

};

class Prey : public Object
{
protected: 
	int getTimeToLive();
	int getTimeToBorn();
public:
	Prey(Cell* cell, int timeToLive, int timeToBorn) :
					Object(cell) {
					this->timeToLive = timeToLive;
					this->timeToBorn = timeToBorn;
							};
	~Prey();
	void live();
	char getIcon();
private:
	void movement();
	const char icon = 'f';
	int timeToLive;
	int timeToBorn;
	bool amIDying();
	bool amIGetChild();
	void newPrey();
};

class Predator : public Prey
{
public:
	Predator(Cell* cell, int timeToLive, int timeToBorn, int hunger) : Prey(cell, timeToLive, timeToBorn) { this->hunger = hunger; };
	~Predator();
	void live();
	char getIcon();
private:
	const char icon = 'S';
	int hunger;
	bool amIDying();
	bool amIGetChild();
	void eating();
	void newPredator();
	void movement();
};

