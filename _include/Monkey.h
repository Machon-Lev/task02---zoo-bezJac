#ifndef MONKEY_H
#define MONKEY_H
#include "Animal.h"


/**
 * A subclass of the `Animal` class representing a monkey with a name, a location, and movement capabilities.
 * The monkey moves either vertically or horizantlly, with an option of one or two indexes each step.
 * New direction and step size drawn every five steps.
 */
class Monkey :public Animal {

	int horizontal_direction;	// The current horizontal direction of the monkey (either -1, or 1).
	int vertical_direction;		// The current vertical direction of the monkey (either -1, or 1).
	int moving_direction;		// The current  direction of the monkey (either 1 : vertical, or 2 : horizontal).
	size_t step_count;			// Counter for monkey steps.
	size_t step_size;			// Number of indexes monkey moves per step (either 1, or 2).
public:
	Monkey(std::string monkey_name, Location monkey_location);
	void printDetails() const override;
	char getInitial() const override;
	void move() override;
	void step() override;
	void turnVertically() override;
	void turnHorizontally() override;

	// private functions to assist step().
private:
	/**
	* @brief Draws and sets a new random direction and step size.
	**/
	void generate_direction();
	/**
	* @brief Returns monkey to within board's borders, if current step has taken it out.
	**/
	void enforceLegalBounds();
};
#endif