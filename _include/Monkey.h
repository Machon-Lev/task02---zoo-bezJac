#ifndef MONKEY_H
#define MONKEY_H
#include "Animal.h"

class Monkey :public Animal {

	int horizontal_direction;
	int vertical_direction;
	int moving_direction;
	size_t step_count;
	size_t step_size;
public:
	Monkey(std::string animal_name);
	void printDetails() const override;
	char getInitial() const override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;

private:
	void generate_direction();
	void enforceLegalBounds();
};
#endif