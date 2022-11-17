#include "Game.hpp"

#include <unistd.h>

Game::Game(const std::string& name) : player_(Player(name)) {
  map_ = Map();
  std::vector<Coordinate> coords{Coordinate(0, 0), Coordinate(1, 1),
                                 Coordinate(2, 5)};
  map_.AddCoordinates(coords);
}

void Game::startGame() {
  int i = 0;
  double time_elapsed = 0;
  int SLEEP_TIME = 125000;
  // Simulates the frames
  while (i <= 30) {
    if (i % 5 == 0) {
      double seconds = time_elapsed / 1000000;
      std::cout << "Game running for " << seconds
                << "seconds. Current frame: " << i << "." << std::endl;
    }
    i++;
    // Sleeps for n microseconds (Actual game could do some math for the time)
    usleep(SLEEP_TIME);
    time_elapsed += SLEEP_TIME;
  }
}

Player& Game::getPlayer() { return player_; }

Map Game::getMap() const {
  auto m = map_;
  return m;
}