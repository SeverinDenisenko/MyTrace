//
// Created by Severin on 27.03.2023.
//

#ifndef MYTRACE_SCENE_H
#define MYTRACE_SCENE_H

#include <vector>

#include "Object.hpp"
#include "Hit.hpp"

class Scene {
public:
    Scene() = default;

    void Add(const std::shared_ptr<Object>& object);
    class Hit Hit(const Ray& ray, double min, double max) const;

private:
    std::vector<std::shared_ptr<Object>> objects;
};


#endif //MYTRACE_SCENE_H
