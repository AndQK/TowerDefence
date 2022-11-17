#ifndef TOWER_DEFENSE_COORDINATE
#define TOWER_DEFENSE_COORDINATE

#include <iostream>

class Coordinate {
 public:
  // Constructor takes which takes x and y as parameters.
  Coordinate(int x, int y) : x_(x), y_(y) {}

  // Overloading the + operator for adding multiple Coordinates together.
  Coordinate operator+(const Coordinate& c2) {
    return Coordinate(this->x_ + c2.x_, this->y_ + c2.y_);
  }

  // Overloading the - operator for subtracting multiple Coordinates from one
  // another.
  Coordinate operator-(const Coordinate& c2) {
    return Coordinate(this->x_ - c2.x_, this->y_ - c2.y_);
  }

  // Overloading << method for printing vector in ostreams.
  friend std::ostream& operator<<(std::ostream& os, Coordinate& c) {
    os << "(" << c.x_ << "," << c.y_ << ")";
    return os;
  }

 private:
  int x_;
  int y_;
};

#endif