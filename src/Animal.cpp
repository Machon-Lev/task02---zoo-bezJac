#include "Animal.h"
#include "random_util.h"
#include <iostream>


Animal::Animal() {}
Animal::Animal(std::string animal_name,Location animal_location)
{
	_name = animal_name;
	_location = animal_location;
	_is_freezed = false;
}
 void Animal::printDetails() const
{
	 std::cout << _name << " location: " << _location;
}

void Animal::stop() { _is_freezed = true; }
void Animal::move() { _is_freezed = false; }
Location Animal::getLocation() const
{ return _location; }
void Animal::setLocation(const int row, const int col) {
	_location._row = row;
	_location._column = col;
}