#include "../include/Ocean.h"
#include "../include/Stone.h"
#include "../include/Prey.h"
#include "../include/Predator.h"

#include <iomanip>


Ocean::Ocean()
{
    stones = 0;
    preys = 0;
    predators = 0;
    for(size_t row = 0; row < N; row++)
    {
        cells.emplace_back(M);
        for(size_t col = 0; col < M; col++)
        {
            auto new_cell_ptr{new Cell};
            cells[row][col] = new_cell_ptr;
            cells[row][col]->init({row, col}, this);

            empty_cells.push_back({row,col});
        }
    }
}

Ocean::~Ocean()
{
    for(auto* object : stuff)
    {
        delete object;
    }
    for(auto& row : cells)
    {
        for(auto* cell : row)
        {
            delete cell;
        }
        row.clear();
    }
    cells.clear();
    empty_cells.clear();
}

void Ocean::run()
{
    vector<Object*> cemetery;
    for(auto obj : stuff)
    {
        if(!obj->live())
        {
            cemetery.push_back(obj);
        }
    }
    for(auto* obj : cemetery)
    {
        deleteObject(obj);
    }
}

void Ocean::addObjects(ObjType type, size_t count)
{
    random_device rdev{};
    default_random_engine generator{rdev()};
    while(!empty_cells.empty() && count > 0)
    {
        uniform_int_distribution<int> distribution(0, empty_cells.size()-1);
        int dice_roll = distribution(generator);
        auto[row, col] = empty_cells[dice_roll];
        empty_cells.erase(empty_cells.begin() + dice_roll);
        count--;

        switch (type)
        {
            case ObjType::STONE:
            {
                auto *new_stone{new Stone{cells[row][col]}};
                cells[row][col]->setObject(new_stone);
                stuff.emplace_back(new_stone);
                stones++;
                break;
            }
            case ObjType::PREY:
            {
                auto *new_prey{new Prey{cells[row][col]}};
                cells[row][col]->setObject(new_prey);
                stuff.emplace_back(new_prey);
                preys++;
                break;
            }
            case ObjType::PREDATOR:
            {
                auto *new_predator{new Predator{cells[row][col]}};
                cells[row][col]->setObject(new_predator);
                stuff.emplace_back(new_predator);
                predators++;
                break;
            }
        }
    }
}

void Ocean::deleteObject(Object* obj)
{
    obj->getCell()->killMe();
}

void Ocean::addStuff(Object* obj)
{
    stuff.push_back(obj);
}

Cell* Ocean::findEmptyCell(Pair coord) const
{
    const vector<pair<int,int>> steps = {{1,0}, {0,1}, {-1,0}, {0, -1}
            ,{-1,-1}, {-1,1}, {1,-1}, {1,1}};
    for(const auto& [row, col] : steps)
    {
        int x = coord.row + row;
        int y = coord.col + col;

        if( x >= 0 && x < N && y >= 0 && y < M )
        {
            auto* cell{cells[x][y]};
            if(cell->isEmpty())
            {
                return cell;
            }
        }
    }
    return nullptr;
}

Cell* Ocean::findType(Pair coord, ObjType type) const
{
    const vector<pair<int,int>> steps = {{1,0}, {0,1}, {-1,0}, {0, -1}
            ,{-1,-1}, {-1,1}, {1,-1}, {1,1}};
    for(const auto& [row, col] : steps)
    {
        int x = coord.row + row;
        int y = coord.col + col;

        if( x >= 0 && x < N && y >= 0 && y < M )
        {
            auto* cell{cells[x][y]};
            if(!cell->isEmpty() && cell->getObj()->getType() == type)
            {
                return cell;
            }
        }
    }
    return nullptr;
}

void Ocean::print(ostream& out) const
{
    for(const auto& row : cells)
    {
        for(const auto& cell : row)
        {
            if(cell->isEmpty())
            {
                out << setw(2) << " ";
            }
            else
            {
                out << setw(2) << *cell->getObj();
            }
        }
        out << endl;
    }
}
