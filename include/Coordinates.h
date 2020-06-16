//
//  Coordinates.h
//  lab7
//
//  Created by Андрей Журавлев on 16.04.2020.
//  Copyright © 2020 Андрей Журавлев. All rights reserved.
//

#ifndef Coordinates_h
#define Coordinates_h
#include <vector>

typedef size_t coord_t;

struct Point {
	coord_t x, y;
	
	Point(coord_t x, coord_t y) : x(x), y(y) {}
};

#endif /* Coordinates_h */
