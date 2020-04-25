#include "Ocean.h"

Ocean::Ocean(size_t size_x, size_t size_y)
{
    this->size_x = size_x;
    this->size_y = size_y;
    this->cells.assign(size_x, std::vector<Cell*>(size_y));
    for (size_t x = 0; x < this->size_x; x++) 
    {
        for (size_t y = 0; y < this->size_y; y++)
        {
            this->cells[x][y] = new Cell(x, y, this);
        }
    }
}

Ocean::~Ocean()
{
}


void Ocean::spawnObjects()
{
    for (size_t x = 0; x < this->size_x; x++) 
    {
        for (size_t y = 0; y < this->size_y; y++)
        {
            this->cells[x][y]->addRandomObject();
            if (!this->cells[x][y]->isEmpty())
            {
                this->objects.push_back(this->cells[x][y]->getObject());
                
            }
        }
    }
}

void Ocean::move()
{
    std::vector<Object*> :: iterator obj;
    for (obj = this->objects.begin(); obj < this->objects.end();++obj)
    {
        if ( (*obj)->isAlive() )
        {
            (*obj)->live(this->cells);
        }
        if ( !((*obj)->isAlive()) ) 
        {
            this->objects.erase(obj);
        }
    }
}

void Ocean::run()
{
    while(!this->isDieOut())
    {
        system("sleep 2");
        this->move();
        this->print();
        std::cout << "Objects: " << this->objects.size() << std::endl;
        std::cout << "Is die out: " << this->isDieOut() << std::endl;

    }
}

void Ocean::print() 
{
    system("clear");
    for (size_t x = 0; x < this->size_x; x++) 
    {
        for (size_t y = 0; y < this->size_y; y++)
        {
            std::cout << this->cells[x][y]->getToken();
        }
        std::cout << std::endl;
    }    
}

void Ocean::addObject(Object* obj)
{
    this->objects.push_back(obj);
}

Cell* Ocean::getCell(size_t x, size_t y)
{
    return this->cells[x][y];
}

bool Ocean::isDieOut()
{
    for (auto obj : this->objects)
    {        
        if (obj->getCell()->getToken() != '#' && obj->getCell()->getToken() != '.' )
        {
            return false;
        }
    }
    return true;
}
