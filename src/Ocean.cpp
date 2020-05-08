#include <cstdint>
#include <vector>

#include "Ocean.h"
#include "OceanCell.h"
#include "OceanObject.h"
#include "OceanObjectType.h"
#include "OceanObjectFactory.h"
#include "Random.h"
#include "Rock.h"

void Swap(int32_t *left, int32_t *right);

Ocean::Ocean(int32_t width, int32_t height)
{
    m_width = width;
    m_height = height;
    m_factory = new OceanObjectFactory(this);
    m_cells = std::vector<OceanCell *>((int64_t)width * (int64_t)height);
    m_objects = std::vector<OceanObject *>();
    m_updateIndices = std::vector<int32_t>();

    for (size_t i = 0; i < (size_t)m_width * (size_t)m_height; i++)
        m_cells[i] = new OceanCell(i % m_width, i / m_width, this);

    Initialize();
}

Ocean::~Ocean()
{
    delete m_factory;
    for (size_t i = 0; i < m_cells.size(); i++)
        delete m_cells[i];
    for (size_t i = 0; i < m_objects.size(); i++)
        delete m_objects[i];
}

int32_t Ocean::GetWidth() const { return m_width; }
int32_t Ocean::GetHeight() const { return m_height; }
const std::vector<OceanCell *> *Ocean::GetCells() const { return &m_cells; }

void Ocean::Initialize()
{
    for (size_t i = 0; i < (size_t)m_width * (size_t)m_height; i++)
    {
        if (Random::GetRandomInt32(1, c_maxOceanDensity + 1) <= c_oceanDensity)
        {
            int32_t value = Random::GetRandomInt32();
            if (value > INT32_MAX >> 1)
                Spawn(m_cells[i], m_factory->CreateObject(OceanObjectType::Seaweed));
            else if (value > INT32_MAX >> 2)
                Spawn(m_cells[i], m_factory->CreateObject(OceanObjectType::HerbivorousFish));
            else if (value > INT32_MAX >> 3)
                Spawn(m_cells[i], m_factory->CreateObject(OceanObjectType::CarnivorousFish));
            else
                Spawn(m_cells[i], m_factory->CreateObject(OceanObjectType::Rock));
        }
    }
}

OceanCell *Ocean::GetCell(int32_t x, int32_t y) const
{
    return m_cells[(size_t)y * (size_t)m_width + (size_t)x];
}
void Ocean::Spawn(OceanCell *cell, OceanObject *object)
{
    object->SetCell(cell);
    cell->SetObject(object);
    m_objects.push_back(object);
}
void Ocean::Move(OceanCell *cell, OceanObject *object)
{
    object->GetCell()->SetObject(nullptr);
    object->SetCell(cell);
    cell->SetObject(object);
}
void Ocean::Despawn(OceanObject *object)
{
    object->Destroy();
    object->GetCell()->SetObject(nullptr);
}

void Ocean::Update()
{
    size_t currentGenerationSize = m_objects.size();
    if (currentGenerationSize > m_updateIndices.size())
        m_updateIndices.resize(currentGenerationSize);

    for (size_t i = 0; i < currentGenerationSize; i++)
        m_updateIndices[i] = i;
    for (size_t i = 0; i < currentGenerationSize; i++)
        Swap(&m_updateIndices[i], &m_updateIndices[Random::GetRandomInt32(0, currentGenerationSize)]);

    for (size_t i = 0; i < currentGenerationSize; i++)
        m_objects[m_updateIndices[i]]->Update();

    for (size_t i = 0; i < currentGenerationSize; i++)
    {
        if (m_objects[i]->IsDestroyed())
        {
            delete m_objects[i];
            m_objects.erase(m_objects.begin() + i);
            i--;
            currentGenerationSize--;
        }
    }
}

void *__cdecl AllocateOcean(int32_t width, int32_t height)
{
    return new Ocean(width, height);
}

void __cdecl UpdateOcean(void *oceanPtr)
{
    ((Ocean *)oceanPtr)->Update();
}

void __cdecl FreeOcean(void *oceanPtr)
{
    delete (Ocean *)oceanPtr;
}

void Swap(int32_t *leftPtr, int32_t *rightPtr)
{
    int32_t leftValue = *leftPtr;
    int32_t rightValue = *rightPtr;
    *leftPtr = rightValue;
    *rightPtr = leftValue;
}
