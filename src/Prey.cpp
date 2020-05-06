#include "../include/Prey.h"
#include "../include/Cell.h"
#include "../include/Ocean.h"


void Prey::spawn()
{
    if(last_spawned > PREY_SPAWN_TIME)
    {
        auto* free_cell = cell->findEmptyCell();
        if(free_cell != nullptr)
        {
            last_spawned = 0;
            auto* new_prey = new Prey(free_cell);
            free_cell->setObject(new_prey);
            free_cell->getOcean()->addStuff(new_prey);
            free_cell->getOcean()->preys++;
        }
    }
    else
    {
        last_spawned++;
    }
}

void Prey::move()
{
    auto* free_cell = cell->findEmptyCell();
    if(free_cell != nullptr)
    {
        cell->setObject(nullptr);
        free_cell->setObject(this);
        cell = free_cell;
    }
}

bool Prey::live()
{
    if(++age < PREY_MAX_AGE && !isEaten)
    {
        spawn();
        move();
        return true;
    }
    else
    {
        return false;
    }
}
