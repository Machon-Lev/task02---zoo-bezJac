#ifndef ANIMAL_H
#define ANIMAL_H
#include "Location.h"
#include <string>


class Animal {
protected:
	std::string name;
	Location location;
	bool is_freezed;
	Animal();
	Animal(std::string animal_name,Location animal_location);
	
public:
	virtual ~Animal() = default;
	virtual void printDetails() const;
	virtual char getInitial() const = 0;
	virtual void step() = 0;
	void stop();
	virtual void move();
	virtual void turnVertically() = 0;
	virtual void turnHorizontally() = 0;
	Location getLocation() const;


};
#endif // ANIMAL_H