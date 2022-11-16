#include "Game.hpp"

Game::Game() : player_(Player("m")) {
  map_ = Map();
  std::vector<Coordinate> coords{Coordinate(0, 0), Coordinate(1, 1),
                                 Coordinate(2, 5)};
  map_.AddCoordinates(coords);
}

Player& Game::getPlayer() { return player_; }

Map Game::getMap() const {
  auto m = map_;
  return m;
}