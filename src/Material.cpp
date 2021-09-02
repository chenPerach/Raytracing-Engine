#include "material.hpp"

Material Material::transperent(Vec3f(-1, -1, -1));
Material::Material() : color(Vec3f()) {}
Material::Material(const Vec3f color) : color(color) {}
Vec3f Material::get_color() const
{
    return color;
}
bool Material::operator==(const Material &other) const
{
    return other.get_color().x == color.x &&
           other.get_color().y == color.y &&
           other.get_color().z == color.z;
}