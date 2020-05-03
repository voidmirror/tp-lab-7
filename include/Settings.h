//
//  Settings.h
//  lab7
//
//  Created by Андрей Журавлев on 22.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Settings_h
#define Settings_h

#define STONE_CHAR '#'
#define PREY_CHAR 'v'
#define PREDATOR_CHAR 'P'

#define PREY_REPRODUCE_PERIOD 10
#define PREDATOR_REPRODUCE_PERIOD 10

#define PREY_LIFETIME 20
#define PREDATOR_LIFETIME 15

#define NUMBER_OF_TRYS 10

enum ObjectTypes{
	STONE, PREY, PREDATOR
};

static char* typeNames[] = {"Stone", "Prey", "Predator"};



#endif /* Settings_h */
