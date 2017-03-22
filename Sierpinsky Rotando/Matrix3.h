#pragma once
#include "Vec3.h"
#include "Vec3.h"
class Matrix3
{
public:
	float m[3][3];

	Matrix3();
	Matrix3(const float val[3][3]);

	Vec3& operator* (const Vec3& v);

	static  Matrix3 Rotate(const float a);
	static Matrix3 Identity();
	static Matrix3 Translate(const Vec3 pos);

	Matrix3& operator* (const Matrix3& v);

	static Matrix3 MatM(const Matrix3 & v, const Matrix3 & p);
};
