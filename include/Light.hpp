#pragma once
#include "geometry.hpp"
class Light
{
private:
    float intensity;
    vec3f position;
public:
    Light();
    Light(vec3f position,float intensity);
    float get_intesity() const;
    vec3f get_position() const;
};

