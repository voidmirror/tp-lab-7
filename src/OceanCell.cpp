#include "Ocean.h"
#include "OceanCell.h"
#include "OceanObject.h"

OceanCell::OceanCell(int32_t x, int32_t y, Ocean *ocean)
{
    m_x = x;
    m_y = y;
    m_ocean = ocean;
    m_object = nullptr;
}

int32_t OceanCell::GetX() const { return m_x; }
int32_t OceanCell::GetY() const { return m_y; }
Ocean *OceanCell::GetOcean() const { return m_ocean; }
OceanObject *OceanCell::GetObject() const { return m_object; }
void OceanCell::SetObject(OceanObject *object) { m_object = object; }

bool OceanCell::ContainsObject() const
{
    return m_object != nullptr;
}

bool OceanCell::IsMostNorthernCell() const
{
    return m_y == 0;
}
bool OceanCell::IsMostSouthernCell() const
{
    return m_y == (m_ocean->GetHeight() - 1);
}
bool OceanCell::IsMostWesternCell() const
{
    return m_x == 0;
}
bool OceanCell::IsMostEasternCell() const
{
    return m_x == (m_ocean->GetWidth() - 1);
}

OceanCell *OceanCell::GetCellOnNorth() const
{
    return IsMostNorthernCell() ? nullptr : m_ocean->GetCell(m_x, m_y - 1);
}
OceanCell *OceanCell::GetCellOnSouth() const
{
    return IsMostSouthernCell() ? nullptr : m_ocean->GetCell(m_x, m_y + 1);
}
OceanCell *OceanCell::GetCellOnWest() const
{
    return IsMostWesternCell() ? nullptr : m_ocean->GetCell(m_x - 1, m_y);
}
OceanCell *OceanCell::GetCellOnEast() const
{
    return IsMostEasternCell() ? nullptr : m_ocean->GetCell(m_x + 1, m_y);
}
