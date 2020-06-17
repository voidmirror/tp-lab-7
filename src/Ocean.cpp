#include "Ocean.h"
#include "Stone.h"
#include "Object.h"
#include "common.h"
#include "Predator.h"
#include "Prey.h"

using namespace std;

Ocean::Ocean(size_t x, size_t y, int preys, int predators, int stones)
{
    N=x;
    M=y;
    cells = new Cell*[N];
    for (size_t i = 0; i < N; i++)
    {
        cells[i] = new Cell[M];
        for (size_t j = 0; j < M; j++)
            cells[i][j].init({i, j}, this);
    }
    addObjects(Type::PREY, preys);
    addObjects(Type::PREDATOR, predators);
    addObjects(Type::STONE, stones);
}
Ocean::~Ocean()
{
    for (int i = 0; i < N; i++)
        delete[] cells[i];
    delete[] cells;
    for (auto obj : objects)
        delete obj;
}

void Ocean::print() const
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++) {
            auto obj = cells[i][j].getObject();
            if (obj)
            {
                cout << cells[i][j].getObject()->getSymbol() << " ";
            }
            else {
                cout << "⬛ ";
            }
        }
        cout<<endl;
    }
    cout<<"prey: "<<countPrey<<" predator: "<<countPredator<<" stone: "<<countStone<<endl;
}

void Ocean::addObjects(Type type, unsigned int amount)
{
    for (int i = 0; i < amount;)
    {
        auto x = rand() % N;
        auto y = rand() % M;
        if (cells[x][y].getObject())
            continue;
        Object* obj = NULL;
        switch(type)
        {
            case Type::PREDATOR:
                obj = new Predator(&cells[x][y]);
                break;
            case Type::PREY:
                obj = new Prey(&cells[x][y]);
                break;
            case Type::STONE:
                obj = new Stone(&cells[x][y]);
				break;
            default:
                break;
        }
        cells[x][y].setObject(obj);
        objects.push_back(obj);
        i++;
    }
}

void Ocean::addStuff(Object *obj)
{
    objects.push_back(obj);
}

void Ocean::eraseObject(Object *obj)
{
    obj->getCell()->killMe();
}

Cell* Ocean::findEmptyCell(Coords crd)
{
    random_device rand;
    std::vector <Cell *> vars;
     for (auto nr = std::max(size_t(0), crd.x - 1); nr <= std::min(crd.x + 1, N - 1); nr++)
       {
           for (auto nc = std::max(size_t(0), crd.y-1); nc <= std::min(crd.y + 1, M - 1); nc++)
           {
               if (!(nr==crd.x && nc==crd.y))
               {
                   if (cells[nr][nc].getObject() == NULL)
                       vars.push_back(&cells[nr][nc]);
               }
           }
       }
    if (vars.size())
        return vars[rand()%vars.size()];
    else
        return NULL;
}

Cell* Ocean::findPrey(Coords crd)
{
    
    for (auto nr = std::max(size_t(0), crd.x - 1); nr <= std::min(crd.x + 1, N - 1); nr++)
    {
        for (auto nc = std::max(size_t(0), crd.y-1); nc <= std::min(crd.y + 1, M - 1); nc++)
        {
            if (!(nr==crd.x && nc==crd.y))
            {
                if (cells[nr][nc].getObject() && cells[nr][nc].getObject()->getType() == Type::PREY)
                    return &cells[nr][nc];
            }
        }
    }
    return NULL;
}
int Ocean::GO()
{
    countPrey=0; countPredator=0; countStone=0;
    auto i = objects.begin();
    for (; i != objects.end(); i++)
    {
        if(!(*i)->live())
        {
            eraseObject(*i);
            objects.erase(i++);
        }
        else
        {
            if (typeid(**i) == typeid(Prey))
            {
               countPrey++;
            }
            if (typeid(**i) == typeid(Predator))
            {
               countPredator++;
            }
            if (typeid(**i) == typeid(Stone))
            {
               countStone++;
            }
        }
    }
    if (!countPrey)
        return 1;
    if (!countPredator)
        return 2;
    return 0;
}
