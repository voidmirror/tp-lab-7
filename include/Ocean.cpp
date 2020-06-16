#include <cstdlib>
#include <ctime>
#include <algorithm>
#include "Ocean.h"
#include "Predator.h"
#include "Prey.h"
#include "Stone.h"

Ocean::Ocean(int width, int height, int prey_amount, int predator_amount, int stone_chance,
	int predator_capacity, int predator_initial_fullness, int predator_fullness_to_reproduce, int predator_fullness_by_prey,
	int prey_age_to_reproduce, int prey_age_to_die, int prey_chance_to_reproduce)
{
	this->width = width;				// set class this->fields
	this->height = height;
	this->predator_capacity = predator_capacity;
	this->predator_initial_fullness = predator_initial_fullness;
	this->predator_fullness_to_reproduce = predator_fullness_to_reproduce;
	this->predator_fullness_by_prey = predator_fullness_by_prey;
	this->prey_age_to_reproduce = prey_age_to_reproduce;
	this->prey_age_to_die = prey_age_to_die;
	this->prey_age_to_die = prey_chance_to_reproduce;
	this->prey_amount = prey_amount;
	this->predator_amount = predator_amount;
	this->prey_chance_to_reproduce = prey_chance_to_reproduce;

	if (prey_amount + predator_amount > width * height) // correct fish amounts if necessary 
	{
		predator_amount = prey_amount = width * height / 4;
	}
	this->field = std::vector<std::vector<Cell*>>(height, std::vector<Cell*> (width)); // generate this->field with cells
	this->objects = std::vector<Object*>(prey_amount + predator_amount);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			this->field[i][j] = new Cell(i, j);
		}
	}

	srand(time(NULL));
	for (int i = 0; i < predator_amount; i++)		// generate predators
	{
		int cell_number = rand() % (width * height);
		while (this->field[cell_number / width][cell_number % width]->get_object() != nullptr)
		{
			cell_number += 1;
			cell_number %= width * height;
		}
		Predator* predator = new Predator(this->field[cell_number / width][cell_number % width], predator_capacity, predator_initial_fullness, predator_fullness_to_reproduce, predator_fullness_by_prey);
		this->field[cell_number / width][cell_number % width]->set_object(predator);
		objects[i] = predator;
	}

	for (int i = 0; i < prey_amount; i++)		// generate prey
	{
		int cell_number = rand() % (width * height);
		while (this->field[cell_number / width][cell_number % width]->get_object() != nullptr)
		{
			cell_number += 1;
			cell_number %= width * height;
		}
		Prey* prey = new Prey(this->field[cell_number / width][cell_number % width], prey_age_to_reproduce, prey_age_to_die, prey_chance_to_reproduce);
		this->field[cell_number / width][cell_number % width]->set_object(prey);
		objects[i + predator_amount] = prey;
	}

	for (int i = 0; i < height; i++)		// generate stones
	{
		for (int j = 0; j < width; j++) 
		{
			if (this->field[i][j]->get_object() == nullptr)
			{
				if (rand() % 100 <= stone_chance)
				{
					Stone* stone = new Stone(this->field[i][j]);
					this->field[i][j]->set_object(stone);
				}
			}
		}
	}
}

Ocean::~Ocean() 
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (this->field[i][j]->get_object() != nullptr) 
			{
				delete this->field[i][j]->get_object();
			}
			delete this->field[i][j];
		}
	}
}

std::string Ocean::get_state()
{
	std::string result = "";
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (this->field[i][j]->get_object() != nullptr)
			{
				result += this->field[i][j]->get_object()->draw();
			}
			else
			{
				result += '.';
			}
		}
		result += '\n';
	}
	return result;
}

