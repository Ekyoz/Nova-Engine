#include "Entity.hpp"
#include "functional"
#include <ctime>
#include <string>

std::string generate_UUID()
{
	std::string id;
	id.reserve(5);
	const char charset[] = "0123456789abcdefghijklmnopqrstuvwxyz";

	std::srand(std::time(nullptr));

	for (int i = 0; i < 5; ++i)
		id.push_back(charset[std::rand() % (sizeof(charset) - 1)]);
	return id;
}
