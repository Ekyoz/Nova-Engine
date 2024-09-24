#include "Texture.hpp"

#include <iostream>
#include <ostream>

Texture::Texture(const std::string& path):
	Component(), _path(path)
{
	std::cout << "Create tex with : " << path << std::endl;
}

Texture::~Texture()
{
}

const componentType Texture::getType() const
{
	return TEXTURE;
}

//-------- Getter and Setter -------//

std::string Texture::path() const
{
	return _path;
}

void Texture::setPath(const std::string& path)
{
	_path = path;
}