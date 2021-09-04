#pragma once
#include "vector.hpp"
struct Material
{
    vec3f diffuse_color;
    float kd;
    float ks_exponent; 
    float ks;
    Material(const vec3f color,const float kd);
    Material(const vec3f color,const float kd,const float ks_e,float ks);
    Material();
    inline bool operator==(const Material& other)const ;
};

