#include "Lion.h"
#include <iostream>
#include <random_util.h>

Lion::Lion(std::string lion_name, Location lion_location) :Animal(lion_name,lion_location) {

	horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
}
void Lion::printDetails() const
{
	std::cout << "Lion: ";
	Animal::printDetails();
}
char Lion::getInitial() const
{
	return 'L';
}

void Lion::move() {
	if (is_freezed)
	{
		Animal::move();
		horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	}
}
void Lion::step()
{
	if (!is_freezed)
	{
		if (location.column < 2 || location.column >37)		// lion reached horizontal border of the board - switch directions
			turnHorizontally();
		if (location.column != 1 || location.column != 38)	// when lion is in (*,1) or (*,38) next move will return it to the same spot
			location += {0, 2 * horizontal_direction};
			
	}
}
void Lion::turnVertically() {}
void Lion::turnHorizontally()
{
	horizontal_direction *= -1;
}