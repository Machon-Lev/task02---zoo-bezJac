#ifndef SHARK_H
#define SHARK_H

#include "Animal.h"



/**
 * A subclass of the `Animal` class representing a shark with a name, a location, and movement capabilities.
 * The shark moves five indexes per step, either vertically horizantlly, or diagonally.
 * New direction is drawn if shark was stoped and allowed to move agian.
 */
class Shark :public Animal {

	int diagonal_vertical_direction;		// The current diagonal-vertical direction orientation of the shark (either -1, or 1).
	int diagonal_horizontal_direction;		 // The current diagonal-horizontal direction orientation of the shark (either -1, or 1).
	int horizontal_direction;			// The current horizontal direction orientation of the shark (either -1, or 1).
	int vertical_direction;				// The current vertical direction orientation of the shark (either -1, or 1).
	int moving_direction;				// The current  direction of the monkey (1 : vertical, 2 : horizontal, 3 : diagonal).
public:
	Shark(std::string shark_name, Location shark_location);
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