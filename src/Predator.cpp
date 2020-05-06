#include "Predator.h"
#include "Cell.h"
#include "Ocean.h"


Predator::Predator(Coordinates coordinates, Ocean* ocean) : LivingObject(coordinates, ocean) {
    character = '~';
}

void Predator::eat(Cell* cell){
    auto prey = (LivingObject*)(cell->getObject());
    prey->die();
    Coordinates* coordCellTo = cell->getLocation();
    move(coordCellTo->x, coordCellTo->y);
    energy += 30;
}

void Predator::reproduct(){
    std::vector<Cell*> forBaby = getNeighbouredCells();

    for (int i = forBaby.size() - 1; i >= 0; i--) {
        if (!forBaby[i]->isEmpty()) {
            forBaby.erase(forBaby.begin() + i);
        }
    }
    if (forBaby.size() != 0) {
        int index = rand() % forBaby.size();
        auto littlePredator = new Predator(*forBaby[index]->getLocation(), ocean);
        littlePredator->birth();
        energy -= 100;
    }
}

Cell* Predator::findFood() {
    Cell* cellTo;
    cellTo = ocean->getCell(location.x, location.y - 1);
    if (isFood(cellTo)) {
        return cellTo;
    }
    cellTo = ocean->getCell(location.x+1, location.y);
    if (isFood(cellTo)) {
        return cellTo;
    }
    cellTo = ocean->getCell(location.x, location.y + 1);
    if (isFood(cellTo)) {
        return cellTo;
    }
    cellTo = ocean->getCell(location.x-1, location.y);
    if (isFood(cellTo)) {
        return cellTo;
    }
    return nullptr;
}

bool Predator::isFood(Cell* cell) {
    return cell && !cell->isEmpty() && cell->getObject()->getName() == "Prey";
}

void Predator::live() {
    Cell* cellTo = findFood();
    if (cellTo) {
        eat(cellTo);
    }
    else {
        motion();
    }
    energy -= 10;
    if (energy >= 190) {
        reproduct();
    }
    if (energy <= 0) {
        die();
    }
}

bool Predator::checkCell(Cell* cell) {
    return cell->isEmpty();
}

std::string Predator::getName() {
    return "Predator";
}
