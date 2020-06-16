//
// Created by sdanilov on 4/14/2020.
//

#include "ocean.h"
#include <map>
#include <iostream>
#include <time.h>

using namespace std;

void Ocean::fillOcean(int size_c){
    size = size_c;
    for (int i = 0; i < size_c; i++){
        matrix.emplace_back();
        for (int j = 0; j < size_c; j++){
            matrix[i].push_back(new Cell(this));
            matrix[i][j]->object = ObjectManufacture::newRandomObject(matrix[i][j]); 
        }
    }
}

Cell* Ocean::getRandomCellfromOcean(){
    int i = rand() % size;
    int j = rand() % size;
    return matrix[i][j];
};
bool Ocean::check() {
	int count_prey = 0;
	int count_pred = 0;
	for (auto& i : matrix) {
		for (int j = 0; j < matrix.size(); j++) {
			if (i[j]->type == "prey") {
				count_prey++;
			}
			else if (i[j]->type == "predator") {
				count_pred++;
			}
		}
	}
	if (count_prey == 0 || count_pred == 0) {
		cout << endl << "Apocalipsis :(";
		return false;
	}
	return true;
}
void Ocean::run(){
	do {
		for (auto& i : matrix) {
			for (int j = 0; j < matrix.size(); j++) {
				i[j]->live();
			}
		}
		_sleep(1000);
		print();
	} while (check());
}

void Ocean::print(){
    for (auto & i : matrix){
        for (int j = 0; j < matrix.size(); j++){
			char symbol;
			if (i[j]->type == "stone") {
				symbol = 'o';
			}
			else if (i[j]->type == "prey") {
				symbol = '>';
			}else if (i[j]->type == "predator") {
				symbol = 'W';
			}
			else {
				symbol = '.';
			}

            cout << symbol;
        }
        cout << endl;
    }
	cout << endl;
}