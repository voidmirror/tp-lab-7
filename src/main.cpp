#include "Ocean.h"

int main() 
{
	srand((unsigned int)time(nullptr));
	Ocean ocean;
	ocean.add_objects(ObjType::PREY, 100);
	ocean.add_objects(ObjType::PREDATOR, 30);
	ocean.add_objects(ObjType::STONE, 5);
	ocean.add_objects(ObjType::CORAL, 5);

	int days = 0;
	while (ocean.count_prey != 0 && ocean.count_pred != 0 && days < MAX_DAYS)
	{
		ocean.run();
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
		ocean.print();
		cout << endl << "Count preditors : " << ocean.count_pred << endl;
		cout << "Count prey : " << ocean.count_prey << endl;
		cout << "Count coral : " << ocean.count_coral << endl;
		cout << "Count stone : " << ocean.count_stone << endl;
		cout << "Not find their place :c : " << ocean.not_find_their_place << endl;
		cout << "Suicide : " << ocean.suicide << endl;
		cout << "Day : " << ++days << endl;
		cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
	}
	if (ocean.count_pred == 0 && days != MAX_DAYS)  
	{
		cout << endl << endl << "\t\t<<< PREY WIN! >>>" << endl << endl;
	}
	if (ocean.count_prey == 0 && days != MAX_DAYS)
	{
		cout << endl << endl << "\t\t<<< PREDITOR WIN! >>>" << endl << endl;
	}
	if (days == MAX_DAYS)
	{
		cout << endl << endl << "\t    <<< To Be Continued >>>" << endl << endl;
	}
	return 0;
}
