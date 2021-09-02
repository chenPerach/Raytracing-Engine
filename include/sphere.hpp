#pragma once
#include "geometry.hpp"
#include "material.hpp"
#include <math.h>
class Sphere
{
public:
    Vec3f pos;
    float radius;
    Material color;
    Sphere(const Vec3f pos, const float radius);
    Sphere(const Vec3f pos, const float radius,const Material color);

    bool ray_intersect(const Vec3f &origin, const Vec3f &direction) const;
    float get_distance(const Vec3f &origin, const Vec3f &direction) const;
    Vec3f get_color()const;
};