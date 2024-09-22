#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <Component/Component/Component.hpp>

class Texture : public Component{
public:
	Texture(const std::string& path);
	~Texture();

	std::string path() const;
	void setPath(const std::string& path);

protected:
	const componentType getType() const;

private:
	std::string _path;
};

#endif //TEXTURE_HPP
