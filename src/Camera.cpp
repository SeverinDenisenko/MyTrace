//
// Created by Severin on 27.03.2023.
//

#include "Camera.hpp"

#include <cmath>

Ray Camera::getRay(double u, double v) const {
    return {origin, lowerLeftCorner + u * horizontal + v * vertical - origin};
}

Camera::Camera(Vec3 from, Vec3 at, Vec3 up, double fov, double aspect) {
    auto theta = fov / 180.0 * 3.14159;
    auto h = tan(theta/2);
    auto viewport_height = 2.0 * h;
    auto viewport_width = aspect * viewport_height;

    auto w = (from - at).unit();
    auto u = cross(up, w).unit();
    auto v = cross(w, u);

    origin = from;
    horizontal = viewport_width * u;
    vertical = viewport_height * v;
    lowerLeftCorner = origin - horizontal/2 - vertical/2 - w;
}
