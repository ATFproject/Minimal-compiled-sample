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
    
    if (body) {
      hitbox.setPosition(body->GetPosition().x, body->GetPosition().y);
      hitbox.setRotation(body->GetAngle());
    } else {
      hitbox.setOrigin(sprite.getGlobalBounds().width / 2, sprite.getGlobalBounds().height / 2);
      hitbox.setPosition(sprite.getGlobalBounds().getPosition() + sprite.getGlobalBounds().getSize() / 2.f);
      hitbox.setSize(sprite.getGlobalBounds().getSize());
    }
    
    window->win->draw(hitbox);
  }
  window->win->draw(sprite);
}


void game::gameObject::tick( window * window, game::Game & game ) {}

void game::gameObject::addToWorld( b2World & world ) {
  body = world.CreateBody(&bodyDef);
};
