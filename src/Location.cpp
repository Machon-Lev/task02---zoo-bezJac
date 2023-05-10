#include "Location.h"
#include <ostream>
Location::Location() {}
Location::Location(int r, int c) :_row(r), _column(c) {}

bool Location::operator==(const Location& other) const {
	return _row == other._row && _column == other._column;
}

bool Location::operator!=(const Location& other) const {
	return !(*this == other);
}

bool Location::operator<(const Location& other) const {
	if (_row < other._row)
		return true;
	else
		if (_row == other._row && _column < other._column)
			return true;
	return false;
}

bool Location::operator<=(const Location& other) const {
	return (*this) < other || (*this) == other;
}

bool Location::operator>(const Location& other) const {
	if (_row > other._row)
		return true;
	else
		if (_row == other._row && _column > other._column)
			return true;
	return false;
}

bool Location::operator>=(const Location& other) const {
	return (*this) > other || (*this) == other;
}

Location Location::operator+(const Location& other) {
	return Location(_row + other._row, _column + other._column);
}
Location& Location::operator+=(const Location& other) {
	_row += other._row;
	_column += other._column;
	return *this;
}




std::ostream& operator<<(std::ostream& os, const Location& location) {
	os << "(" << location._row << ", " << location._column << ")";
	return os;
}
