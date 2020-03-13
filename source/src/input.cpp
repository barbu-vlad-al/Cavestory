#include "../headers/input.h"

//reset the keys that are no longer relevant at the beginning of each new frame
void Input::beginNewFrame(){
	this->_pressedKeys.clear();
	this->_releasedKeys.clear();
}

//called on keypress
void Input::keyDownEvent(const SDL_Event& event){
	this->_pressedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = true;
}

//called on release
void Input::keyUpEvent(const SDL_Event& event){
	this->_releasedKeys[event.key.keysym.scancode] = true;
	this->_heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key){
	return this->_pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key){
	return this->_releasedKeys[key];
}

bool Input::wasKeyHeld(SDL_Scancode key){
	return this->_heldKeys[key];
}
