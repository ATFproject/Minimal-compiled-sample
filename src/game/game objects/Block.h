//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_BLOCK_H
#define SFML_TANK_BATTLEROYALE_BLOCK_H

#include "../game.h"
#include "GameObject.h"

namespace game {
  class Block : public GameObject {
  private:
    sf::Vector2f pos;

  public:
    explicit Block(const sf::Vector2f &pos, const std::string &TexName) : GameObject() {
      sprite.setTexture(*resourceHandler.LoadTexture(TexName));
      sprite.setPosition(pos);
    }

    ~Block() override = default;

    void draw( sf::RenderWindow * window ) override {
      window->draw(sprite);
    }

    void tick( sf::RenderWindow * window ) override {
      sprite.move(1, 0);
    }
  };
}
#endif //SFML_TANK_BATTLEROYALE_BLOCK_H
