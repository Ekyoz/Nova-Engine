#include "Texture.hpp"

Texture::Texture(const std::string& path):
	Component(), _path(path)
{
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