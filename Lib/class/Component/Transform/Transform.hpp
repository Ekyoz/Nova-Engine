#ifndef NOVA_ENGINE_TRANSFORM_HPP
#define NOVA_ENGINE_TRANSFORM_HPP

#include <Component/Component/Component.hpp>
#include <Vector2/Vector2.hpp>

#ifdef _WIN32
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT
#endif

class Transform : public Component {
public:
	Transform(const Vector2& position, const Vector2& rotation, float scale);
	~Transform();

	Vector2 position() const;
	Vector2 rotation() const;
	float scale() const;
	void setPosition(const Vector2& position);
	DLL_EXPORT void setPosition(float x, float y);
	void setRotation(const Vector2& rotation);
	void setRotation(float x, float y);
	void setScale(float scale);

protected:
	const componentType getType() const;

private:
	Vector2 _position;
	Vector2 _rotation;
	float _scale;
};


#endif //NOVA_ENGINE_TRANSFORM_HPP
