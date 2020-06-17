#ifndef _OCEAN_H_
#define _OCEAN_H_

#include <cstdint>
#include <vector>

#include "OceanCell.h"
#include "OceanObject.h"
#include "OceanObjectFactory.h"

class Ocean
{
private:
    static constexpr int32_t c_oceanDensity = 125;
    static constexpr int32_t c_maxOceanDensity = 1000;

    int32_t m_width;
    int32_t m_height;
    OceanObjectFactory *m_factory;
    std::vector<OceanCell *> m_cells;
    std::vector<OceanObject *> m_objects;
    std::vector<int32_t> m_updateIndices;

    void Initialize();

public:
    Ocean(int32_t width, int32_t height);
    ~Ocean();

    int32_t GetWidth() const;
    int32_t GetHeight() const;
    const std::vector<OceanCell *> *GetCells() const;

    OceanCell *GetCell(int32_t x, int32_t y) const;
    void Spawn(OceanCell *cell, OceanObject *object);
    void Move(OceanCell *cell, OceanObject *object);
    void Despawn(OceanObject *object);
    void Update();
};

extern "C" __declspec(dllexport) void *__cdecl AllocateOcean(int32_t width, int32_t height);

extern "C" __declspec(dllexport) void __cdecl UpdateOcean(void *oceanPtr);

extern "C" __declspec(dllexport) void __cdecl FreeOcean(void *oceanPtr);

#endif // _OCEAN_H_
