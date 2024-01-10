//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAME_DEF_H
#define SFML_TANK_BATTLEROYALE_GAME_DEF_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>
#include <cmath>

#include "window.h"

namespace game {
  template<typename T>
    inline sf::Vector2<T> norm( const sf::Vector2<T> & toNorm ) {
      float len = sqrtf(toNorm.x * toNorm.x + toNorm.y * toNorm.y);
      return sf::Vector2<T>{toNorm.x / len, toNorm.y / len};
    }

  class Timer;

  class ResourceHandler;
  extern ResourceHandler resourceHandler;

  class Game;

  enum class GameObjectType;
  class GameObject;
  class Keyboard;
  class Block;
  class Tank;
}

#endif //SFML_TANK_BATTLEROYALE_GAME_DEF_H