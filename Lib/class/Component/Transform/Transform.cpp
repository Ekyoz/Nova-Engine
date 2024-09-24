#include "Transform.hpp"
#include <iostream>

Transform::Transform(const Vector2& position,
	const Vector2& rotation, float scale):
	Component(), _position(position),
	_rotation(rotation), _scale(scale)
{
	std::cout << "Create Transform class" << std::endl;
}

Transform::~Transform() {

}

componentType const Transform::getType() const
{
	return TRANSFORM;
}

//--------- Set and Getter ---------//

Vector2 Transform::position() const
{
	return _position;
}

Vector2 Transform::rotation() const
{
	return _rotation;
}

float Transform::scale() const
{
	return _scale;
}

void Transform::setPosition(const Vector2& position)
{
	_position = position;
}

void Transform::setPosition(float x, float y)
{
	_position.set(x, y);
}

void Transform::setRotation(float x, float y)
{
	_rotation.set(x, y);
}

void Transform::setRotation(const Vector2& rotation)
{
	_rotation = rotation;
}

void Transform::setScale(float scale)
{
	_scale = scale;
}