//
// Created by livefish on 1/14/24.
//

#include "game_mod.h"
#include "gameObject.h"


void game::gameObject::draw( window * window, game::Game & game ) {
  if (game.settings.showHitboxes) {
    hitbox.setOutlineColor(sf::Color::Red);
    hitbox.setOutlineThickness(1);
    hitbox.setFillColor(sf::Color::Transparent);
    hitbox.setPosition(sprite.getGlobalBounds().getPosition());
    hitbox.setSize(sprite.getGlobalBounds().getSize());
    window->win->draw(hitbox);
  }
  
  window->win->draw(sprite);
}

void game::gameObject::tick( window * window, game::Game & game ) {};
