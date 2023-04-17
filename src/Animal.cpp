#include "Animal.h"
#include "random_util.h"
#include <iostream>


Animal::Animal() {}
Animal::Animal(std::string animal_name,Location animal_location)
{
	name = animal_name;
	location = animal_location;
	is_freezed = false;
}
 void Animal::printDetails() const
{
	 std::cout << name << " location: " << location;
}

void Animal::stop() { is_freezed = true; }
void Animal::move() { is_freezed = false; }
Location Animal::getLocation() const
{ return location; }