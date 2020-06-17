#include "HerbivorousFish.h"
#include "Ocean.h"
#include "OceanCell.h"
#include "OceanObject.h"
#include "OceanObjectType.h"
#include "Random.h"
#include "Seaweed.h"

HerbivorousFish::HerbivorousFish(Ocean *ocean, OceanCell *cell)
    : OceanObject(OceanObjectType::HerbivorousFish, ocean, cell)
{
    m_age = 0;
    m_deathAge = Random::GetRandomInt32(c_minDeathAge, c_maxDeathAge);
    m_fullness = c_baseFullness;
}

void HerbivorousFish::EatSeaweed(Seaweed *seaweed)
{
    Ocean *ocean = GetOcean();
    ocean->Despawn(seaweed);
    ocean->Move(seaweed->GetCell(), this);
    m_fullness += 10;
}

void HerbivorousFish::Update()
{
    if (IsDestroyed())
        return;

    m_age++;
    m_fullness--;

    Ocean *ocean = GetOcean();
    OceanCell *containingCell = GetCell();
    if (m_fullness >= c_reproductionFullnessRequired)
    {
        bool reproduced = false;
        if (!reproduced && !containingCell->IsMostNorthernCell() && !containingCell->GetCellOnNorth()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnNorth(), new HerbivorousFish(ocean, nullptr)), reproduced = true;
        if (!reproduced && !containingCell->IsMostSouthernCell() && !containingCell->GetCellOnSouth()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnSouth(), new HerbivorousFish(ocean, nullptr)), reproduced = true;
        if (!reproduced && !containingCell->IsMostWesternCell() && !containingCell->GetCellOnWest()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnWest(), new HerbivorousFish(ocean, nullptr)), reproduced = true;
        if (!reproduced && !containingCell->IsMostEasternCell() && !containingCell->GetCellOnEast()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnEast(), new HerbivorousFish(ocean, nullptr)), reproduced = true;
        if (reproduced)
            m_fullness -= c_reproductionFullnessCost;
    }
    if (!containingCell->IsMostNorthernCell() && containingCell->GetCellOnNorth()->ContainsObject()
        && containingCell->GetCellOnNorth()->GetObject()->GetType() == OceanObjectType::Seaweed && Random::GetRandomInt32(0, 4) == 0)
        EatSeaweed((Seaweed *)(containingCell->GetCellOnNorth()->GetObject()));
    else if(!containingCell->IsMostSouthernCell() && containingCell->GetCellOnSouth()->ContainsObject()
        && containingCell->GetCellOnSouth()->GetObject()->GetType() == OceanObjectType::Seaweed && Random::GetRandomInt32(0, 3) == 0)
        EatSeaweed((Seaweed *)(containingCell->GetCellOnSouth()->GetObject()));
    else if (!containingCell->IsMostWesternCell() && containingCell->GetCellOnWest()->ContainsObject()
        && containingCell->GetCellOnWest()->GetObject()->GetType() == OceanObjectType::Seaweed && Random::GetRandomInt32(0, 2) == 0)
        EatSeaweed((Seaweed *)(containingCell->GetCellOnWest()->GetObject()));
    else if (!containingCell->IsMostEasternCell() && containingCell->GetCellOnEast()->ContainsObject()
        && containingCell->GetCellOnEast()->GetObject()->GetType() == OceanObjectType::Seaweed && Random::GetRandomInt32(0, 1) == 0)
        EatSeaweed((Seaweed *)(containingCell->GetCellOnEast()->GetObject()));
    else
    {
        if (!containingCell->IsMostNorthernCell() && !containingCell->GetCellOnNorth()->ContainsObject() && Random::GetRandomInt32(0, 4) == 0)
            ocean->Move(containingCell->GetCellOnNorth(), this);
        else if (!containingCell->IsMostSouthernCell() && !containingCell->GetCellOnSouth()->ContainsObject() && Random::GetRandomInt32(0, 3) == 0)
            ocean->Move(containingCell->GetCellOnSouth(), this);
        else if (!containingCell->IsMostWesternCell() && !containingCell->GetCellOnWest()->ContainsObject() && Random::GetRandomInt32(0, 2) == 0)
            ocean->Move(containingCell->GetCellOnWest(), this);
        else if (!containingCell->IsMostEasternCell() && !containingCell->GetCellOnEast()->ContainsObject() && Random::GetRandomInt32(0, 1) == 0)
            ocean->Move(containingCell->GetCellOnEast(), this);
    }

    if (m_age == m_deathAge || m_fullness <= 0)
        ocean->Despawn(this);
}
char HerbivorousFish::Draw()
{
    return c_marker;
}
