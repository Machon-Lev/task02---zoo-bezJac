#ifndef LION_H
#define LION_H
#include "Animal.h"




class Lion:public Animal {

	int horizontal_direction;
public:
	Lion(std::string animal_name);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;

};
#endif 