#include "Ocean.h"
#include "Prey.h"
#include "Predator.h"
#include "Stone.h"
#include "Coral.h"

Ocean::Ocean() 
{
	cells = new Cell*[N];
	for (size_t i(0); i < N; i++) 
	{
		cells[i] = new Cell[M];
		for (size_t j(0); j < M; j++)
		{
			cells[i][j].init({ i, j }, this);
		}	
	}
}

Ocean::~Ocean() 
{
	for (int i(0); i < N; i++)
	{
		delete[] cells[i];
	}
	delete[] cells;
	for (auto obj_ : stuff)
	{
		delete obj_;
	}
}

void Ocean::print() const 
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (cells[i][j].get_object())
			{
				cout << cells[i][j].get_object()->get_symbol();
			}
			else
			{
				cout << '.';
			}
		}
		cout << endl;
	}
}

void Ocean::add_stuff(Object *obj_) 
{
	stuff.push_back(obj_);
}

void Ocean::delete_object(Object *obj_) 
{
	obj_->get_cell()->kill_me();
}

void Ocean::add_objects(ObjType type_, unsigned int count_)
{
	int count = count_;
	while (count > 0)
	{
		bool flag = false;
		int k = 0;
		int x = rand() % N;
		int y = rand() % M;
		while (cells[x][y].get_object() != nullptr && k < TRY_)
		{
			int x = rand() % N;
			int y = rand() % M;
			k++;
		}
		Object* object = nullptr;
		if (k == TRY_)
		{
			not_find_their_place++;
		}
		else
		{
			switch (type_)
			{
			case ObjType::PREDATOR:
				object = new Predator(&cells[x][y]);
				count_pred++;
				break;
			case ObjType::PREY:
				object = new Prey(&cells[x][y]);
				count_prey++;
				break;
			case ObjType::STONE:
				object = new Stone(&cells[x][y]);
				count_stone++;
				break;
			case ObjType::CORAL:
				object = new Coral(&cells[x][y]);
				count_coral++;
				break;
			default:
				break;
			}
			this->add_stuff(object);
			cells[x][y].set_object(object, false, type_);
		}
		count--;
	}
}

Cell* Ocean::try_find_empty_cell(Pair crd_) const
{
	for (int i = 0; i < TRY_; i++)
	{
		size_t x_n = crd_.x + rand() % 3 - 1;
		size_t y_n = crd_.y + rand() % 3 - 1;
		if (x_n < N && y_n < M)
		{
			if(cells[x_n][y_n].get_object() == nullptr)
			{
				return &cells[x_n][y_n];
			}
		}
	}
	return nullptr;
}

Cell* Ocean::find_cell(Pair crd_)
{
	for (int i = 0; i < TRY_; i++)
	{
		size_t x_n = crd_.x + rand() % 3 - 1;
		size_t y_n = crd_.y + rand() % 3 - 1;
		if (x_n < N && y_n < M)
		{
			if (cells[x_n][y_n].get_object() == nullptr)
			{
				return &cells[x_n][y_n];
			}
			if (cells[x_n][y_n].get_object()->get_type() == ObjType::PREDATOR)
			{
				suicide++;
				return &cells[x_n][y_n];
			}
		}
	}
	return nullptr;
}

Cell* Ocean::try_find_prey(Pair crd_) const
{
	for (int i = 0; i < TRY_HUNT; i++) 
	{
		size_t x_n = crd_.x + rand() % 3 - 1;
		size_t y_n = crd_.y + rand() % 3 - 1;
		if (x_n < N && y_n < M)
		{
			if (cells[x_n][y_n].get_object())
			{
				if (cells[x_n][y_n].get_object()->get_type() == ObjType::PREY)
				{
					return &cells[x_n][y_n];
				}
			}
		}
	}
	return nullptr;
}

void Ocean::run()
{
	if (stuff.size() == 0)
	{
		cout << "Add some fish plz ... Oo" << endl;
		return;
	}

	for (auto i = stuff.begin(); i != stuff.end();)
	{
		if ((*i)->live() == false)
		{	
			Cell*cell = nullptr;
			switch ((*i)->get_type())
			{
				case ObjType::PREDATOR:
					count_pred--;
					break;
				case ObjType::PREY:
					count_prey--;
					break;
				case ObjType::STONE:
					count_stone--;
					break;
				case ObjType::CORAL:
					cell = (*i)->get_cell();
					count_coral--;
					break;
				default:
					break;
			}

			delete_object(*i);
			stuff.erase(i++);

			if (cell)
			{
				Object* object = new Stone(cell);
				this->add_stuff(object);
				cell->set_object(object, false, ObjType::STONE);
				count_stone++;
			}
		}
		else
		{
			i++;
		}
	}
}
