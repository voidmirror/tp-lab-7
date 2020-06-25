#include <iostream>
#include <vector>
#include <ctime>
#include <Windows.h>
#include "Cell.h"

using namespace std;

int main() {
	srand(time(0));



	Object *obj = new Object(4);
	(*obj).set_fertility(4);
	cout << (*obj).get_fertility();



	int n = 22;
	vector <vector <Cell*>> field;
	field.resize(n);
	for (int i = 0; i < n; i++) {
		field[i].resize(n);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			field[i][j] = new Cell();
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			(*field[i][j]).print_cell();
		}
		cout << endl;
	}



	//int counter_prey = 1;
	//while (counter_prey > 0) {
	//	counter_prey = 0;
	//	//system("cls");
	//	for (int i = 1; i < n - 1; i++) {
	//		for (int j = 1; j < n - 1; j++) {
	//			field[i][j]->release_cell_objects(&field, i, j);
	//		}
	//	}
	//	for (int i = 1; i < n - 1; i++) {
	//		for (int j = 1; j < n - 1; j++) {
	//			field[i][j]->to_the_future();
	//			field[i][j]->add_void_cell();
	//			field[i][j]->print_cell();
	//		}
	//		cout << endl;
	//	}

	//	for (int i = 1; i < n - 1; i++) {
	//		for (int j = 1; j < n - 1; j++) {
	//			for (int k = 0; k < field[i][j]->get_objects().size(); k++) {
	//				if (field[i][j]->get_objects()[i]->get_state() == 2) {
	//					counter_prey++;
	//				}
	//			}
	//			/*if ([&](){
	//				int tmp = 0;
	//				for (int k = 0; k < field[i][j]->get_objects().size(); k++) {
	//					if (true) {
	//						return true;
	//					}
	//				}
	//			})*/
	//		}
	//	}
	//}




	cout << "The End of Game Ocean" << endl;
/*
	cout << endl << endl;

	Cell* cell = new Cell();
	
	for (int i = 0; i < (*cell).get_objects().size(); i++) {
		cout << (*cell).get_objects()[i]->get_state() << " ";
	}
	cout << endl;

	(*cell).sort_objects();

	for (int i = 0; i < (*cell).get_objects().size(); i++) {
		cout << (*cell).get_objects()[i]->get_state() << " ";
	}
	cout << endl;*/
/*
	vector <vector <Cell*>> mat;
	vector <vector <Cell*>> copy;
	mat.resize(n);
	for (int i = 0; i < n; i++) {
		mat[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = new Cell();
		}
	}
	copy.resize(n);
	for (int i = 0; i < n; i++) {
		copy[i].resize(n);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			copy[i][j] = new Cell();
		}
	}

	*/
}