#include "Stone.h"
#include "Cell.h"
#include "Object.h"

Stone::Stone(Cell *cell) : Object(cell)
{
    lifetime = STONELIFETIME;
    type = Type::STONE;
    this->symbol = "🗿";
};


bool Stone::live()
{
    if (!lifetime--)
        return false;
    return true;
}
