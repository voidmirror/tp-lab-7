#include "Prey.h"
#include "Cell.h"
#include "Ocean.h"
#include <cstdlib>


Prey::Prey(Coordinates coordinates, Ocean *ocean) : LivingObject(coordinates, ocean) {
    character = '+';
}

void Prey::live() {
    motion();
    reproduct();
}

bool Prey::checkCell(Cell *cell) {
    return cell->isEmpty();
}

void Prey::eat(Cell *cell) {}

void Prey::reproduct() {
    if (timeToReproduction == 0) {
        std::vector<Cell *> places = getNeighbouredCells();

        for (int i = places.size() - 1; i >= 0; i--) {
            if (!places[i]->isEmpty()) {
                places.erase(places.begin() + i);
            }
        }
        if (places.size() != 0) {
            int index = rand() % places.size();
            Prey *littlePrey = new Prey(*places[index]->getLocation(), ocean);
            littlePrey->birth();
        }
        timeToReproduction = 5;
    } else {
        timeToReproduction--;
    }
}

std::string Prey::getName() {
    return "Prey";
}