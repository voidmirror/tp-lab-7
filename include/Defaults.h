#ifndef Defaults_h
#define Defaults_h

#define PREY_CHAR 'f'
#define PRED_CHAR 'S'
#define STONE_CHAR '#'

#define PREY_LIFE 20
#define PRED_LIFE 15
#define STONE_LIFE 1000000

#define CELL_TRIES 5
#define PREY_TRIES 5

#define PREY_REPR 8
#define PRED_REPR 8

#define X 30
#define Y 30

typedef size_t coord_t;

struct Coord
{
    coord_t x;
    coord_t y;
};
#endif /* Defaults_h */
