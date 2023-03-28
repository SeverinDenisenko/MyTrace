//
// Created by Severin on 28.03.2023.
//

#include "Metal.hpp"

Ray Metal::Scatter(const Ray& in, const Hit& hit, Color& attenuation) {
    auto direction = reflect(in.direction.unit(), hit.normal);
    attenuation = albedo;
    return Ray(hit.point, direction);
}

Vec3 Metal::reflect(const Vec3& v, const Vec3& n) {
    return v - 2 * dot(v,n) * n;
}

Metal::Metal(Color albedo) : albedo(albedo){

}
