//
// Created by fiskirton on 08.04.2020.
//

#include "Ocean.h"
#include "Animate.h"
#include "helper.h"
#include <iostream>
#include <ncurses.h>

using namespace std;

int main(){

    auto * ocean = new Ocean();
    ocean->init();

    return 0;
}