//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#include <random>
#include <iostream>
#include "ocean.h"
#include "stone.h"
#include "object.h"
#include "common.h"


Ocean::Ocean()
{
    this->cells = new Cell*[N];

    for (size_t i = 0; i < N; i++)
    {
        this->cells[i] = new Cell[M];

        for (size_t j = 0; j < M; j++)
        {
            this->cells[i][j].initialize({i, j}, this);
        }
    }
}


Ocean::~Ocean()
{
    for (int i = 0; i < N; i++)
    {
        delete[] this->cells[i];
    }

    delete[] this->cells;

    for (auto obj : this->creations)
    {
        delete obj;
    }
}


void Ocean::addStartObjects(ObjType objectType, unsigned int amount)
{
    for (int i = 0; i < amount; i++)
    {
        auto x = std::rand() % N;
        auto y = std::rand() % M;

        Object* object = nullptr;

        if (this->cells[x][y].getObject())
        {
            i -= 1;
            continue;
        }

        switch(objectType)
        {

            case ObjType::PREY:
                object = new Prey(&this->cells[x][y]);
                break;
            case ObjType::PREDATOR:
                object = new Predator(&this->cells[x][y]);
                break;
            case ObjType::STONE:
                object = new Stone(&this->cells[x][y]);
                break;
            default:
                break;

        }

        this->cells[x][y].setObject(object);
        spawnObject(object);
    }
}


void Ocean::spawnObject(Object *object)
{
    creations.push_back(object);
}


void Ocean::killObject(Object *object)
{
    object->getCell()->kill();
}


Cell* Ocean::findEmptyField(Pair coordinates)
{
    for (int i = 0; i < TRIES_TO_FIND_SOMETHING; i++)
    {
        size_t tempX = coordinates.x + std::rand() % 3 - 1;
        size_t tempY = coordinates.y + std::rand() % 3 - 1;

        if (tempX < N && tempY < M)
        {
            if (this->cells[tempX][tempY].getObject() == nullptr)
            {
                return &this->cells[tempX][tempY];
            }
        }
    }
    return nullptr;
}


Cell* Ocean::findNearPrey(Pair coordinates)
{
    for (int i = 0; i < TRIES_TO_FIND_SOMETHING; i++)
    {
        size_t tempX = coordinates.x + std::rand() % 3 - 1;
        size_t tempY = coordinates.y + std::rand() % 3 - 1;

        if (tempX < N && tempY < M)
        {
            if (this->cells[tempX][tempY].getObject() && this->cells[tempX][tempY].getObject()->getType() == ObjType::PREY)
            {
                return &this->cells[tempX][tempY];
            }
        }
    }
    return nullptr;
}


int * Ocean::print()
{
    int preyAmount = 0;
    int predatorAmount = 0;
    int stoneAmount = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (cells[i][j].getObject())
            {

                if (cells[i][j].getObject()->getSymbol() == 'S')
                {
                    predatorAmount++;
                }
                if (cells[i][j].getObject()->getSymbol() == 'f')
                {
                    preyAmount++;
                }
                if (cells[i][j].getObject()->getSymbol() == '#')
                {
                    stoneAmount++;
                }
                std::cout << cells[i][j].getObject()->getSymbol() << " ";

            }
            else
                {
                    std::cout << ". ";
            }
        }
        std::cout << std::endl;
    }

    static int resultsReturning[2];

    std::cout << "Preys: " << preyAmount << std::endl;
    std::cout << "Predators: " << predatorAmount << std::endl;
    std::cout << "Stone: " << stoneAmount << std::endl;

    resultsReturning[0] = preyAmount;
    resultsReturning[1] = predatorAmount;

    return resultsReturning;
}


void Ocean::run()
{
    for (auto objectLabel = this->creations.begin(); objectLabel != this->creations.end(); objectLabel++)
    {
        if(!(*objectLabel)->live())
        {
            killObject(*objectLabel);
            this->creations.erase(objectLabel++);
        }
    }

}