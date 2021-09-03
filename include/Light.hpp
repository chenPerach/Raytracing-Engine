#pragma once
#include "geometry.hpp"
class Light
{
private:
    float intensity;
    vec3f position;
public:
    Light();
    Light(float intensity,vec3f position);
    inline float get_intesity() const;
    inline vec3f get_position() const;
};

