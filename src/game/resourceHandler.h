//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H
#define SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H

#include "game_def.h"

#include <unordered_set>

namespace game {
  class ResourceHandler {
  private:
    std::vector<sf::Texture *> textures;

  public:
    sf::Texture * LoadTexture( const std::string & TexName ) {
      auto * tex = new sf::Texture();
      std::string path = "../resources/images/" + TexName;
      if (!tex->loadFromFile(path)) {
        std::cerr << "Failed to load \"" << path << "\", exiting'" << std::endl;
        exit(30);
      }
      textures.push_back(tex);
      return tex;
    }

    void clean() {
      std::for_each(textures.begin(), textures.end(), [&]( const auto & item ) {
        delete item;
      });
      std::cout << "CLEANED!" << std::endl;
    }

    virtual ~ResourceHandler() {
      // TODO: Add proper cleaning (WTF is happening?!) threads :(
    }
  };
}

#endif //SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H
