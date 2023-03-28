//
// Created by Severin on 27.03.2023.
//

#include "Sphere.hpp"

#include <cmath>
#include <utility>

class Hit Sphere::Hit(const Ray& r, double min, double max) {
    class Hit res;

    Vec3 oc = r.origin - center;
    auto a = r.direction.norm() * r.direction.norm();
    auto half_b = dot(oc, r.direction);
    auto c = oc.norm() * oc.norm() - radius*radius;
    auto discriminant = half_b*half_b - a*c;

    if (discriminant < 0)
        return res;

    auto sqrtd = sqrt(discriminant);

    // Find the nearest root that lies in the acceptable range.
    auto root = (-half_b - sqrtd) / a;
    if (root < min || max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < min || max < root)
            return res;
    }

    res.t = root;
    res.point = r.At(res.t);
    res.normal = (res.point - center) / radius;
    res.hit = true;
    res.material = material;

    return res;
}

Sphere::Sphere(Vec3 center, double radius, std::shared_ptr<Material> material) :
center(center), radius(radius), material(std::move(material)) {

}
