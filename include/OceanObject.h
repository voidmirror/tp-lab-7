#ifndef _OCEANOBJECT_H_
#define _OCEANOBJECT_H_

#include "OceanObjectType.h"

class Ocean;
class OceanCell;

class OceanObject
{
private:
    OceanObjectType m_type;
    Ocean *m_ocean;
    OceanCell *m_cell;
    bool m_destroyed;

protected:
    OceanObject(OceanObjectType type, Ocean *ocean, OceanCell *cell);

public:
    OceanObjectType GetType() const;
    Ocean *GetOcean() const;
    OceanCell *GetCell() const;
    void SetCell(OceanCell *cell);

    bool IsDestroyed() const;
    void Destroy();

    virtual void Update() = 0;
    virtual char Draw() = 0;
};

#endif // _OCEANOBJECT_H_
