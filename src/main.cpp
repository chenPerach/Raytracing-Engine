#include <limits>
#include <cmath>
#include <iostream>
#include <fstream>
#include <vector>
#include "geometry.hpp"
#include "sphere.hpp"
using namespace std;
Vec3f cast_ray(const Vec3f& origin,const Vec3f& direction,const vector<Sphere>& spheres){
	// if(s.ray_intersect(origin,direction))
	// 	return Vec3f(0.4,0.4,0.3);
	// return Vec3f(0.1,0.12,0.1);

}
void render() {
	vector<Sphere> spheres;
	spheres.push_back(Sphere(Vec3f(3.f,3.f,10.f),1.f,Material(Vec3f(0.2,0.3,0.4))));
	spheres.push_back(Sphere(Vec3f(3.f,3.f,10.f),1.f,Material(Vec3f(0.2,0.3,0.4))));

	const double fov  = 120;
    const int width    = 1024;
    const int height   = 768;
    std::vector<Vec3f> framebuffer(width*height);
	Vec3f origin(0,0,0);
    for (int j = 0; j<height; j++) {
        for (int i = 0; i<width; i++) {
			float x =  ((2*i-width)/(float)width)*tan(fov*0.5)*width/(float)height;
			float y = -((2*j-height)/(float)height)*tan(fov*0.5);
			Vec3f direction = Vec3f(x,y,1).normalize();
			framebuffer[i+j*width] = cast_ray(origin,direction,spheres);
        }
    }
	

	// save framebuffer to file
    std::ofstream ofs;
    ofs.open("./out.ppm");
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for (size_t i = 0; i < height*width; ++i) {
        for (size_t j = 0; j<3; j++) {
            // write value between 0-255 to each pixle
			ofs << (char)(255 * std::max(0.f, std::min(1.f, framebuffer[i][j])));
        }
    }
    ofs.close();
}

int main() {
    render();
    return 0;
}

