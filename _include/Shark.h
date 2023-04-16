#ifndef SHARK_H
#define SHARK_H

#include "Animal.h"




class Shark :public Animal {

	int diagonal_vertical_direction;
	int diagonal_horizontal_direction;
	int horizontal_direction;
	int vertical_direction;
	int moving_direction;
public:
	Shark(std::string animal_name);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;
private:
	void generate_direction();
	void enforceLegalBounds();
};

#endif