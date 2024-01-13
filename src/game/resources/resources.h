//
// Created by livefish on 1/13/24.
//

#ifndef SFML_TANK_BATTLEROYALE_RESOURCES_H
#define SFML_TANK_BATTLEROYALE_RESOURCES_H

#include <utility>

#include "game_def.h"

namespace game {
  class asset {
  protected:
    explicit asset( std::string FileName ) : fileName(std::move(FileName)) {}
    
    template<typename T>
      T & load( const std::string & FileName ) {
        std::string path = "../resources/" + FileName;
        auto * data = new T;
        if (!data->loadFromFile(path)) {
          std::cerr << "Failed to load \"" << path << "\", exiting'" << std::endl;
          exit(30);
        }
        return *data;
      }
  
  public:
    std::string fileName;
    
    virtual ~asset() = default;
  };
  
  class texture : public asset {
  public:
    sf::Texture data;
    
    explicit texture( const std::string & FileName ) : asset(FileName) {
      data = load<sf::Texture>("/images/" + FileName);
    }
    
    operator const sf::Texture &() const { // NOLINT(*-explicit-constructor)
      return data;
    }
  };
  
  class soundBuffer : public asset {
  public:
    sf::SoundBuffer data;
    
    explicit soundBuffer( const std::string & FileName ) : asset(FileName) {
      data = load<sf::SoundBuffer>("/sounds/" + FileName);
    }
    
    operator const sf::SoundBuffer &() const { // NOLINT(*-explicit-constructor)
      return data;
    }
  };
}

#endif //SFML_TANK_BATTLEROYALE_RESOURCES_H
