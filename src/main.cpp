#include <iostream>
#include "Ocean.h"
using namespace std;

class Test{
    private:
    public:
        Test(){};
};

int main()
{
    Ocean* oc = new Ocean(4);
    oc->createCreatures(2,6,1);
    oc->dispMap();
    oc->startSim();
    /*oc->dispMap();
    for(int i = 0; i <= 20; i++){
        oc->startSim();
        cout<<i<<endl;
        oc->dispMap();
        cout<<i<<endl;
    }*/
    return 0;
}
