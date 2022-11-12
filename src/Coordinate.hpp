#ifndef TOWER_DEFENSE_COORDINATE
#define TOWER_DEFENSE_COORDINATE

#include <iostream>

class Coordinate {
 public:
  Coordinate(int x, int y) : x_(x), y_(y) {}

  Coordinate operator+(const Coordinate& c2) {
    return Coordinate(this->x_ + c2.x_, this->y_ + c2.y_);
  }

  Coordinate operator-(const Coordinate& c2) {
    return Coordinate(this->x_ - c2.x_, this->y_ - c2.y_);
  }

  friend std::ostream& operator<<(std::ostream& os, Coordinate& c) {
    os << "(" << c.x_ << "," << c.y_ << ")";
    return os;
  }

 private:
  int x_;
  int y_;
};

#endif