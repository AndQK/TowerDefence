#ifndef TOWER_DEFENCE_GUIFUNCTIONS
#define TOWER_DEFENCE_GUIFUNCTIONS

#include <SFML/Graphics.hpp>
#include <vector>

enum Screens { gameMenu, gameLevelMenu, gameScreen, gameEndScreen };

void createAndDrawGameMenu(sf::RenderWindow &window, sf::Texture texture);

void createAndDrawPlayerInfo(sf::RenderWindow &window, int health, int wave,
                             int gold, sf::Font font);

void createAndDrawTowerBtn(sf::RenderWindow &window, sf::Vector2f btnLocation,
                           sf::Vector2f btnSize, sf::Texture &texture);

std::vector<sf::Vector2f> createAndDrawGameScreen(
    sf::RenderWindow &window, sf::Texture &texture,
    std::vector<sf::Texture> &towerTextures);

void drawDrawables(sf::RenderWindow &window,
                   std::vector<sf::Drawable *> drawables);

#endif