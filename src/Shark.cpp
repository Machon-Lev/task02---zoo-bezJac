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
	if (is_freezed)
	{
		Animal::move();
		generate_direction();
	}
}

void Shark::step()
{

	if (!is_freezed)
	{
		switch (moving_direction)
		{
		case 1: //vertical
		{
			location += {SHARK_STEP* vertical_direction, 0};
			break;
		}
		case 2: //horizontal
		{
			location += {0, SHARK_STEP* horizontal_direction};
			break;
		}
		case 3: //horizontal
		{
			location += {SHARK_STEP* diagonal_vertical_direction, SHARK_STEP* diagonal_horizontal_direction};
			break;
		}
		default:
		{
			break;
		}
		
		}
		enforceLegalBounds();

	}
}

	void Shark::turnVertically() {}
	void Shark::turnHorizontally() {}


	void Shark::generate_direction()
	{
		horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		diagonal_vertical_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		diagonal_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
		moving_direction = RandomUtil::generateRandomValue(1, 3);
	}

	void Shark::enforceLegalBounds()
	{
		if (location.row < 0)
			location.row = 0;
		if (location.row > 19)
			location.row = 19;
		if (location.column < 0)
			location.column = 0;
		if (location.column > 39)
			location.column = 39;
	}