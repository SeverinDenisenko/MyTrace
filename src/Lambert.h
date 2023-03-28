//
// Created by Severin on 28.03.2023.
//

#ifndef MYTRACE_LAMBERT_H
#define MYTRACE_LAMBERT_H

#include "Material.hpp"
#include "Color.h"

class Lambert : public Material{
public:
    explicit Lambert(Color albedo);

    Ray Scatter(const Ray &in, const Hit &hit, Color& attenuation) const override;

    Color albedo;
private:
    static Vec3 randomVectorInUnitSphere();
    static Vec3 randomInHemisphere(const Vec3& normal);
};


#endif //MYTRACE_LAMBERT_H
