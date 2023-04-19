#ifndef ANIMAL_H
#define ANIMAL_H
#include "Location.h"
#include <string>


/**
  A base class representing an animal with a name, a location, and movement capabilities.
  This class is meant to be subclassed and extended for specific types of animals.
 */
class Animal {
protected:
	std::string name;   // The name of the animal.
	Location location;  // The current location of the animal.
	bool is_freezed;    // A flag indicating whether the animal is frozen or not.

	Animal();
	Animal(std::string animal_name, Location animal_location);

public:

	virtual ~Animal() = default;

	/**
	 Prints details about the animal to the console.
	 */
	virtual void printDetails() const;

	/**
	 Returns the initial character of the animal's name.
	  This method is pure virtual, and must be overridden by subclasses.
	 */
	virtual char getInitial() const = 0;

	/**
	 Freezes the animal's movment, overrules step().
	 */
	void stop();

	/**
	Moves the animal one step, according to specific animal characteristics.
	This method is pure virtual, and must be overridden by subclasses to implement specific behaviors.
	*/
	virtual void step() = 0;

	/**
	Unfreeze an animal.
	This method is virtual, and can be overridden by subclasses to implement specific movement behaviors.
	 */
	virtual void move();



	/**
	Turns the animal's verticall direction (e.g. up or down).
	This method is pure virtual, and must be overridden by subclasses.
	 */
	virtual void turnVertically() = 0;

	/**
	Turns the animal horizontall direction (e.g. left or right).
	This method is pure virtual, and must be overridden by subclasses.
	 */
	virtual void turnHorizontally() = 0;

	/**
	Returns the current location of the animal.
	 */
	Location getLocation() const;
};

#endif // ANIMAL_H