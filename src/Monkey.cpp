#include "Monkey.h"
#include <random>
#include <random_util.h>
#include <iostream>


Monkey::Monkey(std::string monkey_name, Location monkey_location) :Animal(monkey_name, monkey_location) {

	generate_direction();
	_step_count = 0;
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
	if (_is_freezed)
		Animal::move();
}


void Monkey::step()
{
	++_step_count;
	if (_step_count == 5) // redraw direction and step size every five steps
	{
		generate_direction();
		_step_count = 0;
	}

	if (!_is_freezed)
	{
		switch (_moving_direction)
		{
		case 1: //vertical
		{
			_location += {(int)_step_size* _vertical_direction, 0};
			break;
		}
		case 2: //horizontal
		{
			_location += {0, (int)_step_size* _horizontal_direction};
			break;
		}
		default:
			break;
		}

		
	}

}

void Monkey::turnVertically() {}
void Monkey::turnHorizontally()
{
	_horizontal_direction *= -1;
}

void Monkey::generate_direction()
{
	_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	_vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	_moving_direction = RandomUtil::generateRandomValue(1, 2);
	_step_size = (size_t)RandomUtil::generateRandomValue(1, 2);
}
