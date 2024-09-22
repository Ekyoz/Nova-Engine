#include "Script.hpp"

Script::Script(const std::string& path):
	Component(), _path(path)
{
}

Script::~Script()
{
}

const componentType Script::getType() const
{
	return SCRIPT;
}

//------- Getter and Setter -------//

std::string Script::path() const
{
	return _path;
}

void Script::setPath(const std::string& path)
{
	_path = path;
}
