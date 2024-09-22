#pragma once

#ifdef _WIN32
	#define DLL_EXPORT __declspec(dllexport)
#else
	#define DLL_EXPORT
#endif

#include <iostream>
#include <Core.hpp>

//-------- Components --------//
#include <Component/Collision/Collision.hpp>
#include <Component/Script/Script.hpp>
#include <Component/Texture/Texture.hpp>
#include <Component/Transform/Transform.hpp>

//-------- Entities --------//
#include <Entity/Entity.hpp>