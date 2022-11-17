#ifndef TOWER_DEFENSE_TEST
#define TOWER_DEFENSE_TEST

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"
#include "Map.hpp"
#include "Player.hpp"

class test {
 public:
  void test1() {
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
  }

  void test2() {
    std::cout << "Testing Player class!" << std::endl;
    auto p = Player("Unknown");
    p.AddMoney(100);
    std::cout << "The players money balance is now " << p.GetMoney()
              << " should be 100." << std::endl;
    auto b = p.Pay(101);
    std::cout << "The pay method returned " << b
              << " should have returned false." << std::endl;
    std::cout << "The players money balance is now " << p.GetMoney()
              << " should be 100." << std::endl;
    p.Pay(100);
    std::cout << "The players money balance is now " << p.GetMoney()
              << " should be 0." << std::endl;
    p.AddPoints(100);
    std::cout << "The players amount of points is now " << p.GetPoints()
              << " should be 100." << std::endl;
    std::cout << "End!" << std::endl;
  }

  void test3() {
    auto game = Game("Matias");
    game.getPlayer().AddMoney(50);
    std::cout << "Get the players money: " << game.getPlayer().GetMoney()
              << " Should be 50." << std::endl;
    game.startGame();
  }
  void test4() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ando on paras!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Red);
    sf::Event event;
    while (window.isOpen()) {
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
      }
      window.clear();
      window.draw(shape);
      window.display();
    }
  }
};

#endif
