#pragma once
#include "vector.hpp"
#include "Material.hpp"
#include <math.h>
class Sphere
{
public:
    vec3f pos;
    float radius;
    Material material;
    Sphere(const vec3f pos, const float radius);
    Sphere(const vec3f pos, const float radius,const Material material);
    Sphere();
    bool ray_intersect(const vec3f &origin, const vec3f &direction) const;
    float get_distance(const vec3f &origin, const vec3f &direction) const;
    vec3f get_color()const;
};