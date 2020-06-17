#ifndef _ROCK_H_
#define _ROCK_H_

#include "OceanObject.h"

class Rock : public OceanObject
{
private:
    static constexpr char c_marker = 'R';

public:
    Rock(Ocean *ocean, OceanCell *cell);

    virtual void Update() override;
    virtual char Draw() override;
};

#endif // _ROCK_H_
