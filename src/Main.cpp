#include "Ocean.h"
#include "Prey.h"
#include "Cell.h"
#include <Windows.h>

int main() {
    Ocean ocean = Ocean(50,10);
    ocean.createObjects();
    for (int i = 0; i < 20; i++) {
        std::vector<LivingObject*> copyLivingObjects(ocean.livingObjects);

        for (int j = 0; j < copyLivingObjects.size(); j++) {
            if (ocean.isExist(j, copyLivingObjects[j])) {
                copyLivingObjects[j]->live();
            }
        }
        for(int j = 0; j < ocean.height; j++){
            for(int k = 0; k < ocean.width; k++){
                ocean.cells[j][k].printView();
            }
            std::cout << "\n";
        }
        Sleep(1000);
    }
}