#include "Core.hpp"
#include <ostream>
#include <Component/Texture/Texture.hpp>
#include <Entity/Entity.hpp>


#define WIDTH 800
#define HEIGHT 600

char *img_path;

void setPath(char* path)
{
	img_path = path;
	// std::cout << img_path << std::endl;
}

SDL_Texture *loadEntityTexture(std::list<Entity*> entities, SDL_Renderer *renderer)
{
	SDL_Texture *img;
	std::vector<Component*> cp_list = entities.front()->getComponentList();
	for (auto cp : cp_list)
	{
		if (dynamic_cast<Texture*>(cp))
		{
			Texture texture = *dynamic_cast<Texture*>(cp);
			img = IMG_LoadTexture(renderer, texture.path().c_str());
			std::cout << texture.path() << std::endl;
		}
	}
	return img;
}


void test(std::list<Entity*> entities)
{
	// variable declarations
	SDL_Window *win = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Texture *img = NULL;
	int w, h; // texture width & height
	
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return;
	
	// create the window and renderer
	// note that the renderer is accelerated
	win = SDL_CreateWindow("Image Loading", 100, 100, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
	
	// load our image
	img = loadEntityTexture(entities, renderer);
	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
	SDL_Rect texr; texr.x = 10; texr.y = 10; texr.w = w; texr.h = h; 
	
	// main loop
	while (1) {
		
		// event handling
		SDL_Event e;
		if ( SDL_PollEvent(&e) ) {
			if (e.type == SDL_QUIT)
				break;
		} 
		
		// clear the screen
		SDL_RenderClear(renderer);
		// copy the texture to the rendering context
		SDL_RenderCopy(renderer, img, NULL, &texr);
		// flip the backbuffer
		// this means that everything that we prepared behind the screens is actually shown
		SDL_RenderPresent(renderer);
		
	}
	
	SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	
	return;
}