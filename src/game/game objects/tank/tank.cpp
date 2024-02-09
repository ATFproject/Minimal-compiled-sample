#pragma clang diagnostic push
#pragma ide diagnostic ignored "cppcoreguidelines-narrowing-conversions"
//
// Created by livefish on 1/9/24.
//

#include "game_mod.h"
#include "tank.h"


void game::Tank::tick(window * window, game::Game & game) {
    gameObject::tick(window, game);

    /*for (auto & gameObject: game.gameObjects) {
      if (gameObject.get() != this) {
        if (gameObject->type == gameObjectType::BLOCK
            && gameObject->sprite.getGlobalBounds().intersects(sprite.getGlobalBounds())) {
          pos = {300, 200};
        }
      }
    } */

    using
    enum sf::Keyboard::Scancode;

    if (game.isKeyPressed(sf::Keyboard::Scancode::A)) {
        body->SetAngularVelocity(-1);
    } else if (game.isKeyPressed(sf::Keyboard::Scancode::D)) {
        body->SetAngularVelocity(1);
    } else {
        body->SetAngularVelocity(0);
    }

    b2Vec2 dir = b2Vec2(std::cos(body->GetAngle()), std::sin(body->GetAngle()));
    dir.Normalize();

    b2Vec2 vel = body->GetLinearVelocity();
    float force = 1000 / game.deltaTime();

    if (game.isKeyPressed(sf::Keyboard::Scancode::W)) {
        body->ApplyForceToCenter(force * dir, true);
    } else if (game.isKeyPressed(sf::Keyboard::Scancode::S)) {
        body->ApplyForceToCenter(force * -dir, true);
    }

    body->ApplyForceToCenter(b2Dot(dir, vel) * -vel, true);

    sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi + 90);

    game.mainView.setCenter(body->GetPosition().x, body->GetPosition().y);
}

game::Tank::Tank(
        const sf::Vector2f & pos, const sf::Vector2f & Size, const sf::Texture & Tex, const sf::Color & Col
                ) : gameObject(gameObjectType::BLOCK, pos), tex(Tex), size(Size), col(Col) {
    bodyDef.type = b2_dynamicBody;
    shape.SetAsBox(size.x / 2, size.y / 2);
    maxVel = b2Vec2(40, 40);
    friction = 0.2;
}

void game::Tank::addToWorld(b2World & world) {
    gameObject::addToWorld(world);

    b2FixtureDef blockFixDef;
    blockFixDef.shape = &shape;

    blockFixDef.density = 1;
    blockFixDef.friction = 0.1f;
    fix = body->CreateFixture(&blockFixDef);
    sprite.setTexture(tex);
    sprite.setScale(size.x / tex.getSize().x, size.y / tex.getSize().y);
    sprite.setOrigin(tex.getSize().x / 2, tex.getSize().y / 2);
    sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
    sprite.setRotation(body->GetAngle() * 180 / b2_pi);
}


#pragma clang diagnostic pop