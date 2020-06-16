//
// Created by Ignatovskiy Nikita on 28.04.2020.
//

#ifndef LAB7_PREY_H
#define LAB7_PREY_H


 #include "cell.h"


 class Cell;
 class Ocean;
 class Prey : public Object
 {

 public:

     Prey(Cell* cell);

     bool live() override;
     char getSymbol() override;
     void move() override;
     void reproduce() override;

 };


#endif //LAB7_PREY_H
