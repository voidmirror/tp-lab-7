#include "Ocean.h"
#include "OceanCell.h"
#include "OceanObject.h"
#include "OceanObjectType.h"
#include "Random.h"
#include "Seaweed.h"

Seaweed::Seaweed(Ocean *ocean, OceanCell *cell)
    : OceanObject(OceanObjectType::Seaweed, ocean, cell)
{
    m_age = 0;
    m_delay = Random::GetRandomInt32(0, c_reproductionPeriod);
    m_deathAge = Random::GetRandomInt32(c_minDeathAge, c_maxDeathAge);
}

void Seaweed::Update()
{
    if (IsDestroyed())
        return;

    m_age++;

    Ocean *ocean = GetOcean();
    OceanCell *containingCell = GetCell();
    if ((m_age + m_delay) % c_reproductionPeriod == 0)
    {
        if (!containingCell->IsMostNorthernCell() && !containingCell->GetCellOnNorth()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnNorth(), new Seaweed(ocean, nullptr));
        if (!containingCell->IsMostSouthernCell() && !containingCell->GetCellOnSouth()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnSouth(), new Seaweed(ocean, nullptr));
        if (!containingCell->IsMostWesternCell() && !containingCell->GetCellOnWest()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnWest(), new Seaweed(ocean, nullptr));
        if (!containingCell->IsMostEasternCell() && !containingCell->GetCellOnEast()->ContainsObject())
            ocean->Spawn(containingCell->GetCellOnEast(), new Seaweed(ocean, nullptr));
    }
    if (m_age == m_deathAge)
        ocean->Despawn(this);
}
char Seaweed::Draw()
{
    return c_marker;
}
