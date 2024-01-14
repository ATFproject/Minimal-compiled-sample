//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_BLOCK_H
#define SFML_TANK_BATTLEROYALE_BLOCK_H

#include "game_def.h"

#include "game objects/game object/gameObject.h"
#include "resources/resourceHandler.h"
#include "game/game.h"

namespace game {
  class Block : public gameObject {
  private:
    b2PolygonShape shape;
    sf::Texture &tex;
  public:
    explicit Block( const sf::Vector2f & pos, const sf::Vector2f & size, sf::Texture & Tex ) : gameObject(
            gameObjectType::BLOCK), tex(Tex) {
      bodyDef.position.Set(pos.x, pos.y);
      bodyDef.angle = 0.f;
      bodyDef.allowSleep = true;
      bodyDef.fixedRotation = false;
      bodyDef.type = b2_dynamicBody; /* No moving on collisions, can move itself */
      shape.SetAsBox(size.x / 2, size.y / 2);
    }
    
    void addToWorld( b2World & world ) override {
      gameObject::addToWorld(world);
      
      b2FixtureDef blockFixDef;
      blockFixDef.shape = &shape;
      
      blockFixDef.density = 1;
      blockFixDef.friction = 0.1f;
      fix = body->CreateFixture(&blockFixDef);
      
      sprite.setTexture(tex);
      sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
      sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
      sprite.setRotation(body->GetAngle() * 180 / b2_pi);
    }
    
    void tick( window * window, Game & game ) override {
      static int angle = 0;
      gameObject::tick(window, game);
      if (game.isKeyPressed(sf::Keyboard::Scancode::Up))
        body->ApplyAngularImpulse(1000, true);
      if (game.isKeyPressed(sf::Keyboard::Scancode::Down))
        body->ApplyAngularImpulse(-1000, true);
      if (game.isKeyPressed(sf::Keyboard::Scancode::Right))
        body->ApplyLinearImpulse(b2Vec2(1000, 0), body->GetWorldCenter(), true);
      if (game.isKeyPressed(sf::Keyboard::Scancode::Left))
        body->ApplyLinearImpulse(b2Vec2(-1000, 0), body->GetWorldCenter(), true);
      
      
      sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
      sprite.setRotation(body->GetAngle() * 180 / b2_pi);
    }
    
    virtual void draw( window * window, Game & game ) override {
      gameObject::draw(window, game);
    }
  };
}

#endif //SFML_TANK_BATTLEROYALE_BLOCK_H
