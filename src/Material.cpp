#include "Material.hpp"

Material::Material() : diffuse_color(vec3f()),kd(1),ks(0),ks_exponent(0) {}
Material::Material(const vec3f color,const float kd) : diffuse_color(color),kd(kd),ks(0),ks_exponent(0){}
Material::Material(const vec3f color,const float kd,const float specular_exponent,float specular_reflection):diffuse_color(color),kd(kd),ks(specular_reflection),ks_exponent(specular_exponent){}

bool Material::operator==(const Material &other) const
{
    return other.diffuse_color.x == diffuse_color.x &&
           other.diffuse_color.y == diffuse_color.y &&
           other.diffuse_color.z == diffuse_color.z;
}