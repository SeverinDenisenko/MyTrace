//
// Created by Severin on 27.03.2023.
//

#include "Scene.h"

void Scene::Add(const std::shared_ptr<Object>& object) {
    objects.push_back(object);
}

class Hit Scene::Hit(const Ray& ray, double min, double max) const {
    if (objects.empty())
        return {};

    class Hit closestHit;
    bool hitted = false;

    for (const auto & object : objects) {
        class Hit hit = object->Hit(ray, min, max);

        if (hit){
            if (hitted){
                if (hit.t < closestHit.t)
                    closestHit = hit;
            } else {
                closestHit = hit;
                hitted = true;
            }
        }
    }

    return closestHit;
}
