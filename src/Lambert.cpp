//
// Created by Severin on 28.03.2023.
//

#include "Lambert.h"
#include "Random.hpp"

Ray Lambert::Scatter([[maybe_unused]] const Ray& in, const Hit& hit, Color& attenuation) const {
    auto direction = randomInHemisphere(hit.normal);
    attenuation = albedo;
    return Ray(hit.point, direction);
}


Vec3 Lambert::randomVectorInUnitSphere(){
    static Random random;

    while (true){
        Vec3 res = {random.Get(), random.Get(), random.Get()};

        if (res.norm() < 1)
            return res;
    }
}

Vec3 Lambert::randomInHemisphere(const Vec3& normal){
    Vec3 r = randomVectorInUnitSphere();

    if (dot(r, normal) > 0.0)
        return r;
    else
        return -r;
}

Lambert::Lambert(Color albedo) : albedo(albedo){

}
