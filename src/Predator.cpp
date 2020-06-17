#include "../include/Predator.h"
#include "../include/Ocean.h"


bool Predator::live()
{
    if((age >= PREDATOR_MAX_AGE) || (days_starving >= PREDATOR_MAX_STARVING_TIME))
    {    //kitten has died
         return false;
    }
    else
    {
        spawn();
        if(days_starving >= PREDATOR_MIN_HUNGER_TIME)
        {
            auto* cell_with_prey = cell->findType(ObjType::PREY);
            if(cell_with_prey != nullptr)
            {
                cell_with_prey->killMe();
                cell_with_prey->setObject(this);

                cell->setObject(nullptr);
                cell = cell_with_prey;
                days_starving = 0;//full and sleeping

             }
            else
            {
                move();
                days_starving++;
            }
        }
        else
        {
            move();
        }
        return true;
    }
}

void Predator::spawn()
{
    last_spawned++;
    if(last_spawned > PREDATOR_SPAWN_TIME && days_starving <= PREDATOR_MIN_HUNGER_TIME) {
        auto *free_cell = cell->findEmptyCell();
        if (free_cell != nullptr)
        {
            last_spawned = 0;
            auto *new_predator = new Predator(free_cell);
            free_cell->setObject(new_predator);
            free_cell->getOcean()->addStuff(new_predator);
            free_cell->getOcean()->predators++;
        }
    }
}

void Predator::move()
{
    auto* free_cell = cell->findEmptyCell();
    if(free_cell != nullptr)
    {
        cell->setObject(nullptr);
        free_cell->setObject(this);
        cell = free_cell;
    }
}

