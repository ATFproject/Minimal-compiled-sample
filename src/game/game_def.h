//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAME_DEF_H
#define SFML_TANK_BATTLEROYALE_GAME_DEF_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <box2d/box2d.h>

#include <iostream>
#include <cmath>

#include "window.h"

namespace game {
  const int PPM = 30; // Pixels per meter for box2D conversion
  
  template<typename T>
    inline sf::Vector2<T> norm( const sf::Vector2<T> & toNorm ) {
      float len = sqrtf(toNorm.x * toNorm.x + toNorm.y * toNorm.y);
      return sf::Vector2<T>{toNorm.x / len, toNorm.y / len};
    }
  
  inline void printVec( const b2Vec2 & vec ) {
    std::cout << "(" << vec.x << ", " << vec.y << ")" << std::endl;
  }
  
  class Timer;
  
  class asset;
  class texture;
  class soundBuffer;
  class music;
  class font;
  
  class resourceHandler;
  
  class Keyboard;
  
  class Game;
  class gameSettings;
  
  enum class gameObjectType;
  class gameObject;
  class Block;
  class Tank;
}

#endif //SFML_TANK_BATTLEROYALE_GAME_DEF_H
