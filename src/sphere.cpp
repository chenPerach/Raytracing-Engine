#include "sphere.hpp"

Sphere::Sphere(const Vec3f center,const float radius): pos(center),radius(radius),color(){}
Sphere::Sphere(const Vec3f center,const float radius,Material color): pos(center),radius(radius),color(color){}
bool Sphere::ray_intersect(const Vec3f &origin, const Vec3f &direction) const
{
    float distance = ((pos-origin) - direction*((pos-origin)*direction)).size();
    return distance <= radius;
}
Vec3f Sphere::get_color() const{
    return this->color.get_color();
}
float Sphere::get_distance(const Vec3f &origin, const Vec3f &direction) const{

}
