#ifndef LION_H
#define LION_H
#include "Animal.h"

/**
A subclass of the `Animal` class representing a lion with a name, a location, and movement capabilities.
The lion moves horizontally 2 indexes per step. 
 */
class Lion:public Animal {

	int horizontal_direction;  // The current horizontal direction of the lion (either -1, or 1).
public:
	Lion(std::string lion_name, Location lion_location);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;

};
#endif 