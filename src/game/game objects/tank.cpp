//
// Created by livefish on 1/9/24.
//

#include "game_mod.h"

#include <cmath>

void game::Tank::tick( window * window, game::Game & game ) {
  for (auto & gameObject: game.gameObjects) {
    if (gameObject != this) {
      if (gameObject->type == GameObjectType::BLOCK
          && gameObject->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        pos = {300, 200};
      }
    }
  }
  
  using
  enum sf::Keyboard::Scancode;
  
  if (game.isKeyPressed(A))
    bodyDirRad -= 1 * game.timer.deltaTime.asSeconds();
  if (game.isKeyPressed(D))
    bodyDirRad += 1 * game.timer.deltaTime.asSeconds();
  
  bodyDir = norm(sf::Vector2f(std::cos(bodyDirRad), std::sin(bodyDirRad)));
  
  if (game.isKeyPressed(W))
    pos += bodyDir * 75.f * game.timer.deltaTime.asSeconds();
  if (game.isKeyPressed(S))
    pos -= bodyDir * 75.f * game.timer.deltaTime.asSeconds();
  
  if (game.isKeyPressed(R))
    sprite.setScale(sprite.getScale() + sf::Vector2f(0.1, 0.1));
  if (game.isKeyPressed(F))
    sprite.setScale(sprite.getScale() - sf::Vector2f(0.1, 0.1));
  
  if (game.isKeyPressed(Right)) {
    game.mainView.rotate(-20 * game.timer.deltaTime.asSeconds());
  }
  
  if (game.isKeyPressed(Left)) {
    game.mainView.rotate(20 * game.timer.deltaTime.asSeconds());
  }
  
  sf::Color color = sprite.getColor();
  if (game.isKeyPressed(Z)) {
    if (color.r == 255)
      color.r = 0;
    else
      color.r += 1;
  }
  if (game.isKeyPressed(X)) {
    if (color.g == 255)
      color.g = 0;
    else
      color.g += 1;
  }
  if (game.isKeyPressed(C)) {
    if (color.b == 255)
      color.b = 0;
    else
      color.b += 1;
  }
  sprite.setColor(color);
  
  sprite.setPosition(pos);
  sprite.setRotation(bodyDirRad / M_PI * 180 + 90);
}

game::Tank::Tank() : GameObject(GameObjectType::TANK) {
  sprite.setTexture(*resourceHandler.LoadTexture("tanks/tank raw.png"));
  sprite.setColor(sf::Color::Black);
  
  pos = {300, 200};
  bodyDir = gunDir = {0, -1};
  bodyDirRad = 0;
  gunDirRad = 0;
  
  sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
  sprite.setPosition(pos);
  
}


