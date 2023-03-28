//
// Created by Severin on 28.03.2023.
//

#ifndef MYTRACE_MATERIAL_HPP
#define MYTRACE_MATERIAL_HPP

#include "Ray.hpp"
#include "Hit.hpp"
#include "Color.h"

class Hit;

class Material {
public:
    virtual Ray Scatter(const Ray& in, const Hit& hit, Color& attenuation) = 0;

    virtual ~Material() = default;
};


#endif //MYTRACE_MATERIAL_HPP
