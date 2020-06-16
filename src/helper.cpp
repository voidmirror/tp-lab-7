//
// Created by fiskirton on 10.04.2020.
//

#include "helper.h"
#include "random"

int getRandom(int min, int max) {

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(min, max);

    return dist(mt);

}

void SetCursorPos(int XPos, int YPos) {
    printf("\033[%d;%dH", YPos+1, XPos+1);
}
