#ifndef TOWER_DEFENSE_COORDINATE
#define TOWER_DEFENSE_COORDINATE

#include <cmath>
#include <iostream>

class Coordinate {
 public:
  // Constructor takes which takes x and y as parameters.
  Coordinate(double x, double y) : x_(x), y_(y) {}

  // Default constructor
  Coordinate() : x_(0), y_(0) {}

  // Overloading the + operator for adding multiple Coordinates together.
  Coordinate operator+(const Coordinate& c2) {
    return Coordinate(this->x_ + c2.x_, this->y_ + c2.y_);
  }

  // Overloading the - operator for subtracting multiple Coordinates from one
  // another.
  Coordinate operator-(const Coordinate& c2) {
    return Coordinate(this->x_ - c2.x_, this->y_ - c2.y_);
  }

  // Gets the length of the vector
  double getLength() { return sqrt(x_ * x_ + y_ * y_); }

  // Method for multiplying Coordinate by a constant
  Coordinate operator*(const double& c2) {
    return Coordinate(x_ * c2, y_ * c2);
  }

  // Method for dividing Coordinate by a constant
  Coordinate operator/(const double& c2) {
    return Coordinate(x_ / c2, y_ / c2);
  }

  double getX() const { return x_; }

  double getY() const { return y_; }

  // Overloading << method for printing vector in ostreams.
  friend std::ostream& operator<<(std::ostream& os, Coordinate& c) {
    os << "(" << c.x_ << "," << c.y_ << ")";
    return os;
  }

 private:
  double x_;
  double y_;
};

#endif