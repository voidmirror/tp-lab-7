#include "Ocean.h"
#include "OceanCell.h"
#include "OceanObject.h"
#include "OceanObjectType.h"
#include "Rock.h"

Rock::Rock(Ocean *ocean, OceanCell *cell)
    : OceanObject(OceanObjectType::Rock, ocean, cell)
{
}

void Rock::Update()
{
}
char Rock::Draw()
{
    return c_marker;
}
