#ifndef TOWER_DEFENSE_MAP
#define TOWER_DEFENSE_MAP

#include <vector>

#include "Coordinate.hpp"

class Map {
 public:
  Map() : nOfNodes_(0) {}

  void AddCoordinate(const Coordinate& coord);

  void AddCoordinates(std::vector<Coordinate> coordinates);

  std::vector<Coordinate> GetNodes() const;

  Coordinate GetNode(const int& index) const;

  int GetNofNodes() const;

 private:
  std::vector<Coordinate> nodes_;
  int nOfNodes_;
};

#endif