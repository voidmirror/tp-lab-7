//
//  Point.hpp
//  Ocean
//
//  Created by Олеся Мартынюк on 05.05.2020.
//  Copyright © 2020 Olesia Martinyuk. All rights reserved.
//

#ifndef Point_hpp
#define Point_hpp

#include <stdio.h>
#include <vector>

typedef size_t coord_t;

struct Point {
   coord_t x, y;

   Point(coord_t x, coord_t y) : x(x), y(y) {}
};

#endif /* Point_hpp */
