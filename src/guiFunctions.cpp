
#include "guiFunctions.hpp"

#include <string>

std::vector<sf::Vector2f> createAndDrawGameScreen(
    sf::RenderWindow &window, sf::Texture &texture,
    std::vector<sf::Texture> &towerTextures) {
  // Upper left corner
  std::vector<sf::Vector2f> btnLocations;
  // Width and height for buttons
  std::vector<sf::Vector2f> btnSizes;

  // initialising a map sprite with a texture
  sf::Sprite mapSprite;
  mapSprite.setTexture(texture);
  mapSprite.setScale(0.5f, 0.5f);

  // panel's width and height
  int width = 200;
  int height = window.getSize().y;

  // panel's position
  int x = window.getSize().x - 200;
  int y = 0;

  // Create sidePanel for game buttons
  sf::RectangleShape panel;
  sf::Color darkerGrey(70, 70, 70);
  panel.setSize(sf::Vector2f(width, height));
  panel.setFillColor(darkerGrey);
  panel.setPosition(x, y);

  // Create buttons. Should be inside sidePanel area and the size is 50x50
  // pixels.
  btnLocations.push_back(sf::Vector2f(x + 15, 300));
  btnLocations.push_back(sf::Vector2f(x + 75, 300));
  btnLocations.push_back(sf::Vector2f(x + 135, 300));
  btnLocations.push_back(sf::Vector2f(x + 33, 365));
  btnLocations.push_back(sf::Vector2f(x + 116, 365));

  // draw the level
  window.draw(mapSprite);

  // draw the panel
  window.draw(panel);

  for (unsigned int i = 0; i < btnLocations.size(); i++) {
    btnSizes.push_back(sf::Vector2f(50, 50));
  }
  for (unsigned int i = 0; i < btnLocations.size(); i++) {
    createAndDrawTowerBtn(window, btnLocations[i], btnSizes[i],
                          towerTextures[i]);
  }
  return btnLocations;
}

void createAndDrawTowerBtn(sf::RenderWindow &window, sf::Vector2f btnLocation,
                           sf::Vector2f btnSize, sf::Texture &texture) {
  std::vector<sf::Drawable *> drawables;

  sf::RectangleShape btn(btnSize);
  btn.setPosition(btnLocation);
  btn.setFillColor(sf::Color::White);

  // button's outline color will be grey
  sf::Color grey(128, 128, 128);
  btn.setOutlineColor(grey);
  btn.setOutlineThickness(3);
  drawables.push_back(&btn);

  // setting up the icon for the button.
  sf::Sprite btnSprite;
  btnSprite.setTexture(texture);
  btnSprite.setScale(0.09, 0.09);
  btnSprite.setOrigin(texture.getSize().x / 2, texture.getSize().y / 2);
  btnSprite.setPosition(btnLocation.x + 25, btnLocation.y + 25);
  drawables.push_back(&btnSprite);

  drawDrawables(window, drawables);
}

void drawDrawables(sf::RenderWindow &window,
                   std::vector<sf::Drawable *> drawables) {
  std::vector<sf::Drawable *>::iterator it = drawables.begin();
  for (; it != drawables.end(); it++) {
    window.draw(**it);
  }
}

void createAndDrawGameMenu(sf::RenderWindow &window, sf::Texture texture) {
  sf::Sprite menuSprite;
  menuSprite.setTexture(texture);

  // width and height of the window
  float width = window.getSize().x;
  float height = window.getSize().y;

  menuSprite.setScale(width / texture.getSize().x,
                      height / texture.getSize().y);
  window.draw(menuSprite);
}

void createAndDrawPlayerInfo(sf::RenderWindow &window, int health, int wave,
                             int gold, sf::Font font) {
  // panel's position we're drawing on
  int x = window.getSize().x - 200;
  int y = 0;

  // storage for the drawables
  std::vector<sf::Drawable *> drawables;

  // colour for the boxes
  sf::Color darkGrey(90, 90, 90);

  // health box
  sf::RectangleShape healthBox;
  healthBox.setSize(sf::Vector2f(180, 30));
  healthBox.setFillColor(darkGrey);
  healthBox.setPosition(x + 10, y + 10);
  drawables.push_back(&healthBox);

  // gold box
  sf::RectangleShape goldBox;
  goldBox.setSize(sf::Vector2f(180, 30));
  goldBox.setFillColor(darkGrey);
  goldBox.setPosition(x + 10, y + 50);
  drawables.push_back(&goldBox);

  // wave box
  sf::RectangleShape waveBox;
  waveBox.setSize(sf::Vector2f(180, 30));
  waveBox.setFillColor(darkGrey);
  waveBox.setPosition(x + 10, y + 90);
  drawables.push_back(&waveBox);

  // convert int values to string
  std::string healthToString = std::to_string(health);
  std::string waveToString = std::to_string(wave);
  std::string goldToString = std::to_string(gold);

  // text for the health
  sf::Text healthText("Health: " + healthToString + "/15", font, 15);
  healthText.setPosition(x + 13, y + 15);
  healthText.setFillColor(sf::Color::White);
  healthText.setStyle(sf::Text::Bold);
  drawables.push_back(&healthText);

  // text for the gold
  sf::Text goldText("Gold: " + goldToString, font, 15);
  goldText.setPosition(x + 13, y + 55);
  goldText.setFillColor(sf::Color::White);
  goldText.setStyle(sf::Text::Bold);
  drawables.push_back(&goldText);

  // text for the wave
  sf::Text waveText("Current wave: " + waveToString, font, 15);
  waveText.setPosition(x + 13, y + 95);
  waveText.setFillColor(sf::Color::White);
  waveText.setStyle(sf::Text::Bold);
  drawables.push_back(&waveText);

  drawDrawables(window, drawables);

}