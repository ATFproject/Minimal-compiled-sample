//
// Created by livefish on 1/9/24.
//

#ifndef SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H
#define SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H

#include "resources.h"

#include <memory>

namespace game {
    class resourceHandler {
    private:
        std::map<const std::string, std::shared_ptr<asset>> resources;

    public:
        template<typename T>
            T & get(const std::string & FileName) {
                auto res = resources.find(FileName);
                std::shared_ptr<asset> ptr;
                if (res != resources.end()) {
                    ptr = res->second;
                } else {
                    ptr = std::shared_ptr<asset>(new T(FileName));
                    resources[FileName] = ptr;
                }
                return *std::dynamic_pointer_cast<T>(ptr);
            }
    };
}

#endif //SFML_TANK_BATTLEROYALE_RESOURCEHANDLER_H
