#include <iostream>
#include "Ocean.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"

using namespace std;

int main() {
    std::srand(std::time(nullptr));
    Ocean ocean;
    std::list<Object*> lst;
    for(int i = 0; i < N*M/5; i++) {
        Prey* prey1 = new Prey();
        Prey* prey2 = new Prey();
        Predator* predator = new Predator();
        Stone* stone = new Stone();
        Coral* coral = new Coral();
        lst.push_back(prey1);
        lst.push_back(prey2);
        lst.push_back(predator);
        lst.push_back(stone);
        lst.push_back(coral);
    }
    ocean.addObjects(lst);

    ocean.run(50);
}
