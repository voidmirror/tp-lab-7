//
//  main.cpp
//  lab7
//
//  Created by Андрей Журавлев on 16.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#include <iostream>
#include "Factory.h"

int main(int argc, const char * argv[]) {
	// insert code here...
	srand(time(NULL));
	Ocean o(6, 6);
	o.addObjects(STONE, 5);
	o.addObjects(PREY, 10);
	o.addObjects(PREDATOR, 7);
	o.shuffle();
	o.printOcean();
	while (o.getState()) {
		o.run();
		o.printOcean();
	}
}
