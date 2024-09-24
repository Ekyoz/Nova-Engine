#ifndef NOVA_ENGINE_ENTITY_HPP
#define NOVA_ENGINE_ENTITY_HPP

#include <string>

#include <string>
#include <vector>
#include <Component/Component/Component.hpp>

std::string generate_UUID();

class Entity {
public:
	Entity();
	~Entity();

	const std::string &getUUID() const;
	void createComponent(Component *component);
	void addChild(Entity* entity);

	std::vector<Component*>& getComponentList();
	std::vector<Entity*> getChildrenEntity() const;

private:
	const std::string _uuid;
	std::vector<Component*> _component_list;
	std::vector<Entity*> _chlidren_entity;
};

#endif //NOVA_ENGINE_ENTITY_HPP
