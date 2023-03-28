//
// Created by Severin on 28.03.2023.
//

#ifndef MYTRACE_LAMBERT_H
#define MYTRACE_LAMBERT_H

#include "Material.hpp"
#include "Color.h"
#include "Random.hpp"

class Lambert : public Material{
public:
    explicit Lambert(Color albedo);

    Ray Scatter(const Ray &in, const Hit &hit, Color& attenuation) override;

    Color albedo;
private:
    Random random;

    Vec3 randomVectorInUnitSphere();
    Vec3 randomInHemisphere(const Vec3& normal);
};


#endif //MYTRACE_LAMBERT_H
