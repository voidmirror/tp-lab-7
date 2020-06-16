#include "ocean.h"

int main (void) {
	
    system("clear");

    // 1 - высота(h)
    // 2 - ширина(w)
    Ocean ocean(50, 100);
    // камни, жертвы, хишники
    ocean.init(100, 250, 25);

    ocean.printOcean(); 
    
    bool iterate = true;
    while(iterate)
    {
        ocean.iterate();
        usleep(200000);
        system("clear");
        ocean.printOcean();
        iterate = ocean.iterationStatus();
    }

	return 0;
}