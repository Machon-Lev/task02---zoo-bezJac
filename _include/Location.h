#ifndef LOCATION_H
#define LOCATION_H

#include <ostream>
struct Location
{
	int row;
	int column;

    Location() {}
    Location(int r, int c)
    {
        row = r;
        column = c;
    }

    bool operator==(const Location& other) const {
        return row == other.row && column == other.column;
    }

    bool operator!=(const Location& other) const {
        return !(*this == other);
    }

    Location operator+(const Location& other) {
        return Location(row + other.row, column + other.column);
    }

    Location& operator+=(const Location& other) {
        row += other.row;
        column += other.column;
        return *this;
    }

    Location operator+(const int add) {
        return Location(row + add, column + add);
    }
    Location operator+(const int add[2]) {
        return Location(row + add[0], column + add[1]);
    }
    Location& operator+=(const int add[2]) {
        row += add[0];
        column += add[1];
        return *this;
    }
   
    
    friend std::ostream& operator<<(std::ostream& os, const Location& location);
};

 inline std::ostream& operator<<(std::ostream& os, const Location& location) {
    os << "(" << location.row << ", " << location.column << ")";
    return os;
}

#endif// LOCATION_H