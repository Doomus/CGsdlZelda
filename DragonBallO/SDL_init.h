#pragma once
#include <SDL.h>
#include <stdio.h>

class SDL_init {
public:
	bool Setup();
	bool Cleanup();
	void Update();
};