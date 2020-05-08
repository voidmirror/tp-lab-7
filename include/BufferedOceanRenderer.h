#ifndef _BUFFEREDOCEANRENDERER_H_
#define _BUFFEREDOCEANRENDERER_H_

#include <cstdint>

#include "Ocean.h"
#include "OceanRenderer.h"

class BufferedOceanRenderer : OceanRenderer
{
private:
    int32_t m_width;
    int32_t m_height;
    char *m_buffer;

public:
    BufferedOceanRenderer(Ocean *ocean, char *buffer);

    char *GetBuffer();
    void SetBuffer(char *buffer);

    virtual void Draw() override;
};

#endif // _BUFFEREDOCEANRENDERER_H_
