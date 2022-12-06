#ifndef TOWER_DEFENSE_TEST
#define TOWER_DEFENSE_TEST

#include <unistd.h>

#include <SFML/Graphics.hpp>
#include <iostream>

#include "EasyEnemy.hpp"
#include "Enemy.hpp"
#include "Game.hpp"
#include "HardEnemy.hpp"
#include "Map.hpp"
#include "Player.hpp"
#include "Projectile.hpp"
#include "SplittingEnemy.hpp"
#include "Tower.hpp"
#include "Gui.hpp"

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

  void testTowers() {
    std::cout << "Testing Tower class!" << std::endl;

    auto e = Enemy(5.0, 3, Coordinate(1, 1), 5);
    auto t = Tower(100, 3, 2, Coordinate(1, 1), 1);

    std::cout << "Tower should be (100, 3, 2, 1) is (" << t.GetCost() << ", "
              << t.GetSpeed() << ", " << t.GetDamage() << ", " << t.GetRange()
              << ")." << std::endl;

    t.Attack(e);
    t.Slow(e);

    std::cout
        << "The enemy got hit by 2 and slowed by 2, should now be (1, 3), "
           "is: ("
        << e.GetHealth() << ", " << e.GetSpeed() << ")." << std::endl;

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
    Game game = Game("Gargamel", map);
    auto enemy = Enemy(2.5, 3, Coordinate(0, 0), 5, &game);

    sf::RenderWindow window(sf::VideoMode(1000, 600), "Tower Defense!");
    window.setPosition(sf::Vector2(50, 50));

    std::vector<sf::CircleShape> nodes;
    sf::CircleShape node1(10.f);
    sf::CircleShape node2(10.f);
    sf::CircleShape node3(10.f);
    sf::CircleShape node4(10.f);
    sf::CircleShape node5(10.f);
    node1.setFillColor(sf::Color::Blue);
    node2.setFillColor(sf::Color::Blue);
    node3.setFillColor(sf::Color::Blue);
    node4.setFillColor(sf::Color::Blue);
    node5.setFillColor(sf::Color::Magenta);
    node1.setPosition(map.GetNode(0).getX() - 10, map.GetNode(0).getY() - 10);
    node2.setPosition(map.GetNode(1).getX() - 10, map.GetNode(1).getY() - 10);
    node3.setPosition(map.GetNode(2).getX() - 10, map.GetNode(2).getY() - 10);
    node4.setPosition(map.GetNode(3).getX() - 10, map.GetNode(3).getY() - 10);
    node5.setPosition(map.GetNode(4).getX() - 10, map.GetNode(4).getY() - 10);
    nodes.push_back(node1);
    nodes.push_back(node2);
    nodes.push_back(node3);
    nodes.push_back(node4);
    nodes.push_back(node5);

    sf::CircleShape shape(20.f);
    shape.setPosition(enemy.GetCoord().getX(), enemy.GetCoord().getY());
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
      for (auto n : nodes) {
        window.draw(n);
      }
      window.display();

      auto moved = enemy.Move();
      if (!moved) {
        usleep(2000000);
        break;
      }
      shape.setPosition(enemy.GetCoord().getX() - 20,
                        enemy.GetCoord().getY() - 20);
      usleep(10000);
    }
  }

  void testProjectiles() {
    Map map = Map();
    map.AddCoordinate(Coordinate(700, 300));
    Game game = Game("Gargamel", map);
    auto enemy = Enemy(1.0, 3, Coordinate(0, 300), 5, &game);
    game.AddEnemy(enemy);
    Projectile projectile = Projectile(2.0, 50, Coordinate(800, 300),
                                       Coordinate(-1, 0), bomb, game);

    sf::CircleShape proj(20.f);
    sf::CircleShape enem(50.f);
    enem.setPosition(enemy.GetCoord().getX() - 50,
                     enemy.GetCoord().getY() - 50);
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
      if (!enemy.Move()) {
        window.close();
        usleep(1000000);
      }
      enem.setPosition(enemy.GetCoord().getX() - 50,
                       enemy.GetCoord().getY() - 50);

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
    auto enemy = Enemy(1.0, 3, Coordinate(35.f, 339.f), 5, &game);
    sf::Texture mapTexture;
    if (!mapTexture.loadFromFile("graphics/Level1.png")) {
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
    if (!enemyTexture.loadFromFile("graphics/enemy1.png")) {
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
    if (!enemyTexture.loadFromFile("graphics/enemy1.png")) {
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
    Game game = Game("Gargamel", map);
    Gui gui = Gui(game);
    gui.run();
  }
};

/*void testGuiFunctions() {
  int currentScreen = 0;

  sf::Texture mapTexture;
  if (!mapTexture.loadFromFile("graphics/Level1.png")) {
    std::cout << "unable to load texture from file" << std::endl;
    exit(-1);
  }
  sf::Texture mainMenuTexture;
  if (!mainMenuTexture.loadFromFile("graphics/mainMenu.png")) {
    std::cout << "unable to load texture form file" << std::endl;
    exit(-1);
  }

  std::vector<sf::Texture> towerTextures;

  sf::Texture diamondTowerTexture;
  if (!diamondTowerTexture.loadFromFile("graphics/diamondGun.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  sf::Texture teslaTowerTexture;
  if (!teslaTowerTexture.loadFromFile("graphics/tesla.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  sf::Texture turretTowerTexture;
  if (!turretTowerTexture.loadFromFile("graphics/turret.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }

  sf::Texture rocketTowerTexture;
  if (!rocketTowerTexture.loadFromFile("graphics/rocketGreen.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }
  sf::Texture iceTowerTexture;
  if (!iceTowerTexture.loadFromFile("graphics/iceRocket.png")) {
    std::cout << "unable to load tower texture from file" << std::endl;
    exit(-1);
  }
  sf::Font font;
  if (!font.loadFromFile("graphics/ARLRDBD.TTF")) {
    std::cout << "unable to load font from file" << std::endl;
    exit(-1);
  }

  towerTextures.push_back(diamondTowerTexture);
  towerTextures.push_back(teslaTowerTexture);
  towerTextures.push_back(turretTowerTexture);
  towerTextures.push_back(rocketTowerTexture);
  towerTextures.push_back(iceTowerTexture);

  sf::RenderWindow window(sf::VideoMode(mapTexture.getSize().x / 2 + 200,
                                        mapTexture.getSize().y / 2),
                          "TowerDefence");
  window.setPosition(sf::Vector2(50, 50));
  while (window.isOpen()) {
    window.clear();
    switch (currentScreen) {
      case 0:  // main menu:
        createAndDrawGameMenu(window, mainMenuTexture);
        break;
      case 1:  // game screen:
        std::vector<sf::Vector2f> coordinates =
            createAndDrawGameScreen(window, mapTexture, towerTextures);
        createAndDrawPlayerInfo(window, 0, 0, 0, font);
        break;
    }
    sf::Event event;
    while (window.pollEvent(event)) {
      if (sf::Event::Closed == event.type) {
        window.close();
      }
      if (sf::Event::MouseButtonPressed == event.type) {
        if (event.mouseButton.button == sf::Mouse::Left) {
          int x = event.mouseButton.x;
          int y = event.mouseButton.y;
          switch (currentScreen) {
            case 0:
              if ((x >= 334 && x <= 506) && (y >= 490 && y <= 528)) {
                currentScreen = 1;
                std::cout << "changing scene" << std::endl;
              }
              break;
            case 1:
              break;
            default:
              break;
          }
        }
      }
    }
    window.display();
  }
}
}*/

#endif
