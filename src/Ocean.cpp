#include "Common.h"
#include "Object.h"
class Cell;
class Ocean;
#include "Ocean.h"
#include "Cell.h"

Ocean::Ocean()
{
	cells.resize(M);
	for (int i = 0; i < M; i++)
	{
		cells[i].resize(N);
	}

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			Cell* tmp = new Cell;
			cells[i][j] = tmp;
			(cells[i][j])->init({ i, j }, this);
		}
}



	

void Ocean::print()
{
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if ((cells[i][j]->obj) != nullptr)
			{
				if ((cells[i][j]->obj)->getSymbol() == '#')
					cout << "#";
				if ((cells[i][j]->obj)->getSymbol() == 'S')
					cout << "S";
				if ((cells[i][j]->obj)->getSymbol() == 'f')
					cout << "f";
				



			}
			else cout << ".";



		}
		cout << "\n";
	}
}


void Ocean::addObjects(int numStone, int numPrey, int numPred)
{
	int flag = 1;

	for (int i = 0; i < numStone; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y])->obj) == nullptr)
			{
				Object* tmp = new Stone(cells[x][y]);
				cells[x][y]->setObject(tmp);
				stuff.push_back(tmp);
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	}

	for (int i = 0; i < numPrey; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y])->obj) == nullptr)
			{
				Object* tmp = new Prey(cells[x][y]);
				cells[x][y]->setObject(tmp);
				stuff.push_back(tmp);
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	}

	for (int i = 0; i < numPred; i++)
	{
		while (flag)
		{
			srand(time(0));
			int x = rand() % M;
			int y = rand() % N;
			if (((cells[x][y])->obj) == nullptr)
			{
				Object* tmp = new Predator(cells[x][y]);
				cells[x][y]->setObject(tmp);
				stuff.push_back(tmp);
				flag = 0;
				cout << x << ' ' << y << endl;
			}
		}
		flag = 1;

	}
}

void Ocean::run()
{
	for (Object* obj : stuff)
	{
		if ((obj->type) != STONE)
		{
			Pair location = ((obj->getObject())->cell)->crd;
			int x2 = -1 + rand() % 3;
			int y2 = -1 + rand() % 3;
			obj->live();
			if (((location.x + x2) < M) && ((location.y + y2) < N) && ((location.x + x2) >= 0) && ((location.y + y2) >= 0) && (cells[location.x + x2][location.y + y2]->obj == nullptr))
			{
				obj->cell->killMe();
				//obj->setCell(&cells[location.x + x2][location.y + y2]);
				cells[location.x + x2][location.y + y2]->setObject(obj);

			}

		}
	}
}
void Ocean::eat()
{
	int flag;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			flag = 0;
			if (((cells[i][j]->obj) != nullptr) && (((cells[i][j]->obj)->type) == PREDATOR))
			{
				if (((i + 1) < M) && (cells[i + 1][j]->obj != nullptr) && ((cells[i + 1][j]->obj)->type == PREY))
				{
					(cells[i + 1][j]->obj)->life = EndLife;
					flag = 1;
				}
				if (((i - 1) >= 0) && (cells[i - 1][j]->obj != nullptr) && ((cells[i - 1][j]->obj)->type == PREY))
				{
					(cells[i - 1][j]->obj)->life = EndLife;
					flag = 1;
				}
				if (((j + 1) < N) && (cells[i][j + 1]->obj != nullptr) && ((cells[i][j + 1]->obj)->type == PREY))
				{
					(cells[i][j + 1]->obj)->life = EndLife;
					flag = 1;
				}
				if (((j - 1) >= 0) && (cells[i][j - 1]->obj != nullptr) && ((cells[i][j - 1]->obj)->type == PREY))
				{
					(cells[i][j - 1]->obj)->life = EndLife;
					flag = 1;
				}


				if (flag == 0)
					(cells[i][j]->obj)->lifeChance--;
			}



		}
}
void Ocean::Kill()
{
	for (auto it = stuff.begin(); it != stuff.end();)
	{
		if ((((*it)->life) >= EndLife) || (((*it)->lifeChance) <= 0))
		{
			(*it)->cell->killMe();

			delete* it;
			it = stuff.erase(it);
		}
		else ++it;



	}
}
void Ocean::reproduction()
{
	srand(time(0));
	int flag = 1;
	for (auto it = stuff.begin(); it != stuff.end(); it++)
	{
		if (((*it)->life) == YearReproduct)
		{
			if ((*it)->type == PREY)
			{
				Pair location = (((*it)->getObject())->cell)->crd;

				if (((location.x + 1) < M) && ((location.y) < N) && ((location.x + 1) >= 0) && ((location.y) >= 0) && (cells[location.x + 1][location.y]->obj == nullptr) && (flag == 1))
				{
					Prey* tmp = new Prey(cells[location.x + 1][location.y]);
					(cells[location.x + 1][location.y])->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}

				if (((location.x - 1) < M) && ((location.y) < N) && ((location.x - 1) >= 0) && ((location.y) >= 0) && (cells[location.x - 1][location.y]->obj == nullptr) && (flag == 1))
				{
					Prey* tmp = new Prey(cells[location.x - 1][location.y]);
					cells[location.x - 1][location.y]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}

				if (((location.x) < M) && ((location.y + 1) < N) && ((location.x) >= 0) && ((location.y + 1) >= 0) && (cells[location.x][location.y + 1]->obj == nullptr) && (flag == 1))
				{
					Prey* tmp = new Prey(cells[location.x][location.y + 1]);
					cells[location.x][location.y + 1]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}

				if (((location.x) < M) && ((location.y - 1) < N) && ((location.x) >= 0) && ((location.y - 1) >= 0) && (cells[location.x][location.y - 1]->obj == nullptr) && (flag == 1))
				{
					Prey* tmp = new Prey(cells[location.x][location.y - 1]);
					cells[location.x][location.y - 1]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}
				flag = 1;

			}
			if ((*it)->type == PREDATOR)
			{
				Pair location = (((*it)->getObject())->cell)->crd;

				if (((location.x + 1) < M) && ((location.y) < N) && ((location.x + 1) >= 0) && ((location.y) >= 0) && (cells[location.x + 1][location.y]->obj == nullptr) && (flag == 1))
				{
					Predator* tmp = new Predator(cells[location.x + 1][location.y]);
					cells[location.x + 1][location.y]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}
				if (((location.x - 1) < M) && ((location.y) < N) && ((location.x - 1) >= 0) && ((location.y) >= 0) && (cells[location.x - 1][location.y]->obj == nullptr) && (flag == 1))
				{
					Predator* tmp = new Predator(cells[location.x - 1][location.y]);
					cells[location.x - 1][location.y]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;

				}

				if (((location.x) < M) && ((location.y - 1) < N) && ((location.x) >= 0) && ((location.y - 1) >= 0) && (cells[location.x][location.y - 1]->obj == nullptr) && (flag == 1))
				{
					Predator* tmp = new Predator(cells[location.x][location.y - 1]);
					cells[location.x][location.y - 1]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;
				}
				if (((location.x) < M) && ((location.y + 1) < N) && ((location.x) >= 0) && ((location.y + 1) >= 0) && (cells[location.x][location.y + 1]->obj == nullptr) && (flag == 1))
				{
					Predator* tmp = new Predator(cells[location.x][location.y + 1]);
					cells[location.x][location.y + 1]->setObject(tmp);
					stuff.push_back(tmp);
					flag = 0;
				}
			}
		}
	}
}