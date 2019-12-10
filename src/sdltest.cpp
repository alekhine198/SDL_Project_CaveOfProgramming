//============================================================================
// Name        : sdltest.cpp
// Author      : Angel Ale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <stdio.h>
#include <cstring>
#include <SDL2/SDL.h>
using namespace std;

int main(int argc, char* argv[]) {

	const int SCREEN_HEIGHT = 600;
	const int SCREEN_WIDTH = 800;
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_Window * window = 0;

	window = SDL_CreateWindow("Hello World",
	SDL_WINDOWPOS_CENTERED,
	SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

	if (window == NULL) {
		SDL_Quit();
		printf("cannot open window %s\n", SDL_GetError());
		return 2;
	}

	SDL_Renderer * renderer = SDL_CreateRenderer(window, -1,
			SDL_RENDERER_PRESENTVSYNC);

	SDL_Texture * texture = SDL_CreateTexture(renderer,
			SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH,
			SCREEN_HEIGHT);

	if (renderer == NULL) {
		printf("%s\n", SDL_GetError());
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 2;
	}

	if (texture == NULL) {
		printf("%s\n", SDL_GetError());
		SDL_DestroyRenderer(renderer);
		SDL_DestroyWindow(window);
		SDL_Quit();
		return 3;
	}
	
	Uint32 *buffer32 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	Uint32 *buffer32 = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];

	memset(buffer32,0x32,SCREEN_HEIGHT*SCREEN_WIDTH*sizeof(Uint32));

	SDL_UpdateTexture(texture, NULL,buffer32,SCREEN_WIDTH*sizeof(Uint32));
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, texture, NULL,NULL);
	SDL_RenderPresent(renderer);

	SDL_Event event;

	bool quit = false;

	while (!quit) {

		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
		}
	}

	// Cleanup and Quit
	SDL_DestroyTexture(texture);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
