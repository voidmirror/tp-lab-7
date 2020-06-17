#include <cstdint>

#include "BufferedOceanRenderer.h"
#include "Ocean.h"
#include "OceanCell.h"
#include "OceanRenderer.h"

BufferedOceanRenderer::BufferedOceanRenderer(Ocean *ocean, char *buffer)
    : OceanRenderer(ocean)
{
    m_width = ocean->GetWidth();
    m_height = ocean->GetHeight();
    m_buffer = buffer;
}

char *BufferedOceanRenderer::GetBuffer() { return m_buffer; }
void BufferedOceanRenderer::SetBuffer(char *buffer) { m_buffer = buffer; }

void BufferedOceanRenderer::Draw()
{
    const std::vector<OceanCell *> *cells = GetOcean()->GetCells();
    for (int32_t x = 0; x < m_width; x++)
    {
        for (int32_t y = 0; y < m_height; y++)
        {
            size_t index = (size_t)y * m_width + (size_t)x;
            m_buffer[index] = '\0';
            if ((*cells)[index]->ContainsObject())
                m_buffer[index] = (*cells)[index]->GetObject()->Draw();
        }
    }
}
