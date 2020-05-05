#include <iostream>
#include "Ocean.hpp"
#include <stdlib.h>

#include <unistd.h>
#include <term.h>

int main(int argc, const char * argv[]) {
    Ocean ocean = Ocean();
    
    int preyValue, predValue, stoneValue;
    cout << "Enter number of preys >> ";
    cin >> preyValue;
    cout << "Enter number of predators >> ";
    cin >> predValue;
    cout << "Enter number of stones >> ";
    cin >> stoneValue;
    
    ocean.addObj(ObjType::PREDATOR, preyValue);
    ocean.addObj(ObjType::PREY, predValue);
    ocean.addObj(ObjType::STONE, stoneValue);

    while (true) {
        #ifdef _WIN32
               system("cls");
        #else
               system("clear");
        #endif
        ocean.run();
        int *res = ocean.print();
        char foo;
        cout << "Press enter to continue . . .";
        foo = cin.get();
        if (foo == 10){
            if (res[0] == 0 || res[1] == 0)
            {
                if (res[0] == 0) {
                    cout << "All preys died" << endl;
                }
                else {
                    cout << "All predators died" << endl;
                }
            }
            else{
                #ifdef _WIN32
                    system("pause");
                #else
                    system("read");
                #endif
            }
        }
    }
}
