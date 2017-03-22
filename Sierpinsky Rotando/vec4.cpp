#include "vec4.h"

Vec4::Vec4(): x(0), y(0), z(0), w(0)
{
}

Vec4 & Vec4::operator+(const Vec4 & v)
{

	return Vec4(x + v.x + y, y + v.y, z + v.z, w + v.w);
}

Vec4 & Vec4::operator-(const Vec4 & v)
{
	return Vec4(x - v.x - y, y - v.y, z - v.z, w - v.w);
}

Vec4::Vec4(const float & x, const float & y, const float & z, const float & w):
	x(x), y(y), z(z), w(w)
{

}
