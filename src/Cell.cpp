#include <iostream>
#include <vector>
#include <algorithm>
#include "Cell.h"

using namespace std;

void Cell::to_the_future() {
	objects.resize(future_objects.size());
	for (int i = 0; i < future_objects.size(); i++) {
		objects[i] = future_objects[i];
	}
}

void Cell::sort_objects() {
	
	sort(objects.begin(),
		objects.end(), 
		[](Object  * a, Object  * b)
		{
		return (*a).get_state() < (*b).get_state();
		}
		);
}

int Cell::num_of_objects(int state) {
	int obj = 0;
	for each (Object* var in objects)
	{
		if ((*var).get_state() == state) {
			obj++;
		}
	}
	return obj;
}

int Cell::fight() {
	// num of predators
	int preds = 0;
	vector <int> pred_place;
	pred_place.resize(objects.size());

	preds = num_of_objects(3);

	if (preds > 0) {
		for (int i = 0; i < objects.size(); i++) {
			if ((*objects[i]).get_state() == 3) {
				pred_place.push_back(i);
			}
		}

		if (preds > 1) {
			return pred_place[rand() % pred_place.size()];
		}
		else {
			return pred_place[rand() % pred_place.size()] + 1000;
		}
	}
	else {
		return -1;
	}
}

// if no predators !!!!!!		<---
// pred - return of fight
void Cell::after_fight(int pred) {
	if (pred != -1) {
		if (pred - 1000 > -1) {
			pred -= 1000;
		}
		else {
			// subtraction predator's hp after fight
			(*objects[pred]).set_hp((*objects[pred]).get_hp() - 3);

			for (int i = 0; i < objects.size(); i++) {
				if (i != pred && (*objects[i]).get_state() == 3) {
					(*objects[i]).set_state(1000);	// not in range
				}
			}

			sort_objects();
			delete_all_with_state_1000();
		}
	}
}

void Cell::delete_all_with_state_1000() {
	while ((*objects[objects.size() - 1]).get_state() == 1000) {
		delete(objects[objects.size() - 1]);
		objects.pop_back();
	}
}

void Cell::increase_fertility() {
	for (int i = 0; i < objects.size(); i++) {
		(*objects[i]).set_fertility((*objects[i]).get_fertility() + 1);
		if ((*objects[i]).get_state() == 2 && (*objects[i]).get_fertility() == 3) {
			objects.push_back(new Object(2));
		}
		if ((*objects[i]).get_state() == 3 && (*objects[i]).get_fertility() == 13) {
			objects.push_back(new Object(3));
		}
	}
}

void Cell::move_prepare(vector <vector <Cell*>> *field, int cur_i, int cur_j) {
	// if neither void nor stone
	for (int i = 0; i < objects.size(); i++) {
		if ((*objects[i]).get_state() != 0 && (*objects[i]).get_state() != 1) {
			int itmp = rand() % 3;
			int jtmp = rand() % 3;
			cur_i -= 1;
			cur_j -= 1;

			if (itmp == 1 && jtmp == 1 || (((*field)[cur_i + itmp][cur_j + jtmp])->get_objects())[0]->get_state() == 1) {
				((*field)[cur_i + 1][cur_j + 1])->remove_future_void_cell();
				((*field)[cur_i + 1][cur_j + 1])->get_future_objects().push_back(objects[i]);
				cout << "chosen here" << endl;
			}
			else {
				((*field)[cur_i + itmp][cur_j + jtmp])->remove_future_void_cell();
				((*field)[cur_i + itmp][cur_j + jtmp])->get_future_objects().push_back(objects[i]);
				cout << "chosen " << itmp << " " << jtmp << endl;
			}
		}
	}
}

void Cell::remove_void_cell() {
	if (objects.size() > 1) {
		(*objects[0]).set_state(1000);
		delete_all_with_state_1000();
	}
}

void Cell::add_void_cell() {
	if (objects.empty()) {
		objects.push_back(new Object(0));
	}
}

void Cell::add_future_void_cell() {
	if (future_objects.empty()) {
		future_objects.push_back(new Object(0));
	}
}

void Cell::remove_future_void_cell() {
	if ((*future_objects[0]).get_state() == 0) {
		(*future_objects[0]).set_state(1000);
		delete_all_with_state_1000();
	}
}

void Cell::release_cell_objects(vector <vector <Cell*>> *field, int cur_i, int cur_j) {
	sort_objects();
	after_fight(fight());

	if (num_of_objects(3) == 1) {
		// set +2 hp for each prey in cell (feeding)
		((*objects[objects.size() - 1]).set_hp((*objects[objects.size() - 1]).get_hp() + num_of_objects(2) * 2));
		for (int i = 0; i < objects.size(); i++) {
			if ((*objects[i]).get_state() == 2) {
				(*objects[i]).set_state(1000);	// not in range
			}
		}

		delete_all_with_state_1000();
	}

	increase_fertility();
	add_future_void_cell();
	move_prepare(field, cur_i, cur_j);

}

void Cell::print_cell() {
	if ((*objects[objects.size() - 1]).get_state() == 0) {
		cout << "  ";
	}
	if ((*objects[objects.size() - 1]).get_state() == 1) {
		cout << "O ";
	}
	if ((*objects[objects.size() - 1]).get_state() == 2) {
		cout << "p ";
	}
	if ((*objects[objects.size() - 1]).get_state() == 3) {
		cout << "S ";
	}
}

bool Cell::isEmpty() {
	return this->get_objects().empty();
}

vector <Object*> Cell::get_objects() {
	return objects;
}

vector <Object*> Cell::get_future_objects() {
	return future_objects;
}

Cell::Cell() {
	future_objects.resize(0);
	int tmp = rand() % 100;
	if (tmp >= 0 && tmp < 10) {
		objects.push_back(new Object(0));
	}
	if (tmp >= 10 && tmp < 20) {
		objects.push_back(new Object(1));
	}
	if (tmp >= 20 && tmp < 80) {
		objects.push_back(new Object(2));
	}
	if (tmp >= 80 && tmp < 100) {
		objects.push_back(new Object(3));
	}
}