#include "Lion.h"
#include <iostream>
#include <random_util.h>

Lion::Lion(std::string lion_name, Location lion_location) :Animal(lion_name,lion_location) {

	_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
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
	if (_is_freezed)
	{
		Animal::move();
		_horizontal_direction = RandomUtil::generateRandomValue(0, 1) == 0 ? -1 : 1;
	}
}
void Lion::step()
{
	if (!_is_freezed)
	{
		if (_location._column < 2 || _location._column >37)		// lion reached horizontal border of the board - switch directions
			turnHorizontally();
		if (_location._column != 1 || _location._column != 38)	// when lion is in (*,1) or (*,38) next move will return it to the same spot
			_location += {0, 2 * _horizontal_direction};
			
	}
}
void Lion::turnVertically() {}
void Lion::turnHorizontally()
{
	_horizontal_direction *= -1;
}