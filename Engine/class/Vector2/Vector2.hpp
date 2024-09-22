#pragma once

#include <Vector/Vector.hpp>

class Vector2 : public Vector<double> {
public:
	Vector2();
	Vector2(double x, double y);
	~Vector2();
	
	Vector2 normalize();
	
	Vector2 operator+(Vector2 const &src) const;
	Vector2 operator-(Vector2 const &src) const;
	Vector2 operator*(const double scalar) const;
	Vector2 operator/(const double scalar) const;


};
