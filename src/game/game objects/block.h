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
        sf::Texture & tex;
        sf::Vector2f size;
        float maxVel, friction;

    public:
        explicit Block(const sf::Vector2f & pos, const sf::Vector2f & size, sf::Texture & Tex) :
                gameObject(gameObjectType::BLOCK, pos), tex(Tex), size(size) {
            bodyDef.type = b2_dynamicBody; /* No moving on collisions, can move itself */
            shape.SetAsBox(size.x / 2, size.y / 2);
            maxVel = 50;
            friction = 0.96;
        }

        void addToWorld(b2World & world) override {
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

        void tick(window * window, Game & game) override {
            gameObject::tick(window, game);

            if (game.isKeyPressed(sf::Keyboard::Scancode::Up)) {
                body->SetAngularVelocity(5);
            } else if (game.isKeyPressed(sf::Keyboard::Scancode::Down)) {
                body->SetAngularVelocity(-5);
            } else {
                body->SetAngularVelocity(0);
            }

            b2Vec2 vel = body->GetLinearVelocity();
            float desiredVel;
            if (game.isKeyPressed(sf::Keyboard::Scancode::Right)) {
                desiredVel = b2Min(vel.x + 0.1f, maxVel);
            } else if (game.isKeyPressed(sf::Keyboard::Scancode::Left)) {
                desiredVel = b2Max(vel.x - 0.1f, -maxVel);
            } else {
                desiredVel = vel.x * friction;
            }

            float velChange = desiredVel - vel.x;
            float impulse = body->GetMass() * velChange;

            body->ApplyLinearImpulse(b2Vec2(impulse, 0), body->GetWorldCenter(), true);

            sprite.setPosition(body->GetPosition().x, body->GetPosition().y);
            sprite.setRotation(body->GetAngle() * 180 / b2_pi);
        }

        virtual void draw(window * window, Game & game) override {
            gameObject::draw(window, game);
        }
    };
}

#endif //SFML_TANK_BATTLEROYALE_BLOCK_H
