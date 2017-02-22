#pragma once
#include <iostream>

class Vec3
{
public:
	float x, y, z;
	
	//vec3 (x, y, z);

	Vec3 operator + (const Vec3& rh);
	Vec3(const float &x, const float &y, const float &z);
	Vec3();

	Vec3 midPoint(const Vec3& p0, const Vec3& p1);

};