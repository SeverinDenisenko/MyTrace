//
// Created by Severin on 26.03.2023.
//

#include "Ray.hpp"

Ray::Ray(const Vec3& origin, const Vec3& direction) : origin(origin), direction(direction) {

}

Vec3 Ray::At(Vec3::ValueType t) const {
    return origin + direction * t;
}
