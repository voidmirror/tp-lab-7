#ifndef Object_hpp
#define Object_hpp

#include <stdio.h>

enum class ObjType {STONE, PREY, PREDATOR};
class Cell;
class Ocean;

class Object
{
    friend Ocean;
    friend Cell;
protected:
    Cell* cell;
    ObjType type;
    int lifetime;
    int reprtime;
public:
    explicit Object(Cell *c);
    virtual ~Object() = default;

    Cell* getCell();
    ObjType getType();
    
    virtual char getChar() = 0;
    virtual bool live() = 0;
    virtual void move() {};
    virtual void reproduce() {};

    void setLifetime(int lifetime);

};

#endif /* Object_hpp */
