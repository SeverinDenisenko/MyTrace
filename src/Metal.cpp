//
// Created by Severin on 28.03.2023.
//

#include "Metal.hpp"
#include "Random.hpp"

Ray Metal::Scatter(const Ray& in, const Hit& hit, Color& attenuation) {
    auto direction = reflect(in.direction.unit(), hit.normal) + fuzz * randomUnitVector();
    attenuation = albedo;
    return Ray(hit.point, direction);
}

Vec3 Metal::reflect(const Vec3& v, const Vec3& n) {
    return v - 2 * dot(v,n) * n;
}

Metal::Metal(Color albedo, double fuzz) : albedo(albedo), fuzz(fuzz){

}

Vec3 Metal::randomUnitVector() {
    static Random random;

    while (true){
        Vec3 res = {random.Get(), random.Get(), random.Get()};

        if (res.norm() < 1)
            return res.unit();
    }
}
