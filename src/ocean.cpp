#include "ocean.h"
#include "stone.h"
#include "object.h"

using namespace std;

Ocean::Ocean()
{
    cells = new Cell * [N];
    for (size_t i(0); i < N; i++)
    {
        cells[i] = new Cell[M];
        for (size_t j(0); j < M; j++)
            cells[i][j].init({ i, j }, this);
    }
}
Ocean::~Ocean()
{
    for (int i(0); i < N; i++)
        delete[] cells[i];
    delete[] cells;
    for (auto obj : stuff)
        delete obj;
}

void Ocean::print(std::ostream& stream) const
{
    for (int i(0); i < N; i++)
    {
        for (int j(0); j < M; j++)
            stream << (cells[i][j].getObject() ? cells[i][j].getObject()->getChar() : '.');
        stream << endl;
    }
}

void Ocean::addObjects(ObjType type, unsigned int amount)
{
    for (int i(0); i < amount;)
    {
        auto x = rand() % N;
        auto y = rand() % M;
        if (cells[x][y].getObject())
            continue;
        Object* obj = nullptr;
        switch (type)
        {
        case ObjType::PREDATOR:
            obj = new Predator(&cells[x][y]);
            break;
        case ObjType::PREY:
            obj = new Prey(&cells[x][y]);
            break;
        case ObjType::STONE:
            obj = new Stone(&cells[x][y]);
            break;
        default:
            break;
        }
        cells[x][y].setObject(obj);
        stuff.push_back(obj);
        i++;
    }
}

void Ocean::addStuff(Object* obj)
{
    stuff.push_back(obj);
}

void Ocean::deleteObject(Object* obj)
{
    obj->getCell()->killMe();
}

Cell* Ocean::findEmpty(Pair crd)
{
   
    for (int i(0); i < Search_Attempts; i++)
    {
        size_t x_n = crd.x + rand() % 3 - 1;
        size_t y_n = crd.y + rand() % 3 - 1;
        
        if (x_n < N && y_n < M)
            if (cells[x_n][y_n].getObject() == nullptr)
                return &cells[x_n][y_n];
    }

    return nullptr;
}

Cell* Ocean::findPrey(Pair crd)
{
    
    for (int i(0); i < Search_Attempts; i++)
    {
        size_t x_n = crd.x + rand() % 3 - 1;
        size_t y_n = crd.y + rand() % 3 - 1;
       
        if (x_n < N && y_n < M)
            if (cells[x_n][y_n].getObject() && cells[x_n][y_n].getObject()->getType() == ObjType::PREY)
                return &cells[x_n][y_n];
    }
    return nullptr;
}
void Ocean::run()
{
    auto i = stuff.begin();
    for (; i != stuff.end(); i++)
    {
        if (!(*i)->live())
        {
            deleteObject(*i);
            stuff.erase(i++);
        }
    }

}