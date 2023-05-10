#include "Shark.h"
#include <random_util.h>
#include <iostream>

#define SHARK_STEP 5

Shark::Shark(std::string shark_name, Location shark_location) :Animal(shark_name,shark_location) {
	generate_direction();
}
void Shark::printDetails() const
{
	std::cout << "Shark: ";
	Animal::printDetails();
}
char Shark::getInitial() const
{
	return 'S';
}

void Shark::move()
{
	if (_is_freezed)
	{
		Animal::move();
		generate_direction();
	}
}

void Shark::step()
{

	if (!_is_freezed)
	{
		switch (_moving_direction)
		{
		case 1: //vertical
		{
			_location += {SHARK_STEP* _vertical_direction, 0};
			break;
		}
		case 2: //horizontal
		{
			_location += {0, SHARK_STEP* _horizontal_direction};
			break;
		}
		case 3: //horizontal
		{
			_location += {SHARK_STEP* _diagonal_vertical_direction, SHARK_STEP* _diagonal_horizontal_direction};
			break;
		}
		default:
		{
			break;
		}
		
		}

	}
}

	void Shark::turnVertically() {}
	void Shark::turnHorizontally() {}


	void Shark::generate_direction()
	{
		_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		_vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		_diagonal_vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		_diagonal_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		_moving_direction = RandomUtil::generateRandomValue(1, 3);
	}

