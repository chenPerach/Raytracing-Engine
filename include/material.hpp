#pragma once
#include "geometry.hpp"
class Material
{
private:
    Vec3f color;    
public:
    Material(const Vec3f color);
    Material();
    Vec3f get_color()const ;
    static Material transperent;
    inline bool operator==(const Material& other)const ;
};

