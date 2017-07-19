#include "SDL_init.h"

//using namespace SDL_init;
//
//bool Setup();
//bool Cleanup();
//void Update();

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

SDL_Window* window = NULL;
SDL_Surface* screenSurface = NULL;

bool SDL_init::Setup() {
	bool success = true;

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		printf("SDL could no initialize! SDL_Error: %s \n", SDL_GetError());
		success = false;
	}
	else {
		window = SDL_CreateWindow("Dragon Ball 0!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (window == NULL) {
			printf("Window could not be created! SDL_Error: %s \n", SDL_GetError());
			success = false;
		}
		else {
			Uint32 color = SDL_MapRGB(screenSurface->format, 0xFF, 0xFF, 0xFF);
			if (SDL_FillRect(screenSurface, NULL, color) < 0) {
				printf("SDL rect could not be filled! SDL_Error: %s\n", SDL_GetError());
				success = false;
			}
		}
		
	}
	
	return success;
}
bool SDL_init::Cleanup() {
	bool initSuccess = true;

	SDL_DestroyWindow(window);
	SDL_Quit();
	return initSuccess;
}
void SDL_init::Update() {
	SDL_UpdateWindowSurface(window);


}
