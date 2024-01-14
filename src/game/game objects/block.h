//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_BLOCK_H
#define SFML_TANK_BATTLEROYALE_BLOCK_H

#include "game_def.h"

#include "gameObject.h"
#include "resources/resourceHandler.h"

namespace game {
  class Block : public GameObject {
  private:
    sf::Vector2f pos;
  
  public:
    explicit Block( const sf::Vector2f & pos, const sf::Texture & Tex ) : GameObject(GameObjectType::BLOCK) {
      sprite.setTexture(Tex);
      sprite.setPosition(pos);
      sprite.setScale(2, 2);
    }
  };
}

#endif //SFML_TANK_BATTLEROYALE_BLOCK_H
