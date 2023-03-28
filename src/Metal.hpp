//
// Created by Severin on 28.03.2023.
//

#ifndef MYTRACE_METAL_HPP
#define MYTRACE_METAL_HPP

#include "Material.hpp"
#include "Color.h"

class Metal : public Material{
public:
    explicit Metal(Color albedo, double fuzz);

    Ray Scatter(const Ray &in, const Hit &hit, Color &attenuation) override;

private:
    Color albedo;
    double fuzz;

    static Vec3 reflect(const Vec3& v, const Vec3& n);
    static Vec3 randomUnitVector();
};


#endif //MYTRACE_METAL_HPP
