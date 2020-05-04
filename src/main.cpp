//
// Created by sdanilov on 4/14/2020.
// stable works 11 23 4 14 2020
//
#include "ocean.h"
#include <iostream>
#include <time.h>
using namespace std;

int main(){
	cout << "Ocean started!!!" << endl;
	srand(time(NULL));
	Ocean ocean;
    ocean.fillOcean(20);
	ocean.run();
}