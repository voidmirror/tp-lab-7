#pragma once
#include <cstring>
#include <iostream>

class Ocean;

struct Coordinates {
    int x;
    int y;
};

class Object {

protected:
    Ocean* ocean;
    Coordinates location;
    char character;

    Object(int x, int y, Ocean* ocean);
    Object(Coordinates coordinates, Ocean* ocean);


public:
    char getCharacter();
    virtual std::string getName() = 0;
};
