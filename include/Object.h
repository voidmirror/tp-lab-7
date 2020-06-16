//
// Created by fiskirton on 08.04.2020.
//

#ifndef OCEAN_OBJECT_H
#define OCEAN_OBJECT_H

#define STONE_N '#'
#define FISH_N 'f'
#define PFISH_N 'S'

enum ObjType {FISH=1, PFISH, STONE};

class Cell;
class Ocean;

class Object {

protected:
    char obj_type{};
    Cell *cell{};
    int type_id{};

public:
    virtual ~Object();

public:
    void setCell(Cell *cell);
    char getObjType() const;
    int getTypeId() const;

    virtual void init() = 0;
    virtual void update() = 0;
    virtual void kill() = 0;

    Cell *getCell() const;

};

#endif //OCEAN_OBJECT_H