void Ocean::update() 
{
	std::random_shuffle(this->objects.begin(), this->objects.end());

	for (int i = 0; i < objects.size(); i++)
	{
		Object* object = objects[i];
		Cell* cell = object->get_cell();
		int x = cell->get_x();
		int y = cell->get_y();

		Object_type up, down, left, right;

		//set up value
		if (x == 0)
		{
			up = Object_type::stone;
		}
		else if (this->field[x - 1][y]->get_object() == nullptr)
		{
			up = Object_type::empty_space;
		}
		else
		{
			up = this->field[x - 1][y]->get_object()->get_type();
		}

		//set down value
		if (x == height - 1)
		{
			down = Object_type::stone;
		}
		else if (this->field[x + 1][y]->get_object() == nullptr)
		{
			down = Object_type::empty_space;
		}
		else
		{
			down = this->field[x + 1][y]->get_object()->get_type();
		}

		//set left value
		if (y == 0)
		{
			left = Object_type::stone;
		}
		else if (this->field[x][y - 1]->get_object() == nullptr)
		{
			left = Object_type::empty_space;
		}
		else
		{
			left = this->field[x][y - 1]->get_object()->get_type();
		}

		//set right value
		if (y == width - 1)
		{
			right = Object_type::stone;
		}
		else if (this->field[x][y + 1]->get_object() == nullptr)
		{
			right = Object_type::empty_space;
		}
		else
		{
			right = this->field[x][y + 1]->get_object()->get_type();
		}

		Action action = object->live(up, down, left, right);

		switch (action)
		{
		// DIE SECTION
		case Action::die:
			this->field[x][y]->set_object(nullptr);
			objects.erase(objects.begin() + i);
			if (object->get_type() == Object_type::predator)
			{
				this->predator_amount--;
			}
			else
			{
				this->prey_amount--;
			}
			i--;
			delete object;
			break;

		// MOVE SECTION
		case Action::move_up:
			this->field[x][y]->set_object(nullptr);
			this->field[x - 1][y]->set_object(object);
			object->set_cell(this->field[x - 1][y]);
			break;
		case Action::move_down:
			this->field[x][y]->set_object(nullptr);
			this->field[x + 1][y]->set_object(object);
			object->set_cell(this->field[x + 1][y]);
			break;
		case Action::move_left:
			this->field[x][y]->set_object(nullptr);
			this->field[x][y - 1]->set_object(object);
			object->set_cell(this->field[x][y - 1]);
			break;
		case Action::move_right:
			this->field[x][y]->set_object(nullptr);
			this->field[x][y + 1]->set_object(object);
			object->set_cell(this->field[x][y + 1]);
			break;

		// REPRODUCE SECTION
		case Action::reproduce_up:
			if (object->get_type() == Object_type::predator)
			{
				Predator* predator = new Predator(this->field[x - 1][y], 
					this->predator_capacity, this->predator_initial_fullness, this->predator_fullness_to_reproduce, this->predator_fullness_by_prey);
				this->field[x - 1][y]->set_object(predator);
				this->predator_amount++;
			}
			else
			{
				Prey* prey = new Prey(this->field[x - 1][y], this->prey_age_to_reproduce, this->prey_age_to_die, this->prey_chance_to_reproduce);
				this->field[x - 1][y]->set_object(prey);
				this->prey_amount++;
			}
			break;
		case Action::reproduce_down:
			if (object->get_type() == Object_type::predator)
			{
				Predator* predator = new Predator(this->field[x + 1][y],
					this->predator_capacity, this->predator_initial_fullness, this->predator_fullness_to_reproduce, this->predator_fullness_by_prey);
				this->field[x + 1][y]->set_object(predator);
				this->predator_amount++;
			}
			else
			{
				Prey* prey = new Prey(this->field[x + 1][y], this->prey_age_to_reproduce, this->prey_age_to_die, this->prey_chance_to_reproduce);
				this->field[x + 1][y]->set_object(prey);
				this->prey_amount++;
			}
			break;
		case Action::reproduce_left:
			if (object->get_type() == Object_type::predator)
			{
				Predator* predator = new Predator(this->field[x][y - 1],
					this->predator_capacity, this->predator_initial_fullness, this->predator_fullness_to_reproduce, this->predator_fullness_by_prey);
				this->field[x][y-1]->set_object(predator);
				this->predator_amount++;
			}
			else
			{
				Prey* prey = new Prey(this->field[x][y - 1], this->prey_age_to_reproduce, this->prey_age_to_die, this->prey_chance_to_reproduce);
				this->prey_amount++;
			}
			break;
		case Action::reproduce_right:
			if (object->get_type() == Object_type::predator)
			{
				Predator* predator = new Predator(this->field[x - 1][y],
					this->predator_capacity, this->predator_initial_fullness, this->predator_fullness_to_reproduce, this->predator_fullness_by_prey);
				this->field[x][y + 1]->set_object(predator);
				this->predator_amount++;
			}
			else
			{
				Prey* prey = new Prey(this->field[x][y + 1], this->prey_age_to_reproduce, this->prey_age_to_die, this->prey_chance_to_reproduce);
				this->field[x][y + 1]->set_object(prey);
				this->prey_amount++;
			}
			break;
		
		// EAT SECTION
		case Action::eat_up:
			this->field[x][y]->set_object(nullptr);
			delete this->field[x - 1][y]->get_object();
			this->field[x - 1][y]->set_object(object);
			this->prey_amount--;
			break;
		case Action::eat_down:
			this->field[x][y]->set_object(nullptr);
			delete this->field[x + 1][y]->get_object();
			this->field[x + 1][y]->set_object(object);
			this->prey_amount--;
			break;
		case Action::eat_left:
			this->field[x][y]->set_object(nullptr);
			delete this->field[x][y - 1]->get_object();
			this->field[x][y - 1]->set_object(object);
			this->prey_amount--;
			break;
		case Action::eat_right:
			this->field[x][y]->set_object(nullptr);
			delete this->field[x][y + 1]->get_object();
			this->field[x][y + 1]->set_object(object);
			this->prey_amount--;
			break;

		default: break;
		}
	}
}

void Ocean::run()
{
	std::string pred_result = this->get_state();
	this->update();
	std::string next_result = this->get_state();
	while (pred_result != next_result && predator_amount != 0 && prey_amount != 0)
	{
		pred_result = next_result;
		this->update();
		next_result = this->get_state();
	}
}