#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by livefish on 1/9/24.
//

#include "game_mod.h"

void game::Tank::tick( window * window, game::Game & game ) {
  for (auto & gameObject: game.gameObjects) {
    if (gameObject.get() != this) {
      if (gameObject->type == gameObjectType::BLOCK
          && gameObject->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
        pos = {300, 200};
      }
    }
  }
  
  using
  enum sf::Keyboard::Scancode;
  
  if (game.isKeyPressed(A))
    bodyDirRad -= rotationSpeed * game.deltaTime();
  if (game.isKeyPressed(D))
    bodyDirRad += rotationSpeed * game.deltaTime();
  
  bodyDir = norm(sf::Vector2f(std::cos(bodyDirRad), std::sin(bodyDirRad)));
  
  if (game.isKeyPressed(W))
    pos += bodyDir * speed * game.deltaTime();
  if (game.isKeyPressed(S))
    pos -= bodyDir * speed * game.deltaTime();
  
  sprite.setPosition(pos);
  sprite.setRotation(bodyDirRad / M_PI * 180 + 90);
  game.mainView.setCenter(pos);
}

game::Tank::Tank( const sf::Texture & Tex, const sf::Color & Col ) : gameObject(gameObjectType::TANK) {
  sprite.setTexture(Tex);
  sprite.setColor(Col);
  
  pos = {300, 200};
  bodyDir = gunDir = {0, -1};
  bodyDirRad = 0;
  gunDirRad = 0;
  
  speed = 75;
  rotationSpeed = 1;
  
  sprite.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
  sprite.setPosition(pos);
  sprite.setScale(3, 3);
}

void game::Tank::addToWorld( b2World & world ) {
//  gameObject::addToWorld(world);
}


#pragma clang diagnostic pop