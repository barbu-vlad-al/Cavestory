#ifndef GRAPHICS_H
#define GRAPHICS_H

#include <map>
#include <string>

struct SDL_Window;
struct SDL_Renderer;
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Rect;

class Graphics{
public:
	Graphics();
	~Graphics();

	/*loads an image into the _spriteSheets map if it doesn't already exist
	used this map in order to load the sprites only once*/
	SDL_Surface* loadImage(const std::string &filePath);
	
	// draws images - SDL_Textures to the screen
	void blitSurface(SDL_Texture* source, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle);
	
	//renders everything to the screen
	void flip();

	//clears the screen
	void clear();

	SDL_Renderer* getRenderer() const;
private:
	SDL_Window* _window;
	SDL_Renderer* _renderer;

	std::map<std::string, SDL_Surface*> _spriteSheets;
};

#endif
