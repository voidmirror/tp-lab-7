#ifndef Stone_hpp
#define Stone_hpp

#include "Cell.hpp"
#include "Object.hpp"
#include "Defaults.h"
#include <stdio.h>

class Stone: public Object {
public:
    Stone(Cell* cell);
    ~Stone() = default;
    
    char getChar() override;
    bool live() override;
    
};

#endif /* Stone_hpp */
