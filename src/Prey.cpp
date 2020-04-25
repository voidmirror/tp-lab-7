#include "Prey.h"

Prey::Prey(Cell* cell = nullptr):
    Fish(5, cell)
{
    this->direction = rand() % 2;
}

Prey::~Prey()
{
}

void Prey::live(std::vector< std::vector<Cell*> > cells)
{
    this->livetime++;
    unsigned int x = this->cell->getX();
    unsigned int y = this->cell->getY();
    
    if (this->livetime == this->maxlivetime)
    {
        this->die();
        cells[x][y]->clearCell();
    } 
    else if (this->livetime == this->reproductiontime && x > 0 && cells[x-1][y]->getToken() == '.')
    {
        this->reproduction(cells[x-1][y]);
    }
    else if (this->livetime == this->reproductiontime && x+1 < cells.size() && cells[x+1][y]->getToken() == '.')
    {
        this->reproduction(cells[x+1][y]);
    }
    else if (this->direction == true)
    {
        if (y > 0 && cells[x][y-1]->getToken() == '.')
            {this->go(cells[x][y-1]);}
        else {this->direction = false;}    
    }
    else if (this->direction == false)
    {
        if (y+1 < cells[0].size() && cells[x][y+1]->getToken() == '.')
            {this->go(cells[x][y+1]);}
        else {this->direction = true;}
    }
}

void  Prey::reproduction(Cell* cell)
{
    Prey* p = new Prey(cell);
    cell->setObject(prey, p);
    cell->getOcean()->addObject(p);
}

void Prey::go(Cell* cell)
{
    cell->setObject(prey,this);
    this->cell->clearCell();
    this->setCell(cell);
}