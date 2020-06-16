#ifndef OBJECT_H
#define OBJECT_H
#include <vector>


class Cell;
class Ocean;
class Object
{
    public:
        Object();
        virtual ~Object(){};
        virtual void live() = 0;
        int getRow(){return this->row;};
        int getCol(){return this->col;};
        void kill();

        void setPlace(Cell* place){this->place = place;};
        void setRow(int row){this->row = row;};
        void setCol(int col){this->col = col;};
        int getObjType(){return this->objType;};
        bool checkKilled(){return this->killed;};
    protected:
        int objType = -1;
        int row;
        int col;
        int age = 0;
        bool killed = false;
        Cell* place;
    private:

};

#endif // OBJECT_H
