#include <Engine.hpp>
#include <Entity/Entity.hpp>

#include "Wrapper.hpp"

typedef void (*EntityPositionCallback)(float x, float y);

extern "C"{
	//-------- Entity --------//
	DLL_EXPORT Entity* createEntity()
	{
		Entity* entity = new Entity();
		entities.push_front(entity);
		return entity;
	}
	DLL_EXPORT void addComponent(Entity* entity, Component* component)
	{
		entity->createComponent(component);
	}

	static EntityPositionCallback position_callback = nullptr;
	DLL_EXPORT void registerCallback(EntityPositionCallback callback)
	{
		position_callback = callback;
	}

	DLL_EXPORT void run()
	{
		std::cout << "test" << endl;
		open_window();
	}
}
