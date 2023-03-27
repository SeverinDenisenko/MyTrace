//
// Created by Severin on 26.03.2023.
//

#ifndef MYTRACE_RAY_HPP
#define MYTRACE_RAY_HPP

#include <Algebra3D/Vec3.hpp>

using algebra::Vec3;

class Ray {
public:
    Ray(const Vec3& origin, const Vec3& direction);

    Vec3 At(Vec3::ValueType t) const;

    Vec3 origin;
    Vec3 direction;
};


#endif //MYTRACE_RAY_HPP
