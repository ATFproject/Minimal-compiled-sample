//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAMEDEF_H
#define SFML_TANK_BATTLEROYALE_GAMEDEF_H

#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"

#include <iostream>

namespace game {
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

#endif //SFML_TANK_BATTLEROYALE_GAMEDEF_H
