#include "Vector2Int.hpp"

Vector2Int::Vector2Int(): Vector<int>(0, 0) {}

Vector2Int::Vector2Int(int x, int y) : Vector(x, y) {}

Vector2Int::~Vector2Int() {}


Vector2Int Vector2Int::operator+(const Vector2Int &src) const {
	Vector2Int vector2Int(this->getX() + src.getX(), this->getY() + src.getY());
	return vector2Int;
}

Vector2Int Vector2Int::operator-(const Vector2Int &src) const {
	Vector2Int vector2Int(this->getX() + src.getX(), this->getY() + src.getY());
	return vector2Int;
}

Vector2Int Vector2Int::operator*(const int scalar) const {
	Vector2Int vector2Int(this->getX() * scalar, this->getY() * scalar);
	return vector2Int;
}

Vector2Int Vector2Int::operator/(const int scalar) const {
	Vector2Int vector2Int(this->getX() / scalar, this->getY() / scalar);
	return vector2Int;
}