//
// Created by livefish on 1/13/24.
//

#ifndef SFML_TANK_BATTLEROYALE_RESOURCES_H
#define SFML_TANK_BATTLEROYALE_RESOURCES_H

#include "game_def.h"

#include <memory>

namespace game {
  class asset {
  protected:
    explicit asset( std::string FileName ) : fileName(std::move(FileName)) {}
    
    template<typename T>
      std::shared_ptr<T> load( const std::string & FileName ) {
        std::string path = "../resources/" + FileName;
        auto data = std::make_shared<T>();
        bool res;
        if constexpr (requires { data->loadFromFile(path); }) {
          res = data->loadFromFile(path);
        } else if constexpr (requires { data->openFromFile(path); }) {
          res = data->openFromFile(path);
        } else {
          std::cerr << "No matching load function found!" << std::endl;
          res = false;
        }
        if (!res) {
          std::cerr << "Failed to load \"" << path << "\", exiting'" << std::endl;
          exit(30);
        }
        return data;
      }
  
  public:
    std::string fileName;
    
    virtual ~asset() = default;
  };
  
  class texture : public asset {
  public:
    std::shared_ptr<sf::Texture> data;
    
    explicit texture( const std::string & FileName ) : asset(FileName) {
      data = load<sf::Texture>("images/" + FileName);
    }
    
    operator const sf::Texture &() const { // NOLINT(*-explicit-constructor)
      return *data;
    }
  };
  
  class soundBuffer : public asset {
  public:
    std::shared_ptr<sf::SoundBuffer> data;
    
    explicit soundBuffer( const std::string & FileName ) : asset(FileName) {
      data = load<sf::SoundBuffer>("sounds/" + FileName);
    }
    
    operator const sf::SoundBuffer &() const { // NOLINT(*-explicit-constructor)
      return *data;
    }
  };
  
  class music : public asset {
  public:
    std::shared_ptr<sf::Music> data;
    
    explicit music( const std::string & FileName ) : asset(FileName) {
      data = load<sf::Music>("sounds/" + FileName);
    }
    
    operator sf::Music *() const { // NOLINT(*-explicit-constructor)
      return data.get();
    }
  };
}

#endif //SFML_TANK_BATTLEROYALE_RESOURCES_H
