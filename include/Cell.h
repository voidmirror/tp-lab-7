#ifndef CELL_H
#define CELL_H

class Ocean;
class Object;
class Cell
{
    public:
        Cell(Ocean* ocean);
        void setRow(int row){this->row = row;};
        void setCol(int col){this->column = col;};
        void setObject(Object* object);

        int getRow(){return this->row;};
        int getCol(){return this->column;};
        int getObjType(){return this->objType;};
        Ocean* getOcean(){return this->ocean;};
        Object* getObject(){return this->object;};

        bool isEmpty(){if(object != nullptr){return false;} return true;};
    protected:

    private:
    int objType = -1;
    int row;
    int column;
    Ocean* ocean;
    Object* object;
};

#endif // CELL_H
