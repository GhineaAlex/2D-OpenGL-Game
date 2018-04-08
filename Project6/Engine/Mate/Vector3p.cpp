#include "Vector3p.h"

Vector3p::Vector3p()
{
	x = 0;
	y = 0;
	z = 0;
}

Vector3p::Vector3p(const Vector3p& alt)
{
	x = alt.x;
	y = alt.y;
	z = alt.z;
}

Vector3p::Vector3p(float _x)
{
	x = _x;
	y = _x;
	z = _x;
}

Vector3p::Vector3p(float _x, float _y, float _z)
{
	x = _x;
	y = _y;
	z = _z;
}

Vector3p & Vector3p::operator=(const Vector3p& alt)
{
	x = alt.x;
	y = alt.y;
	z = alt.z;

	return *this; //un pointer catre propria instanta a clasei
}

Vector3p Vector3p::operator+(const Vector3p& alt)
{
	Vector3p p; 
	p.x = x + alt.x;
	p.y = y + alt.y;
	p.z = z + alt.z;

	return p;
}

Vector3p Vector3p::operator-(const Vector3p& alt)
{
	Vector3p p;
	p.x = x - alt.x;
	p.y = y - alt.y;
	p.z = z - alt.z;

	return p;
}

Vector3p Vector3p::operator*(const Vector3p& alt)
{
	Vector3p p;
	p.x = x * alt.x;
	p.y = y * alt.y;
	p.z = z * alt.z;

	return p;
}
Vector3p Vector3p::operator*(float _x)
{
	Vector3p p;
	p.x = x * _x;
	p.y = y * _x;
	p.z = z * _x;

	return p;
}

bool Vector3p::operator == (const Vector3p & alt)
{
	if (x == alt.x && y == alt.y && z == alt.z)
		return true;
	else false;
}

bool Vector3p::operator != (const Vector3p & alt)
{
	if (x != alt.x && y != alt.y && z != alt.z)
		return true;
	else false;
}