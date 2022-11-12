#include "Map.hpp"

void Map::AddCoordinate(const Coordinate& coord) {
  nOfNodes_++;
  nodes_.push_back(coord);
}

void Map::AddCoordinates(std::vector<Coordinate> coordinates) {
  for (auto i = coordinates.begin(); i != coordinates.end(); i++) {
    nodes_.push_back(*i);
    nOfNodes_++;
  }
}

std::vector<Coordinate> Map::GetNodes() const { return nodes_; }

Coordinate Map::GetNode(const int& index) const { return nodes_.at(index); }

int Map::GetNofNodes() const { return nOfNodes_; }