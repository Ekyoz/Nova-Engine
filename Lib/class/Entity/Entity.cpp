#include "Entity.hpp"

#include <iostream>

Entity::Entity() : _uuid(generate_UUID()) {
	std::cout << "Creating entity" << std::endl;
}

Entity::~Entity() {}


const std::string &Entity::getUUID() const {
	return _uuid;
}

void Entity::createComponent(Component *component_list)
{
	_component_list.push_back(component_list);
}

void Entity::addChild(Entity* entity)
{
	_chlidren_entity.push_back(entity);
}

std::vector<Component*>& Entity::getComponentList()
{
	return _component_list;
}

std::vector<Entity*> Entity::getChildrenEntity() const
{
	return _chlidren_entity;
}


