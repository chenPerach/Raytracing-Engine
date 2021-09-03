#include "material.hpp"

Material Material::transperent(vec3f(-1, -1, -1));
Material::Material() : color(vec3f()) {}
Material::Material(const vec3f color) : color(color) {}
vec3f Material::get_color() const
{
    return color;
}
bool Material::operator==(const Material &other) const
{
    return other.get_color().x == color.x &&
           other.get_color().y == color.y &&
           other.get_color().z == color.z;
}