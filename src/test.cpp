#ifndef TOWER_DEFENSE_TEST
#define TOWER_DEFENSE_TEST

#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "Coordinate.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "Gui.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "SlowingTower.hpp"
#include "Tower.hpp"
#include "guiFunctions.hpp"
#include "level.hpp"

class test {
 public:
  void testMap() {
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

  void testGame() {
    auto game = Game("Matias", Map());
    game.GetPlayer().AddMoney(50);
    std::cout << "Get the players money: " << game.GetPlayer().GetMoney()
              << " Should be 50." << std::endl;
    game.StartGame();
  }

  void testGraphics() {
    int pos = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "Ando on paras!");
    sf::CircleShape shape(100.f);
    shape.setPosition(pos, pos);
    shape.setFillColor(sf::Color::Red);
    sf::Event event;
    while (window.isOpen() && pos < 300) {
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
      }
      window.clear();
      window.draw(shape);
      window.display();
      pos++;
      shape.setPosition(pos, pos);
      usleep(5000);
    }
  }

  void testEnemyMovement() {
    auto map = Map();
    map.AddCoordinate(Coordinate(100, 150));
    map.AddCoordinate(Coordinate(150, 300));
    map.AddCoordinate(Coordinate(250, 50));
    map.AddCoordinate(Coordinate(100, 50));
    map.AddCoordinate(Coordinate(600, 500));
    map.AddCoordinate(Coordinate(750, 50));

    Game game = Game("Gargamel", map);
    auto level = Level(100, &game);

    auto enemy = new Enemy(2.5, 34, Coordinate(0, 0), 5, &game, 0);
    game.AddEnemy(enemy);
    auto tower = new SlowingTower(Coordinate(100, 100), &game);
    auto tower2 = new SlowingTower(Coordinate(620, 300), &game);
    game.AddTower(tower);
    game.AddTower(tower2);

    std::vector<sf::CircleShape> towerShapes;
    sf::CircleShape towerShape(10.f);
    sf::CircleShape towerShape2(10.f);
    towerShape.setFillColor(sf::Color::Green);
    towerShape2.setFillColor(sf::Color::Green);
    towerShape.setPosition(tower->GetPlace().getX() - 10,
                           tower->GetPlace().getY() - 10);
    towerShape2.setPosition(tower2->GetPlace().getX() - 10,
                            tower2->GetPlace().getY() - 10);
    towerShapes.push_back(towerShape);
    towerShapes.push_back(towerShape2);

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Tower Defense!");
    window.setPosition(sf::Vector2(50, 50));

    std::vector<sf::CircleShape> nodes;
    sf::CircleShape node1(10.f);
    sf::CircleShape node2(10.f);
    sf::CircleShape node3(10.f);
    sf::CircleShape node4(10.f);
    sf::CircleShape node5(10.f);
    sf::CircleShape node6(10.f);
    node1.setFillColor(sf::Color::Blue);
    node2.setFillColor(sf::Color::Blue);
    node3.setFillColor(sf::Color::Blue);
    node4.setFillColor(sf::Color::Blue);
    node5.setFillColor(sf::Color::Blue);
    node6.setFillColor(sf::Color::Magenta);
    node1.setPosition(map.GetNode(0).getX() - 10, map.GetNode(0).getY() - 10);
    node2.setPosition(map.GetNode(1).getX() - 10, map.GetNode(1).getY() - 10);
    node3.setPosition(map.GetNode(2).getX() - 10, map.GetNode(2).getY() - 10);
    node4.setPosition(map.GetNode(3).getX() - 10, map.GetNode(3).getY() - 10);
    node5.setPosition(map.GetNode(4).getX() - 10, map.GetNode(4).getY() - 10);
    node6.setPosition(map.GetNode(5).getX() - 10, map.GetNode(5).getY() - 10);
    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(node5);
    nodes.push_back(node6);

    std::vector<sf::CircleShape> projectiles;

    sf::CircleShape enemyShape(20.f);
    enemyShape.setPosition(0, 0);
    enemyShape.setFillColor(sf::Color::Red);
    sf::Event event;
    while (window.isOpen()) {
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
      }
      window.clear();
      window.draw(enemyShape);
      for (auto t : towerShapes) window.draw(t);
      for (auto n : nodes) window.draw(n);

      if (game.GetProjectiles().size() > projectiles.size()) {
        sf::CircleShape p(5.f);
        p.setFillColor(sf::Color::Cyan);
        p.setPosition(game.GetProjectiles().back()->GetPosition().getX() - 5,
                      game.GetProjectiles().back()->GetPosition().getY() - 5);
        projectiles.push_back(p);
      }

      for (int i = 0; i < game.GetProjectiles().size(); i++) {
        projectiles.at(i).setPosition(
            game.GetProjectiles().at(i)->GetPosition().getX() - 5,
            game.GetProjectiles().at(i)->GetPosition().getY() - 5);
        window.draw(projectiles.at(i));
      }
      level.update();

      window.display();
      for (auto t : game.GetTowers()) t->Defend();
      for (auto p : game.GetProjectiles()) p->Move();

      for (auto e : game.GetEnemies()) {
        auto moved = e->Move();
        enemyShape.setPosition(e->GetCoord().getX() - 20,
                               e->GetCoord().getY() - 20);
      }
      if (game.GetEnemies().empty()) {
        game.AddEnemy(new Enemy(2.5, 34, Coordinate(0, 0), 5, &game, 0));
      }

      usleep(10000);
    }
  }

  void testProjectiles() {
    Map map = Map();
    map.AddCoordinate(Coordinate(700, 300));
    Game game = Game("Gargamel", map);
    auto enemy = new Enemy(1.0, 3, Coordinate(0, 300), 5, &game, 0);
    game.AddEnemy(enemy);
    Projectile projectile = Projectile(2.0, 50, Coordinate(800, 300),
                                       Coordinate(-1, 0), bomb, &game);

    sf::CircleShape proj(20.f);
    sf::CircleShape enem(50.f);
    enem.setPosition(enemy->GetCoord().getX() - 50,
                     enemy->GetCoord().getY() - 50);
    proj.setPosition(projectile.GetPosition().getX() - 20,
                     projectile.GetPosition().getY() - 20);
    enem.setFillColor(sf::Color::Red);
    proj.setFillColor(sf::Color::Blue);

    sf::RenderWindow window(sf::VideoMode(800, 600), "Projectile test");
    window.setPosition(sf::Vector2(100, 100));
    sf::Event event;
    while (window.isOpen()) {
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
      }
      if (!enemy->Move()) {
        window.close();
        usleep(1000000);
      }
      enem.setPosition(enemy->GetCoord().getX() - 50,
                       enemy->GetCoord().getY() - 50);

      projectile.Move();
      proj.setPosition(projectile.GetPosition().getX() - 20,
                       projectile.GetPosition().getY() - 20);

      window.clear();
      window.draw(enem);
      window.draw(proj);
      window.display();
      usleep(5000);
    }
  }
  void testSprites() {
    auto map = Map();
    map.AddCoordinate(Coordinate(164, 348));
    map.AddCoordinate(Coordinate(164, 98));
    map.AddCoordinate(Coordinate(292, 98));
    map.AddCoordinate(Coordinate(295, 479));
    map.AddCoordinate(Coordinate(87, 479));
    map.AddCoordinate(Coordinate(94, 615));
    map.AddCoordinate(Coordinate(542, 615));
    map.AddCoordinate(Coordinate(549, 413));
    map.AddCoordinate(Coordinate(418, 413));
    map.AddCoordinate(Coordinate(418, 157));
    map.AddCoordinate(Coordinate(625, 157));

    std::vector<sf::CircleShape> nodes;
    sf::CircleShape node1(10.f);
    sf::CircleShape node2(10.f);
    sf::CircleShape node3(10.f);
    sf::CircleShape node4(10.f);
    sf::CircleShape node5(10.f);
    sf::CircleShape node6(10.f);
    sf::CircleShape node7(10.f);
    sf::CircleShape node8(10.f);
    sf::CircleShape node9(10.f);
    sf::CircleShape node10(10.f);
    sf::CircleShape node11(10.f);

    node1.setFillColor(sf::Color::Blue);
    node2.setFillColor(sf::Color::Blue);
    node3.setFillColor(sf::Color::Blue);
    node4.setFillColor(sf::Color::Blue);
    node5.setFillColor(sf::Color::Blue);
    node6.setFillColor(sf::Color::Blue);
    node7.setFillColor(sf::Color::Blue);
    node8.setFillColor(sf::Color::Blue);
    node9.setFillColor(sf::Color::Blue);
    node10.setFillColor(sf::Color::Blue);
    node11.setFillColor(sf::Color::Blue);

    node1.setPosition(map.GetNode(0).getX(), map.GetNode(0).getY());
    node2.setPosition(map.GetNode(1).getX(), map.GetNode(1).getY());
    node3.setPosition(map.GetNode(2).getX(), map.GetNode(2).getY());
    node4.setPosition(map.GetNode(3).getX(), map.GetNode(3).getY());
    node5.setPosition(map.GetNode(4).getX(), map.GetNode(4).getY());
    node6.setPosition(map.GetNode(5).getX(), map.GetNode(5).getY());
    node7.setPosition(map.GetNode(6).getX(), map.GetNode(6).getY());
    node8.setPosition(map.GetNode(7).getX(), map.GetNode(7).getY());
    node9.setPosition(map.GetNode(8).getX(), map.GetNode(8).getY());
    node10.setPosition(map.GetNode(9).getX(), map.GetNode(9).getY());
    node11.setPosition(map.GetNode(10).getX(), map.GetNode(10).getY());

    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(node5);
    nodes.push_back(node6);
    nodes.push_back(node7);
    nodes.push_back(node8);
    nodes.push_back(node9);
    nodes.push_back(node10);
    nodes.push_back(node11);

    Game game = Game("Gargamel", map);
    auto enemy = Enemy(1.0, 3, Coordinate(35.f, 339.f), 5, &game, 0);
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("../graphics/Level1.png")) {
      std::cout << "unable to load texture from file" << std::endl;
      exit(-1);
    }
    unsigned int x = mapTexture.getSize().x;
    unsigned int y = mapTexture.getSize().y;
    sf::Sprite mapSprite;
    mapSprite.setTexture(mapTexture);
    mapSprite.setScale(0.5, 0.5);

    sf::RenderWindow window(sf::VideoMode(x / 2, y / 2), "TowerDefence");
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("../graphics/enemy1.png")) {
      std::cout << "unable to load enemy texture from file" << std::endl;
      exit(-1);
    }
    window.setPosition(sf::Vector2(50, 50));
    sf::Sprite enemySprite;

    float radiusX = enemyTexture.getSize().x / 2;
    float radiusY = enemyTexture.getSize().y / 2;

    enemySprite.setTexture(enemyTexture);
    enemySprite.setScale(0.05, 0.05);
    enemySprite.setOrigin(radiusX, radiusY);
    enemySprite.setPosition(35.f, 339.f);
    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
        if (sf::Event::MouseButtonPressed == event.type) {
          if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "The left button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
          }
        }
      }

      auto moved = enemy.Move();
      if (!moved) {
        usleep(2000000);
      }
      auto oldCoord = enemySprite.getPosition();
      enemySprite.setOrigin(radiusX, radiusY);
      enemySprite.setPosition(enemy.GetCoord().getX(), enemy.GetCoord().getY());

      enemySprite.setRotation(enemy.getAngle());
      std::cout << enemy.getAngle() << std::endl;
      window.clear();
      window.draw(mapSprite);
      window.draw(enemySprite);
      for (auto i : nodes) {
        window.draw(i);
      }
      window.display();
      usleep(10000);
    }
  }
  void testRotate() {
    float r = 0;
    sf::RenderWindow window(sf::VideoMode(800, 600), "TowerDefence");
    sf::Texture enemyTexture;
    if (!enemyTexture.loadFromFile("../graphics/enemy1.png")) {
      std::cout << "unable to load enemy texture from file" << std::endl;
      exit(-1);
    }
    window.setPosition(sf::Vector2(50, 50));

    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
          window.close();
        }
        if (sf::Event::MouseButtonPressed == event.type) {
          if (event.mouseButton.button == sf::Mouse::Left) {
            std::cout << "The left button was pressed" << std::endl;
            std::cout << "mouse x: " << event.mouseButton.x << std::endl;
            std::cout << "mouse y: " << event.mouseButton.y << std::endl;
          }
        }
      }
      sf::Sprite enemySprite;

      // float radiusX = 10.f;
      // float radiusY = 10.f;

      float radiusX = enemyTexture.getSize().x / 2;
      float radiusY = enemyTexture.getSize().y / 2;

      enemySprite.setTexture(enemyTexture);
      enemySprite.setScale(0.05f, 0.05f);
      enemySprite.setOrigin(radiusX, radiusY);
      enemySprite.setPosition(100.f, 100.f);

      // enemySprite.rotate(90.f);
      // enemySprite.setOrigin(radiusX, radiusY);
      enemySprite.rotate(r);
      window.clear();
      window.draw(enemySprite);
      window.display();

      r += 2.f;
      // usleep(1000);
    }
  }
  void testGui() {
    auto map = Map();
    map.loadCoordinates("../path3.txt");
    /*for (auto i : map.GetNodes()) {
      std::cout << i << std::endl;
    }*/
    Game game = Game("Gargamel", map);
    Level level = Level(100, &game);
    game.SetLevel(level);
    auto enemy = new Enemy(1.0, 3, map.GetNodes().front(), 5, &game, 0);
    game.AddEnemy(enemy);
    Gui gui = Gui(&game);
    gui.run();
  }
};

#endif
