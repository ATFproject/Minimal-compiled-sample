//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_TIMER_H
#define SFML_TANK_BATTLEROYALE_TIMER_H

#include "game_def.h"

namespace game {
    class Timer {
    private:
        sf::Clock clock {};
        sf::Time previousTime = clock.getElapsedTime();
        int frameCounter = 0;

    public:
        sf::Time time, deltaTime, fpsTime;
        double fps = 30;

        void response() {
            time = clock.getElapsedTime();
            deltaTime = time - previousTime;
            frameCounter++;
            if (time.asSeconds() - fpsTime.asSeconds() > 0.5) {
                fps = frameCounter /
                      static_cast<float>((time.asSeconds() - fpsTime.asSeconds())); // NOLINT(*-narrowing-conversions)
                fpsTime = time;
                frameCounter = 0;
            }
            previousTime = time;
        }
    };
}

#endif //SFML_TANK_BATTLEROYALE_TIMER_H
