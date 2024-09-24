#ifndef COLLISION_HPP
#define COLLISION_HPP

#include <Component/Component/Component.hpp>
#include <Vector2/Vector2.hpp>

class Collision : public Component{
public:
	Collision(const Vector2& fisrt_point, const Vector2& second_point);
	~Collision();

	Vector2 fisrtPoint() const;
	Vector2 secondPoint() const;
	void setFisrtPoint(const Vector2& fisrt_point);
	void setSecondPoint(const Vector2& second_point);

protected:
	const componentType getType() const;

private:
	Vector2 _fisrtPoint;
	Vector2 _secondPoint;
};

#endif //COLLISION_HPP
