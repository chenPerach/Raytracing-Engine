#include "sphere.hpp"

Sphere::Sphere(const vec3f center, const float radius) : pos(center), radius(radius), color() {}
Sphere::Sphere(const vec3f center, const float radius, Material color) : pos(center), radius(radius), color(color) {}
Sphere::Sphere() : pos(vec3f(0, 0, 0)), radius(0) {}

bool Sphere::ray_intersect(const vec3f &origin, const vec3f &direction) const
{
    float distance = ((pos - origin) - direction * ((pos - origin) * direction)).size();
    return distance <= radius;
}
vec3f Sphere::get_color() const
{
    return this->color.get_color();
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
