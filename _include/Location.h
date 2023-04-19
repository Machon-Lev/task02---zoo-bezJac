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
	int row;
	int column;

	Location() {}
	Location(int r, int c):row(r),column(c){}
	
	bool operator==(const Location& other) const {
		return row == other.row && column == other.column;
	}

	bool operator!=(const Location& other) const {
		return !(*this == other);
	}

	bool operator<(const Location& other) const {
		if (row < other.row)
			return true;
		else
			if (row == other.row && column < other.column)
				return true;
		return false;
	}

	bool operator<=(const Location& other) const {
		return (*this) < other || (*this) == other;
	}

	bool operator>(const Location& other) const {
		if (row > other.row)
			return true;
		else
			if (row == other.row && column > other.column)
				return true;
		return false;
	}

	bool operator>=(const Location& other) const {
		return (*this) > other || (*this) == other;
	}

	Location operator+(const Location& other) {
		return Location(row +other.row, column + other.column);
	}
	Location& operator+=(const Location& other) {
		row += other.row;
		column += other.column;
		return *this;
	}


	friend std::ostream& operator<<(std::ostream& os, const Location& location);
};

inline std::ostream& operator<<(std::ostream& os, const Location& location) {
	os << "(" << location.row << ", " << location.column << ")";
	return os;
}

#endif// LOCATION_H