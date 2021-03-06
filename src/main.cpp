#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "vector.hpp"
#include "sphere.hpp"
#include "Light.hpp"
#include "Color.hpp"
using namespace std;

#define RADIANS(x) (x) * M_PI / 180

vec3f cast_ray(const vec3f &origin, const vec3f &direction, vector<Sphere> &spheres, vector<Light> &lights)
{
    // find if ray intersects any object
    Sphere min_sphere;
    float min_distance = numeric_limits<float>::max();
    bool intersects = false;
    for (Sphere s : spheres)
        if (s.ray_intersect(origin, direction))
        {
            if (!intersects)
                intersects = true;
            float distance = s.get_distance(origin, direction);
            if (distance < min_distance)
            {
                min_distance = distance;
                min_sphere = s;
            }
        }
    if (!intersects)
        return background;

    // add defuse coloring to the pixel
    float diffiuse_light_intensity = 0;
    vec3f hit = direction * min_distance + origin, N = (min_sphere.pos - hit).normalize();
    float specular_reflection_intensity = 0;
    for (Light l : lights)
    {
        vec3f L = (hit - l.get_position()).normalize();
        vec3f R = N*(2*(L*N)) - L; // getting the reflected ray
        diffiuse_light_intensity += min_sphere.material.kd*l.get_intesity() * std::max(0.f, L * N);
        specular_reflection_intensity += pow(std::max(0.f,R*direction),min_sphere.material.ks_exponent)*min_sphere.material.ks*l.get_intesity();
    }

    return min_sphere.get_color() * diffiuse_light_intensity + vec3f(1,1,1)* specular_reflection_intensity;
}
void render()
{
    vector<Sphere> spheres;
    spheres.push_back(Sphere(vec3f(0.f, 0.f, 4.f), .75f, Material(red,0.75,3,0.125)));
    spheres.push_back(Sphere(vec3f(1.5f, 1.5f, 2.5f), 1.f, Material(green,0.75,3,0.1)));
    spheres.push_back(Sphere(vec3f(-1.5f, -1.f, 3.f), 1.f, Material(blue,0.75,3,0.1)));

    vector<Light> lights;
    lights.push_back(Light(vec3f(0, 8, -2.5), 6.f));
    // lights.push_back(Light(vec3f(0,-5,-2.5),0.5f));
    const double fov = RADIANS(90);
    const int width = 1024;
    const int height = 768;
    std::vector<vec3f> framebuffer(width * height);
    vec3f origin(0, 0, 0);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float x = (2 * (j + 0.5) / (float)width - 1) * tan(fov / 2.) * width / (float)height;
            float y = -(2 * (i + 0.5) / (float)height - 1) * tan(fov / 2.);
            vec3f direction = vec3f(x, y, 1).normalize();
            framebuffer[j + i * width] = cast_ray(origin, direction, spheres, lights);
        }
    }

    // save framebuffer to file
    std::ofstream ofs;
    ofs.open("./out.ppm");
    ofs << "P6\n"
        << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height * width; ++i)
    {
        for (size_t j = 0; j < 3; j++)
        {
            // write value between 0-255 to each pixle
            ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main()
{
    render();
    return 0;
}
