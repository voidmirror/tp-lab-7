#ifndef COMMON_H
#define COMMON_H

#define STONE_LIFESPAN 0
#define STONE_REPRODUCTION 0
#define STONE_CAPACITY 0
#define PREY_LIFESPAN 10
#define PREY_REPRODUCTION 5
#define PREY_CAPACITY 0
#define PREDATOR_LIFESPAN 6
#define PREDATOR_REPRODUCTION 2
#define PREDATOR_CAPACITY 4

typedef size_t coord_t;

struct Pair
{
	coord_t x, y;
};

const size_t N = 10;
const size_t M = 10;

#endif
