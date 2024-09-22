#ifndef NOVA_ENGINE_COMPONENT_HPP
#define NOVA_ENGINE_COMPONENT_HPP

typedef enum {
	COLLISION = 0,
	SCRIPT = 1,
	TEXTURE = 2,
	TRANSFORM = 3
} componentType;

class Component {
public:
    Component();
	virtual ~Component();

	virtual const componentType getType() const = 0;
	
};

#endif // NOVA_ENGINE_COMPONENT_HPP