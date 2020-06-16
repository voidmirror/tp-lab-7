//
// Created by Mikhail on 01.05.2020.
//

#ifndef TASK1_HELPERS_H
#define TASK1_HELPERS_H
enum ObjType {
    STONE,
    PREY,
    PREDATOR,
    NONE
};

#define STONE_N '#'
#define PREY_N 'f'
#define PREDATOR_N 'S'

const int dx[4] = {0, 1, -1, 0};
const int dy[4] = {1, 0, 0, -1};

namespace PREYH {
    const int lifeTime = 25;
    const int reproduceTime = 5;
}

namespace PREDATORH {
    const int lifeTime = 15;
    const int reproduceTime = 10;
    const int eatTime = 5;
}

namespace STONEH {
    const int lifeTime = 1000000;
}

#endif //TASK1_HELPERS_H
