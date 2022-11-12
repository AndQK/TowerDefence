#include <iostream>

#include "Map.hpp"

int main(int, char**) {
  std::cout << "Testing coordinates added one by one!" << std::endl;

  auto m = Map();
  m.AddCoordinate(Coordinate(0, 0));
  m.AddCoordinate(Coordinate(1, 1));
  m.AddCoordinate(Coordinate(1, 3));
  m.AddCoordinate(Coordinate(3, 3));
  m.AddCoordinate(Coordinate(3, 5));
  auto nodes = m.GetNodes();
  for (auto n : nodes) std::cout << n << std::endl;

  std::cout << "Testing getting a single Coordinate!" << std::endl;
  auto node = m.GetNode(4);
  std::cout << node << std::endl;

  std::cout << "Testing coordinates added as a vector!" << std::endl;
  auto m2 = Map();
  std::vector<Coordinate> coords(5, Coordinate(12, 20));
  m2.AddCoordinates(coords);
  auto nodes2 = m2.GetNodes();
  for (auto n : nodes2) std::cout << n << std::endl;

  std::cout << "End!" << std::endl;
}
