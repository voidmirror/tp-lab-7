#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Ocean.h"
#include "Cell.h"
#include "Object.h"
#include "common.h"
#include "Fishes.h"

#define MAIN 1
#define CREATOR 0

#if (CREATOR == 1)
bool arr[30][30];

int main()
{
	freopen("output.txt", "w", stdout);
	for (unsigned int i = 0; i < 30; i++)
	{
		for (unsigned int j = 0; j < 30; j++)
			arr[i][j] = true;
	}

	for (unsigned int i = 0; i < 700; i++)
	{
		unsigned int tmp = rand() % 30;
		unsigned int tmp2 = rand() % 30;

		if (i < 100)
			cout << "Predator ";
		else if (i < 700)
			cout << "Prey ";
		else if (i < 750)
			cout << "Stone ";
		while (arr[tmp][tmp2] == false)
		{
			tmp = rand() % 30;
			tmp2 = rand() % 30;
		}
		arr[tmp][tmp2] = false;
		cout << tmp << " " << tmp2 << endl;
	}
	getchar();
	return 0;
}

#elif (MAIN == 1)
using namespace std;

int main()
{
	Ocean* oc = new Ocean();
	oc->print();
	oc->run(30);


	getchar();
}

#endif