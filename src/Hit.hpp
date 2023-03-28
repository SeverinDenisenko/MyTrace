//
// Created by Severin on 27.03.2023.
//

#ifndef MYTRACE_HIT_HPP
#define MYTRACE_HIT_HPP

#include <Algebra3D/Vec3.hpp>

#include "Material.hpp"
#include "Color.h"

using algebra::Vec3;

class Material;

class Hit {
public:
    Vec3 point = {.0, .0, .0};
    Vec3 normal = {.0, .0, .0};
    double t = .0;
    std::shared_ptr<Material> material;
    bool hit = false;

    explicit operator bool() const{
        return hit;
    }
};


#endif //MYTRACE_HIT_HPP
