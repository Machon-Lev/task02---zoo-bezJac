#ifndef LOCATION_H
#define LOCATION_H

#include <ostream>

/**
 A struct representing a location in two-dimensional board.
 The location can be added to or incremented with another location,
 and can be compared to other locations for equality or relative ordering.
 */
struct Location
{
	int _row;
	int _column;

	Location();
	Location(int r, int c);
	
	bool operator==(const Location& other) const;

	bool operator!=(const Location& other) const;

	bool operator<(const Location& other) const;

	bool operator<=(const Location& other) const;
	bool operator>(const Location& other) const;

	bool operator>=(const Location& other) const;

	Location operator+(const Location& other);
	Location& operator+=(const Location& other);


	friend std::ostream& operator<<(std::ostream& os, const Location& location);
};


#endif// LOCATION_H