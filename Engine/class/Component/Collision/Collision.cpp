#include "Collision.hpp"

Collision::Collision(const Vector2& fisrt_point, const Vector2& second_point):
	Component(), _fisrtPoint(fisrt_point), _secondPoint(second_point)
{
}

Collision::~Collision()
{
}

const componentType Collision::getType() const
{
	return COLLISION;
}

//------- Setter and Getter -------//

Vector2 Collision::fisrtPoint() const
{
	return _fisrtPoint;
}

Vector2 Collision::secondPoint() const
{
	return _secondPoint;
}

void Collision::setFisrtPoint(const Vector2& fisrt_point)
{
	_fisrtPoint = fisrt_point;
}

void Collision::setSecondPoint(const Vector2& second_point)
{
	_secondPoint = second_point;
}
