//
// Created by Severin on 27.03.2023.
//

#ifndef MYTRACE_OBJECT_HPP
#define MYTRACE_OBJECT_HPP

#include "Ray.hpp"
#include "Hit.hpp"

class Object {
public:
    virtual Hit Hit(const Ray& ray, double min, double max) = 0;

    virtual ~Object() = default;
};


#endif //MYTRACE_OBJECT_HPP
