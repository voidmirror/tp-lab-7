#ifndef TASK1_OBJECT_H
#define TASK1_OBJECT_H

#include <string>
using namespace std;
#include "ocean.h"
class Ocean;

class Object {
public:
    string type;
    virtual void live(Ocean& ocean) = 0;
};


#endif
