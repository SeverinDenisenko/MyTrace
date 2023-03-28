#include <cmath>

#include <PAMImage/PPM.hpp>
#include <SLib/SLog.hpp>

#include "Camera.hpp"
#include "Ray.hpp"
#include "Sphere.hpp"
#include "Scene.h"
#include "Random.hpp"

using Color = algebra::Vec3;

Color rayColor(const Ray& ray, const Scene& scene){
    Hit hit = scene.Hit(ray, 0, std::numeric_limits<double>::infinity());
    if (hit) {
        return 0.5 * (hit.normal + Color(1,1,1));
    } else {
        Vec3 unit_direction = (ray.direction).unit();
        double t = 0.5*(unit_direction.j + 1.0);
        return (1.0-t)*Color(1.0, 1.0, 1.0) + t*Color(0.5, 0.7, 1.0);
    }
}

int main() {
    S_LOG_LEVEL_INFO;
    S_INFO("Start rendering...");

    std::size_t width = 256;
    std::size_t height = 256;
    auto aspect = double(width) / double(height);

    const int samples = 100;

    Camera camera(2.0, 2.0 / aspect, 1.0);
    Scene scene;
    scene.Add(std::make_shared<Sphere>(Vec3(0,0,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(-2,0,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(2,0,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(0,-2,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(-2,-2,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(2,-2,-3), 1));
    scene.Add(std::make_shared<Sphere>(Vec3(0,1001,-3), 1000));

    pam::PPM ppm(width, height, pam::PPM::Max16);

    Random random;

    for (std::size_t i = 0; i < width; ++i) {
        for (std::size_t j = 0; j < height; ++j) {
            Color color;
            for (int k = 0; k < samples; ++k) {
                auto u = (i + random.Get()) / (width - 1);
                auto v = (j + random.Get()) / (height - 1);

                Ray ray = camera.getRay(u, v);
                color += rayColor(ray, scene);
            }

            auto r = static_cast<std::uint16_t>(color.i / samples * pam::PPM::Max16);
            auto g = static_cast<std::uint16_t>(color.j / samples * pam::PPM::Max16);
            auto b = static_cast<std::uint16_t>(color.k / samples * pam::PPM::Max16);

            ppm(j, i) = {r, g, b};
        }
    }

    ppm.Write("out.ppm");

    S_INFO("End rendering...");

    return 0;
}
