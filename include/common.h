//
// Created by Оксана on 02.05.2020.
//

#ifndef TASK1_COMMON_H
#define TASK1_COMMON_H


#include <iostream>
using namespace std;





const int N = 30;
const int M = 60;

//const int stones = 10;
//const int preys = 10;
//const int predators = 10;

const int preyLifetime = 10;
const int preyReproducetime = 5;

const int predatorLifetime = 15;
const int predatorReproducetime = 5;
const int predatorHungerlevel = 4;
//const int speed = 10;

struct Pair {
    int x; // 0...M-1
    int y; // 0...N-1
};



#endif //TASK1_COMMON_H
