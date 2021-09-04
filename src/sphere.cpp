#include "sphere.hpp"

Sphere::Sphere(const vec3f center, const float radius) : pos(center), radius(radius), material() {}
Sphere::Sphere(const vec3f center, const float radius, Material material) : pos(center), radius(radius), material(material) {}
Sphere::Sphere() : pos(vec3f(0, 0, 0)), radius(0) {}

bool Sphere::ray_intersect(const vec3f &origin, const vec3f &direction) const
{
    float distance = ((pos - origin) - direction * ((pos - origin) * direction)).size();
    return distance <= radius;
}
vec3f Sphere::get_color() const
{
    return this->material.diffuse_color;
}
float Sphere::get_distance(const vec3f &origin, const vec3f &direction) const
{
    float d_distance = (pos - origin).size() - radius;
    vec3f p = origin;
    while (abs((p - pos).size() -radius) >= 0.01)
    {
        p = p + direction * (d_distance - radius);
        d_distance = (p - pos).size();
    }
    return (p-origin).size();
}
