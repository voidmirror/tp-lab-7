#include "Ocean.h"
int main()
{
    Ocean ocean(20, 20, 130, 10, 50);
    int reason;
    while (!(reason = ocean.GO()))
    {
        #ifdef _WIN32
           system("cls");
        #else
           system("clear");
        #endif
        ocean.print();
        std::cout<<"Press return key to continue";
        std::cout<<"\n";
        #ifdef _WIN32
            system("pause");
        #else
            system("read");
        #endif
    }
    switch (reason)
    {
        case 1:
            std::cout<<"The predators ate all the prey"<< std::endl;
            break;
        case 2:
            std::cout<<"All the predators are dead"<< std::endl;
            break;
        default:
            break;
    }
    return 0;
}
