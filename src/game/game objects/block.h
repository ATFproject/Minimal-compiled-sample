//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_BLOCK_H
#define SFML_TANK_BATTLEROYALE_BLOCK_H

#include "game_def.h"

#include "gameObject.h"
#include "resourceHandler.h"

namespace game {
  class Block : public GameObject {
  private:
    sf::Vector2f pos;
  
  public:
    explicit Block( const sf::Vector2f & pos, const std::string & TexName ) : GameObject(GameObjectType::BLOCK) {
      sprite.setTexture(*resourceHandler.LoadTexture(TexName));
      sprite.setPosition(pos);
    }
  };
}
#endif //SFML_TANK_BATTLEROYALE_BLOCK_H
