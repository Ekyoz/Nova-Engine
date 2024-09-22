#pragma once

#include <exception>
#include <math.h>
#include <stdexcept>

template<typename T>
class Vector {
public:
	Vector(T x, T y) : _x(x), _y(y) {}
	~Vector() {}

	T getX() const { return _x; }
	T getY() const { return _y; }
	void setX(T x) { _x = x; }
	void setY(T y) { _y = y; }
	void set(T x, T y) {_x = x; _y = y;}
	
	T magnitude(){
		return (T)sqrt(pow(_x, 2) + pow(_y, 2));
	}
	
	T sqrMagnitude(){
		return (T)sqrt(this->magnitude());
	}
	
	bool equals(Vector<T> vector){
		if (this->_x == vector._x && this->_y == vector._y)
			return true;
		return false;
	}
	
	T operator[](const int pos) const {
		if (pos == 0)
			return _x;
		if (pos == 1)
			return _y;
		else
			throw std::out_of_range("Index must be either 0 or 1.");
	}
	
	bool operator==(Vector<T> const &copy){
		if (copy._x == this->_x && copy._y == this->_y)
			return true;
		return false;
	}
	
	Vector<T> &operator=(Vector<T> const &src){
		return *this;
	}

private:
	T _x;
	T _y;
};
