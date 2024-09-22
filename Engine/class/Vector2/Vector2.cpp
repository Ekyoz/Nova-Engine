#include "Vector2.hpp"

Vector2::Vector2(): Vector<double>(0, 0) {}

Vector2::Vector2(double x, double y) : Vector<double>(x, y) {}

Vector2::~Vector2() {

}

Vector2 Vector2::normalize() {
	Vector2 norm(getX() / magnitude(), getY() / magnitude());
	return norm;
}

Vector2 Vector2::operator+(const Vector2 &src) const{
	Vector2 vector2(this->getX() + src.getX(), this->getY() + src.getY());
	return vector2;
}

Vector2 Vector2::operator-(const Vector2 &src) const{
	Vector2 vector2(this->getX() - src.getX(), this->getY() - src.getY());
	return vector2;
}

Vector2 Vector2::operator*(const double scalar) const{
	Vector2 vector2(this->getX() * scalar, this->getY() * scalar);
	return vector2;
}

Vector2 Vector2::operator/(const double scalar) const{
	Vector2 vector2(this->getX() / scalar, this->getY() / scalar);
	return vector2;
}

