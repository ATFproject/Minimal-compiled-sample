//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
#define SFML_TANK_BATTLEROYALE_GAMEOBJECT_H

#include "game_def.h"

namespace game {
  enum class GameObjectType {
    BLOCK,
    TANK,
  };
  
  class GameObject {
  protected:
    explicit GameObject( GameObjectType newType ) : type(newType) {}
  
  public:
    GameObjectType type;
    sf::Sprite sprite;
    sf::RectangleShape hitbox;
    
    GameObject() = delete;
    
    virtual void tick( window * window, Game & game ) {};
    
    virtual void draw( window * window, Game & game ) {
      hitbox.setOutlineColor(sf::Color::Red);
      hitbox.setOutlineThickness(1);
      hitbox.setFillColor(sf::Color::Transparent);
      hitbox.setPosition(sprite.getGlobalBounds().getPosition());
      hitbox.setSize(sprite.getGlobalBounds().getSize());
      window->win->draw(hitbox);
      
      window->win->draw(sprite);
    };
    
    virtual ~GameObject() = default;
  };
}


#endif //SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
