#pragma once
#include "geometry.hpp"
class Material
{
private:
    vec3f color;    
public:
    Material(const vec3f color);
    Material();
    vec3f get_color()const ;
    static Material transperent;
    inline bool operator==(const Material& other)const ;
};

