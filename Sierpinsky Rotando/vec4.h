#pragma once
class Vec4
{
public:
	float x, y, z, w;

	Vec4();
	Vec4& operator+ (const Vec4& v);
	Vec4& operator- (const Vec4& v);
	Vec4(const float &x, const float &y, const float &z, const float &w);
	
};