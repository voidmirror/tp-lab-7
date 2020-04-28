//
// Created by Anton Korkunov on 02/04/2020.
//

#include "ObjectTypes.h"
#include "Cell.h"

Stone::Stone(){
cell=nullptr;
};

 void Stone::live() {
//do nothing
};

 std::string Stone::type() {
    return STONE_N;
};

 Prey::Prey(int intrv_of_birth, int intrv_of_death){
    this->intrv_of_birth=intrv_of_birth;
    this->intrv_of_death=intrv_of_death;
    cell=nullptr;
 };

void Prey::Move(){
    Cell* tmp = cell->CheckAround();
    if(tmp==nullptr) return;
    cell->setObject(nullptr);
    setCell(tmp);
    cell->setObject(this);
}

void Prey::Reproduce(){
    Cell* tmp = cell->CheckAround();
    if(tmp==nullptr) return;
    tmp->setObject(new Prey(Preprod,Plife));
    tmp->getObject()->setCell(tmp);
    tmp->Call_to_add();
};

void Prey::live() {
Move();
if(intrv_of_death==0){
    cell->killMe();
    return;
}
intrv_of_death--;
if(intrv_of_birth==0) {
    Reproduce();
    intrv_of_birth=Preprod;
}
intrv_of_birth--;
};

std::string Prey::type() {
  return PREY_N;
};

Predator::Predator(int intrv_of_birth, int intrv_of_death,int hunger):Prey(intrv_of_birth, intrv_of_death){
   this->hunger=hunger;
};
void Predator::Reproduce(){
    Cell* tmp = cell->CheckAround();
    if(tmp==nullptr) return;
    tmp->setObject(new Predator(PRreprod,PRlife,PRhunger));
    tmp->getObject()->setCell(tmp);
    tmp->Call_to_add();
};
std::string Predator::type() {
return PREDATOR_N;
};

void Predator::live() {
    Move();
    if(intrv_of_death==0 or hunger==0){
        cell->killMe();
        return;
    }
    intrv_of_death--;
    if(intrv_of_birth<=0 and hunger>=PRhunger) {
        Reproduce() ;
        intrv_of_birth=PRreprod;
    }
    intrv_of_birth--;
    if(hunger<PRhunger) Hunt();
    hunger--;
};

void Predator::Hunt(){
    Cell* tmp = cell->CheckAround_for_Prey();
    if(tmp==nullptr) return;
    tmp->killMe();
    cell->setObject(nullptr);
    setCell(tmp);
    cell->setObject(this);
    hunger+=2;
};