//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
#define SFML_TANK_BATTLEROYALE_GAMEOBJECT_H

#include "gameDef.h"
#include "window.h"

namespace game {
  enum class GameObjectType {
    BLOCK,
    TANK,
    NONE,
  };

  class GameObject {
  protected:
    explicit GameObject( GameObjectType newType ) : type(newType) {}

  public:
    GameObjectType type;
    sf::Sprite sprite;

    GameObject() = delete;
    virtual void tick( window * window, Game & game ) = 0;

    virtual void draw( window * window, Game & game ) = 0;

    virtual ~GameObject() = default;
  };
}


#endif //SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
