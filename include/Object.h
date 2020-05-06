#pragma once
#include <cstring>
#include <iostream>

class Ocean;

struct coord {
    int x;
    int y;
};

class Object {

protected:
    Ocean* ocean;
    coord location;
    char symbol;

    Object(int x, int y, Ocean* ocean);
    Object(coord coordinates, Ocean* ocean);


public:
    char getSymbol();
    virtual std::string getName() = 0;
};
