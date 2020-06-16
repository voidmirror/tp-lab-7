#pragma once //fix

#include "Common.h"

#define STONE_S '#'
#define PREY_S 'f'
#define PREDATOR_S 'S'

enum class ObjectType { STONE, PREY, PREDATOR };

class Cell;
class Ocean;

class Object {
	friend Ocean;
	friend Cell;
protected:
	unsigned int lifetime;
	bool dead;
	Cell* cell;
	ObjectType type;
public:
	Object(Cell* = nullptr); 
	virtual ~Object() {};
	void SetLifetime(unsigned int newlifetime); 
	unsigned int GetLifetime(); 
	void SetCell(Cell* newcell); 
	virtual void Live() = 0;
	virtual char GetSymbol() = 0;
	Cell* GetCell(); 
	bool IsLive(); 
	void Die(); 
	ObjectType GetType(); 
 };