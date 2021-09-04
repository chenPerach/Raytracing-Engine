#pragma once
// #ifndef COLOR_HPP
// #define COLOR_HPP
#include "vector.hpp"
struct Color : public vec3f
{
    Color();
    Color(const float r,const float g,const float b);
    Color(const int r,const int g,const int b);
};
const Color red(255,0,0);
const Color green(0,255,0);
const Color blue(0,0,255);
const Color background(78, 85, 166);
// #endif