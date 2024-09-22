#include "Wrapper.hpp"
#include <Core.hpp>

extern "C"{
	//-------- Transform --------//
	DLL_EXPORT Transform* createTransform(float x_position, float y_position, float x_rotation, float y_rotation, float scale){
		Transform* transform = new Transform(Vector2(x_position, y_position), Vector2(x_rotation, y_rotation), scale);
		return transform;
	}
	DLL_EXPORT float getTransformX(Transform* transform)
	{
		return transform->position().getX();
	}
	DLL_EXPORT float getTransformY(Transform* transform)
	{
		return transform->position().getY();
	}
	DLL_EXPORT float getTransformRotX(Transform* transform)
	{
		return transform->rotation().getX();
	}
	DLL_EXPORT float getTransformRotY(Transform* transform)
	{
		return transform->rotation().getY();
	}
	DLL_EXPORT float getTransformScale(Transform* transform)
	{
		return transform->scale();
	}
	
	//-------- Texture --------//
	DLL_EXPORT Texture* createTexture(char *path){
		Texture* texture = new Texture(path);
		return texture;
	}
	
	//-------- Script --------//
	DLL_EXPORT Script* createScript(char *path){
		Script* script = new Script(path);
		return script;
	}
	
	//-------- Collision --------//
	DLL_EXPORT Collision* createCollision(float x_fp, float y_fp, float x_lp, float y_lp){
		Collision* collision = new Collision(Vector2(x_fp, y_fp), Vector2(x_lp, y_lp));
		return collision;
	}

}
