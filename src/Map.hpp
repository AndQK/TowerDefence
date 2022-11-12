#ifndef TOWER_DEFENSE_MAP
#define TOWER_DEFENSE_MAP

#include <vector>

#include "Coordinate.hpp"

class Map {
 public:
  Map() : nOfNodes_(0) {}

  // Adds a single Coordinate to the enemies "path".
  void AddCoordinate(const Coordinate& coord);

  // Adds a vector Coordinates to the enemies "path".
  void AddCoordinates(std::vector<Coordinate> coordinates);

  // Gets the path of the enemies.
  std::vector<Coordinate> GetNodes() const;

  // Gets a single node from the path.
  // Takes the index of the node as a parameter.
  Coordinate GetNode(const int& index) const;

  // Gets the amount of nodes.
  // If enemy is on the last node, it means enemy got through the defenses.
  int GetNofNodes() const;

 private:
  // Enemies path
  std::vector<Coordinate> nodes_;

  // amount of nodes
  int nOfNodes_;
};

#endif