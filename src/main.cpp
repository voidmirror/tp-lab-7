#include "Ocean_Enums.h"
#include "Ocean.h"
#include "Cell.h"
#include "Object.h"
#include "Predator.h"
#include "Prey.h"
#include <iostream>
#include <string>

int main() 
{
	Ocean* ocean = new Ocean(25, 25, 10, 100, 5, 20, 10, 15, 10, 10, 20, 90);
	std::string pred_result = ocean->get_state();
	std::cout << pred_result << "\n\n\n";
	ocean->update();
	std::string next_result = ocean->get_state();
	while (pred_result != next_result)
	{
		std::cout << pred_result << "\n";
		pred_result = next_result;
		ocean->update();
		next_result = ocean->get_state();
	}
	return 0;
}