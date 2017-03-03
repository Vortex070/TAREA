#include "vec3.h"

Vec3::Vec3(const float & x, const float & y, const float & z):
	x(x), y(y), z(z)
{

}

/*Vec3 Vec3::operator+(const Vec3 & rh)
{
	return Vec3(x+rh.y,y+rh.y,z+rh.z);
}*/

Vec3::Vec3():
	x(0),y(0),z(0)
{}

Vec3 Vec3::midPoint(const Vec3 & p0, const Vec3 & p1)
{
	Vec3 pm;
	pm.x = (p0.x + p1.x) / (2.0f);
	pm.y = (p0.y + p1.y) / (2.0f);
	pm.z = (p0.z + p1.z) / (2.0f);
	return pm;
}