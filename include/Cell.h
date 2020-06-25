#ifndef Cell_H
#define Cell_H
#include <vector>
#include "Object.h"
using namespace std;
class Cell
{
public:
	//void changeStateNow(int s);	// stay
	//void changeStateFuture(int s);	// stay
	//void printState();	// stay
	//int getStateNow();	// stay
	//void updateNextGeneration();	// stay
	//void updateCellClass(vector <vector <Cell*>> mat, int iMat, int jMat);	// stay
	//Cell();

	void to_the_future();
	void release_cell_objects(vector <vector <Cell*>> *field, int cur_i, int cur_j);
	void sort_objects();
	int fight();
	void after_fight(int pred);
	int num_of_objects(int state);
	void increase_fertility();
	void delete_all_with_state_1000();
	void move_prepare(vector <vector <Cell*>> *field, int cur_i, int cur_j);
	void print_cell();
	void remove_void_cell();
	void add_void_cell();
	void add_future_void_cell();
	void remove_future_void_cell();
	bool isEmpty();

	vector <Object*> get_objects();
	vector <Object*> get_future_objects();

	Cell();

private:
	vector <Object*> objects;
	vector <Object*> future_objects;
};

#endif