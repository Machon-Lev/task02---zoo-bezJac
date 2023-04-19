#include "Monkey.h"
#include <random>
#include <random_util.h>
#include <iostream>

#define LOWER__ROW_BOUND 0
#define UPPER__ROW_BOUND 19
#define LOWER__COLUMN_BOUND 0
#define UPPER__COLUMN_BOUND 39

Monkey::Monkey(std::string monkey_name, Location monkey_location) :Animal(monkey_name, monkey_location) {

	generate_direction();
	step_count = 0;
}
void Monkey::printDetails() const
{
	std::cout << "Monkey: ";
	Animal::printDetails();
}
char Monkey::getInitial() const
{
	return 'M';
}

void Monkey::move()
{
	if (is_freezed)
		Animal::move();
}


void Monkey::step()
{
	++step_count;
	if (step_count == 5) // redraw direction and step size every five steps
	{
		generate_direction();
		step_count = 0;
	}

	if (!is_freezed)
	{
		switch (moving_direction)
		{
		case 1: //vertical
		{
			location += {(int)step_size* vertical_direction, 0};
			break;
		}
		case 2: //horizontal
		{
			location += {0, (int)step_size* horizontal_direction};
			break;
		}
		default:
			break;
		}

		enforceLegalBounds();
	}

}

void Monkey::turnVertically() {}
void Monkey::turnHorizontally()
{
	horizontal_direction *= -1;
}

void Monkey::generate_direction()
{
	horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	moving_direction = RandomUtil::generateRandomValue(1, 2);
	step_size = (size_t)RandomUtil::generateRandomValue(1, 2);
}

void Monkey::enforceLegalBounds()
{
	if (location.row < LOWER__ROW_BOUND)
		location.row = LOWER__ROW_BOUND;

	if (location.row > UPPER__ROW_BOUND)
		location.row = UPPER__ROW_BOUND;

	if (location.column < LOWER__COLUMN_BOUND)
		location.column = LOWER__COLUMN_BOUND;

	if (location.column > UPPER__COLUMN_BOUND)
		location.column = UPPER__COLUMN_BOUND;
}