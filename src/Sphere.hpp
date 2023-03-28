//
// Created by Severin on 27.03.2023.
//

#ifndef MYTRACE_SPHERE_HPP
#define MYTRACE_SPHERE_HPP

#include "Object.hpp"
#include "Material.hpp"

class Sphere : public Object{
public:
    Sphere(Vec3 center, double radius, std::shared_ptr<Material> material);

    class Hit Hit(const Ray &r, double min, double max) override;

private:
    Vec3 center;
    double radius;
    std::shared_ptr<Material> material;
};


#endif //MYTRACE_SPHERE_HPP
