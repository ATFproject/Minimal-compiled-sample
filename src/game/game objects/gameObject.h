//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
#define SFML_TANK_BATTLEROYALE_GAMEOBJECT_H

#include "game_def.h"

namespace game {
  enum class gameObjectType {
    BLOCK,
    TANK,
  };
  
  class gameObject {
  protected:
    explicit gameObject( gameObjectType newType ) : type(newType) {}
  
  public:
    gameObjectType type;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;
    
    gameObject() = delete;
    
    virtual void tick( window * window, Game & game );
    
    virtual void draw( window * window, Game & game );
    
    virtual ~gameObject() = default;
  };
}


#endif //SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
