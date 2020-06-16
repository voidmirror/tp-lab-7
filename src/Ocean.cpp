#include "Ocean.h"
#include "Stone.h"
#include "Prey.h"
#include "Predator.h"
#include "windows.h"

Ocean::Ocean() {
	cells = new Cell *[rows];
	for (size_t i = 0; i < rows; i++) {
		cells[i] = new Cell[cols];
		for (size_t j = 0; j < cols; j++) {
			cells[i][j].init({ static_cast<coord_t>(i), static_cast<coord_t>(j) }, this);
		}
	}
}

Ocean::~Ocean() {
	for (size_t i = 0; i < rows; i++)
		delete[] cells[i];
	delete cells;
	for (unsigned i = 0; i < stuff.size(); i++)
		delete stuff[i];
	stuff.clear();
}

void Ocean::add_objects(ObjectType type, int count) {
	for (int k = 0; k < count; k++) {
		Cell *emptyCell = &cells[rand() % rows][rand() % cols];
		while (emptyCell->get_object() != nullptr)
			emptyCell = &cells[rand() % rows][rand() % cols];
		switch (type) {
		case (ObjectType::STONE): {
			Stone *stone = new Stone(emptyCell);
			emptyCell->set_object(stone);
			stuff.push_back(stone);
			break;
		}
		case (ObjectType::PREY): {
			Prey *prey = new Prey(emptyCell);
			emptyCell->set_object(prey);
			stuff.push_back(prey);
			break;
		}
		case (ObjectType::PREDATOR): {
			Predator *predator = new Predator(emptyCell);
			emptyCell->set_object(predator);
			stuff.push_back(predator);
			break;
		}
		default:
			break;
		}
	}
}

void Ocean::delete_object(Object* object) {
	for (auto item = stuff.begin(); item != stuff.end(); item++) {
		if (*item == object) {
			(*item)->get_cell()->clear_cell();
			delete *item;
			stuff.erase(item);
			break;
		}
	}
}

void Ocean::print() const {
	for (size_t i = 0; i < rows; i++) {
		for (size_t j = 0; j < cols; j++) {
			if (cells[i][j].get_object() == nullptr) {
				cout << '.';
				continue;
			}
			ObjectType type = cells[i][j].get_object()->get_type();
			if (type == ObjectType::PREY) cout << "F";
			else if (type == ObjectType::PREDATOR) cout << "S";
			else if (type == ObjectType::STONE) cout << "#";
		}
		cout << "\n";
	}
}

void Ocean::run() {
	int preyNum, predNum;
	int iteration = 1;
	ObjectType type;
	while (1) {
		preyNum = 0;
		predNum = 0;
		for (int i = 0; i < stuff.size(); i++) {
			type = stuff[i]->get_type();
			if (type == ObjectType::PREY) preyNum++;
			else if (type == ObjectType::PREDATOR) predNum++;
		}

		if (preyNum == 0 || predNum == 0)
			break;

		for (int i = 0; i < stuff.size(); i++)
			stuff[i]->live();

		Sleep(100);
		system("cls");
		print();
		cout << "Iteraion:" << iteration << " | Predators:" << predNum << " | Preys:" << preyNum;
		iteration++;
	}
}

Cell* Ocean::free_cell(Pair coord) {
	vector<char> x_arr = { 0, 0, 1, 1, 1, -1, -1, -1 };
	vector<char> y_arr = { -1, 1, 0, 1, -1, 0, 1, -1 };
	int len = 9;

	while (--len) {
		size_t i = rand() % len;
		int new_x = coord.x + x_arr[i];
		int new_y = coord.y + y_arr[i];

		if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {
			if (cells[new_x][new_y].get_object() == nullptr)
				return &cells[new_x][new_y];
		}
		x_arr.erase(x_arr.begin() + i);
		y_arr.erase(y_arr.begin() + i);
	}
	return nullptr;
}

Cell* Ocean::prey_cell(Pair coord) {
	vector<int> x_arr = { 0, 0, 1, 1, 1, -1, -1, -1 };
	vector<int> y_arr = { -1, 1, 0, 1, -1, 0, 1, -1 };
	int len = 9;
	while (--len) {
		size_t i = rand() % len;
		int new_x = coord.x + x_arr[i];
		int new_y = coord.y + y_arr[i];

		if (new_x >= 0 && new_x < rows && new_y >= 0 && new_y < cols) {

			if (cells[new_x][new_y].get_object() != nullptr && cells[new_x][new_y].get_object()->get_type() == ObjectType::PREY)
				return &cells[new_x][new_y];
		}
		x_arr.erase(x_arr.begin() + i);
		y_arr.erase(y_arr.begin() + i);
	}
	return nullptr;
}