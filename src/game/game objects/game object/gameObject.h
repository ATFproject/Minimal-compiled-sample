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
        explicit gameObject(gameObjectType newType, const sf::Vector2f & pos) : type(newType), body(nullptr) {
            bodyDef.position.Set(pos.x, pos.y);
            bodyDef.angle = 0.f;
            bodyDef.allowSleep = true;
            bodyDef.fixedRotation = false;
        }

    public:
        gameObjectType type;
        sf::Sprite sprite;
        sf::RectangleShape hitbox;

        b2Body * body;
        b2Fixture * fix;
        b2BodyDef bodyDef;

        gameObject() = delete;

        virtual void tick(window * window, Game & game);

        virtual void addToWorld(b2World & world);

        virtual void draw(window * window, Game & game);

        virtual ~gameObject() = default;
    };
}


#endif //SFML_TANK_BATTLEROYALE_GAMEOBJECT_H
