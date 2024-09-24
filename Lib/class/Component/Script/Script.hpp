#ifndef SCRIPT_HPP
#define SCRIPT_HPP

#include <string>
#include <Component/Component/Component.hpp>


class Script : public Component{
public:
	Script(const std::string& path);
	~Script();

	std::string path() const;
	void setPath(const std::string& path);

protected:
	const componentType getType() const;

private:
	std::string _path;
};



#endif //SCRIPT_HPP
