//
// Created by livefish on 1/9/24.
//

#include "Tank.h"

#include "game.h"

void game::Tank::tick( window * window, game::Game & game ) {
  for (auto & gameObject: game.gameObjects) {

  }
}

void game::Tank::draw( window * window, game::Game & game ) {
  type;
}

game::Tank::Tank() : GameObject(GameObjectType::TANK) {

}

