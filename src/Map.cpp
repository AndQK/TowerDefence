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

void Map::loadCoordinates(std::string file) {
  std::string coordinate;
  std::ifstream myFile(file);
  if (myFile.is_open()) {
    while (std::getline(myFile, coordinate)) {
      std::string formatted;
      std::string remove = "()";
      for (std::string::const_iterator it = coordinate.begin();
           it != coordinate.end(); ++it) {
        if (remove.find(*it) == std::string::npos) {
          if (*it != ',') {
            formatted += *it;
          } else {
            formatted += " ";
          }
        }
      }
      std::istringstream data(formatted);
      int x;
      int y;
      data >> x >> y;

      // check that reading succeeded.

      if (data) {
        Coordinate coord(x, y);
        this->AddCoordinate(coord);
      } else {
        std::cout << "there was a problem reading data for coordinates"
                  << std::endl;
      }
    }
  } else {
    std::cout << "Couldn't open file" << std::endl;
  }
}