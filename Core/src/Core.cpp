#include "Core.hpp"
#include <ostream>

#define WIDTH 800
#define HEIGHT 600

void open_window()
{
	Entity entity;
	Window window1;
	auto window = sf::RenderWindow{ { 1920u, 1080u }, "CMake SFML Project" };
	window.setFramerateLimit(144);

	while (window.isOpen())
	{
		for (auto event = sf::Event{}; window.pollEvent(event);)
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.display();
	}
}