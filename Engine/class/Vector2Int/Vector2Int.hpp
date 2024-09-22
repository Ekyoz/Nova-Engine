#ifndef NOVA_ENGINE_VECTOR2INT_HPP
#define NOVA_ENGINE_VECTOR2INT_HPP

#include <Vector/Vector.hpp>

class Vector2Int : public Vector<int>{
public:
	Vector2Int();
	Vector2Int(int x, int y);
	~Vector2Int();
	
	Vector2Int	operator+(Vector2Int const &src) const;
	Vector2Int	operator-(Vector2Int const &src) const;
	Vector2Int	operator*(const int scalar) const;
	Vector2Int	operator/(const int scalar) const;
};


#endif //NOVA_ENGINE_VECTOR2INT_HPP
