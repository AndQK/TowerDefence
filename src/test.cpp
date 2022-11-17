#ifndef TOWER_DEFENSE_TEST
#define TOWER_DEFENSE_TEST

#include <iostream>

#include "EasyEnemy.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "HardEnemy.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "SplittingEnemy.hpp"

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

  void testPlayer() {
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

  void testEnemies() {
    std::cout << "Testing Enemy class!" << std::endl;

    auto e = Enemy(1.0, 3, Coordinate(1, 1), 5);
    std::cout << "The enemy has been initialized with speed, health and worth: "
              << e.GetSpeed() << ", " << e.GetHealth() << ", " << e.GetWorth()
              << " accordingly." << std::endl;

    e.getHit(2);
    e.Slow(0.5);
    std::cout << "The enemy got hit by 2 and slowed by 0.5, health should now "
                 "be 1 and speed 0.5. They are:"
              << e.GetHealth() << ", " << e.GetSpeed() << std::endl;

    e.getHit(2);
    e.Slow(0.5);
    std::cout << "The enemy got hit by 2 and slowed by 0.5, health should now "
                 "be 0 (not -1) and speed 0.5 (not 0). They are:"
              << e.GetHealth() << ", " << e.GetSpeed() << std::endl;

    std::cout << "Testing Enemy subclasses!" << std::endl;

    auto easy = EasyEnemy(Coordinate(1, 1));
    std::cout << "EasyEnemy should be (1.0, 1, 3) is (" << easy.GetSpeed()
              << ", " << easy.GetHealth() << ", " << easy.GetWorth() << ")."
              << std::endl;

    auto splitting = SplittingEnemy(Coordinate(1, 1));
    std::cout << "SplittingEnemy should be (2.0, 3, 5) is ("
              << splitting.GetSpeed() << ", " << splitting.GetHealth() << ", "
              << splitting.GetWorth() << ")." << std::endl;

    auto hard = HardEnemy(Coordinate(1, 1));
    std::cout << "HardEnemy should be (3.0, 5, 10) is (" << hard.GetSpeed()
              << ", " << hard.GetHealth() << ", " << hard.GetWorth() << ")."
              << std::endl;

    hard.getHit(2);
    hard.Slow(0.5);
    std::cout
        << "The HardEnemy got hit by 2 and slowed by 0.5, health should now "
           "be 3 and speed 2.5. They are:"
        << hard.GetHealth() << ", " << hard.GetSpeed() << std::endl;

    std::cout << "End!" << std::endl;
  }

  void test3() {
    auto game = Game("Matias");
    game.getPlayer().AddMoney(50);
    std::cout << "Get the players money: " << game.getPlayer().GetMoney()
              << " Should be 50." << std::endl;
    game.startGame();
  }
};

#endif