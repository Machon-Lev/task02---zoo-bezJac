#include "Animal.h"
#include "random_util.h"
#include <iostream>


Animal::Animal() {}
Animal::Animal(std::string animal_name)
{
	name = animal_name;
	location.row = RandomUtil::generateRandomValue(0, 19);
	location.column = RandomUtil::generateRandomValue(0, 39);
}
 void Animal::printDetails() const
{
	 std::cout << name << " location: " << location;
}

void Animal::stop() { is_freezed = true; }
void Animal::move() { is_freezed = false; }
