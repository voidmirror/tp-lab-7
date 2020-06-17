#ifndef _OCEANCELL_H_
#define _OCEANCELL_H_

#include <cstdint>

#include "OceanObject.h"

class Ocean;

class OceanCell
{
private:
    int32_t m_x;
    int32_t m_y;
    Ocean *m_ocean;
    OceanObject *m_object;

public:
    OceanCell(int32_t x, int32_t y, Ocean *ocean);

    int32_t GetX() const;
    int32_t GetY() const;
    Ocean *GetOcean() const;
    OceanObject *GetObject() const;
    void SetObject(OceanObject *object);

    bool ContainsObject() const;

    bool IsMostNorthernCell() const;
    bool IsMostSouthernCell() const;
    bool IsMostWesternCell() const;
    bool IsMostEasternCell() const;

    OceanCell *GetCellOnNorth() const;
    OceanCell *GetCellOnSouth() const;
    OceanCell *GetCellOnWest() const;
    OceanCell *GetCellOnEast() const;
};

#endif // _OCEANCELL_H_
