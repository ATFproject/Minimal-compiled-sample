//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_TANK_H
#define SFML_TANK_BATTLEROYALE_TANK_H

#include "game_def.h"

#include "game objects/game object/gameObject.h"

namespace game {
    class Tank : public gameObject {
    private:
        b2PolygonShape shape;
        const sf::Texture & tex;
        sf::Vector2f size;
        b2Vec2 maxVel;
        float friction;
        sf::Color col;
    public:
        Tank() = delete;

        Tank(
                const sf::Vector2f & pos, const sf::Vector2f & size, const sf::Texture & Tex,
                const sf::Color & Col = sf::Color::White
            );

        void tick(window * window, Game & game) override;

        virtual void addToWorld(b2World & world) override;
    };
}


#endif //SFML_TANK_BATTLEROYALE_TANK_H
