//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
#define SFML_TANK_BATTLEROYALE_GAMEOBJECT_H

#include "../gameDef.h"

namespace game {
  class GameObject {
  protected:
    GameObject() {}

  public:
    sf::Sprite sprite;

    virtual void tick( sf::RenderWindow * window ) = 0;

    virtual void draw( sf::RenderWindow * window ) = 0;

    virtual ~GameObject() = default;
  };
}


#endif //SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
