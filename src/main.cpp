#include <iostream>
#include "Ocean.h"
#include "Cell.h"
#include "common.h"
#include <iomanip>
#include "ObjectTypes.h"
using namespace std;
//MxN
int main() {

    auto* foc=new Ocean();

    foc->addObjects();
    for (int i = 0; i < 1350; i++) {//5350
        cout<<"________________ITERATION - "<< i <<"___________________\n";
        foc->print();
        foc->run();
        cout<<"________________________________________________\n";
       }
    foc->print();
   // delete(foc);



    return 0;
}