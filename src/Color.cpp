#include "Color.hpp"
Color::Color():vec3f(){}
Color::Color(const float r,const float g, const float b): vec3f(r,g,b){}
Color::Color(const int r,const int g,const int b):vec3f((float)r/255,(float)g/255,(float)b/255){}