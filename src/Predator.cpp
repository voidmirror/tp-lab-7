#include "Predator.h"

Predator::Predator(Cell* cell = nullptr) :
    Fish(7, cell)
{
    this->full = false;
}

Predator::~Predator()
{
}

void Predator::live(std::vector< std::vector<Cell*> > cells)
{
    this->livetime++;
    unsigned int x = this->cell->getX();
    unsigned int y = this->cell->getY();
    
    if (this->livetime == this->maxlivetime)
    {
        this->die();
        cells[x][y]->clearCell();
    } 
    else if (this->full && x > 0 && cells[x-1][y]->getToken() == '.')
    {
        this->reproduction(cells[x-1][y]);
    }
    else if (this->full && x+1 < cells.size() && cells[x+1][y]->getToken() == '.')
    {
        this->reproduction(cells[x+1][y]);
    }
    else
    {
        if (x > 0 && cells[x-1][y]->getToken() == 'f') 
        {
            this->kill(cells[x-1][y]);
        }
        else if (y > 0 && cells[x][y-1]->getToken() == 'f')
        {
            this->kill(cells[x][y-1]);
        }
        else if (x+1 < cells.size() && cells[x+1][y]->getToken() == 'f')
        {
            this->kill(cells[x+1][y]);
        }
        else if (y+1 < cells[0].size() && cells[x][y+1]->getToken() == 'f')
        {
            this->kill(cells[x][y+1]);
        }
    }
    
}

void Predator::reproduction(Cell* cell)
{
    this->full=false;

    Predator* p = new Predator(cell);
    cell->setObject(predator, p);
    cell->getOcean()->addObject(p);
}

void Predator::kill(Cell* cell)
{
    this->full = true;

    cell->getObject()->die();
    cell->setObject(predator, this);
    
    this->cell->clearCell();
    this->setCell(cell);
}