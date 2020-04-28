//
// Created by Mary on 15.04.2020.
//
#include <random>
#include <algorithm>
#include "ocean.h"
#include "cell.h"
Ocean::Ocean(int size_x, int size_y)
{
    sizeOfOcean = std::make_pair(size_x, size_y);
    cells.resize(sizeOfOcean.first);
    for (size_t i = 0; i < sizeOfOcean.first; i++)
    {
        cells[i].resize(sizeOfOcean.second);
        for (size_t j = 0; j < sizeOfOcean.second; j++)
        {
            cells[i][j] = new Cell();
            cells[i][j]->init(i, j, this);
        }
    }
}


void Ocean::print()
{
    for (size_t i = 0; i < sizeOfOcean.first; i ++)
    {
        for (size_t j = 0; j < sizeOfOcean.second; j ++)
        {
            if  (cells[i][j]->getObject())
                std::cout << cells[i][j]->getObject()->getSymbol() << " ";
            else
                std::cout << ". ";
        }
        std::cout << std::endl;
    }
}

void Ocean::addCreatures(ObjType type, size_t number)
{
    for (size_t i = 0; i < number;)
    {
        size_t x = rand() % sizeOfOcean.first;
        size_t y = rand() % sizeOfOcean.second;
        if (cells[x][y]->getObject())
            continue;
        Object* obj = nullptr;
        switch(type)
        {
            case ObjType ::STONE :
                obj = new Stone(cells[x][y]);
                break;
            case ObjType::PREY :
                obj = new Prey(cells[x][y]);
                break;
            case ObjType::PREDATOR :
                obj = new Predator(cells[x][y]);
                break;
            default:
                break;
        }
        cells[x][y]->setObject(obj);
        creatures.push_back(obj);
        i++;
    }

}

void Ocean::addCreature(Object *obj)
{
    creatures.push_back(obj);
}

void Ocean::live(size_t numberOfIterations)
{
    for (size_t i = 0; i < numberOfIterations; i ++)
    {
        std::list<Object*> alive_creatures;
        for(auto obj : creatures)
        {
            if (!(obj->live()))
            {
                obj->getCell()->setObject(nullptr);
                obj = nullptr;
            }
            else
                alive_creatures.push_back(obj);
        }
        int nPredator = 0, nPrey = 0;
        creatures = alive_creatures;
        for (auto obj : alive_creatures)
        {
            if (obj->getTypeOfObject() == ObjType::PREDATOR)
                nPredator++;
            else if (obj->getTypeOfObject() == ObjType::PREY)
                nPrey++;
        }
        if (nPredator == 0)
        {
            print();
            std::cout << "All predators are died" << std::endl;
            return;
        }
        if (nPrey == 0)
        {
            print();
            std::cout << "All preys are died" << std::endl;
            return;
        }
    }
    print();
    std::cout << "Ocean in balance" << std::endl;
}

Cell* Ocean::isPreyAround(std::pair<size_t, size_t> coords)
{
    std::vector<std::pair<size_t, size_t>> pos_coords = {
            std::make_pair(coords.first + 1, coords.second),
            std::make_pair(coords.first - 1, coords.second),
            std::make_pair(coords.first, coords.second + 1),
            std::make_pair(coords.first, coords.second - 1)};
    for (auto i : pos_coords)
    {
        if ((i.first >= 0) && (i.first < sizeOfOcean.first) &&
            (i.second >= 0) && (i.second < sizeOfOcean.second))
        {
            if (cells[i.first][i.second]->getObject())
            {
               if (cells[i.first][i.second]->getObject()->getTypeOfObject() == ObjType::PREY)
                   return cells[i.first][i.second];
            }
        }
    }
    return nullptr;
}

Cell* Ocean::isFreeCellAround(std::pair<size_t, size_t> coords)
{
    std::vector<std::pair<size_t, size_t>> pos_coords = {
            std::make_pair(coords.first + 1, coords.second),
            std::make_pair(coords.first - 1, coords.second),
            std::make_pair(coords.first, coords.second + 1),
            std::make_pair(coords.first, coords.second - 1)};
    auto rng = std::default_random_engine{};
    std::shuffle(pos_coords.begin(), pos_coords.end(), rng);
    for (auto i : pos_coords)
    {
        if ((i.first >= 0) && (i.first < sizeOfOcean.first) && (i.second >= 0) && (i.second < sizeOfOcean.second))
        {
            if (cells[i.first][i.second]->getObject() == nullptr)
            {
               return cells[i.first][i.second];
            }
        }
    }
    return nullptr;
}