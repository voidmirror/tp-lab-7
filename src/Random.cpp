#include <cstdint>
#include <cstdlib>

#include "Random.h"

void Random::SetRandomSeed(int32_t seed)
{
    srand((uint32_t)seed);
}

int32_t Random::GetRandomInt32()
{
    return rand() << 16 | rand();
}
int32_t Random::GetRandomInt32(int32_t lowerBound, int32_t upperBound)
{
    return lowerBound + GetRandomInt32() % (upperBound - lowerBound);
}

void __cdecl SetRandomSeed(int32_t seed)
{
    Random::SetRandomSeed(seed);
}
