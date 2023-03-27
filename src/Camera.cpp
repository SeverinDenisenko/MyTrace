//
// Created by Severin on 27.03.2023.
//

#include "Camera.hpp"

Camera::Camera(double viewportWidth, double viewportHeight, double focalLength) :
        viewportWidth(viewportWidth), viewportHeight(viewportHeight), focalLength(focalLength) {
    horizontal = {double(this->viewportWidth), .0, .0};
    vertical = {.0, double(this->viewportHeight), .0};
    lowerLeftCorner = origin - horizontal / 2. - vertical / 2. - Vec3(.0, .0, this->focalLength);
}

Ray Camera::getRay(double u, double v) const {
    return {origin, lowerLeftCorner + u * horizontal + v * vertical - origin};
}
