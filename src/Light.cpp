#include "Light.hpp"
float Light::get_intesity() const{
    return this->intensity;
}

vec3f Light::get_position() const{
    return this->position;
}
Light::Light():intensity(0),position(vec3f()){}
Light::Light(vec3f position,float intensity):intensity(intensity),position(position){}