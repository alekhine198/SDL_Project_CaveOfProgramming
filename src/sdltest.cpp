//============================================================================
// Name        : sdltest.cpp
// Author      : Angel Ale
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Screen.h"
#include <iostream>
#include <Math.h>
#include <stdlib.h>
#include <ctime>
#include "Swarm.h"
#include "Particle.h"
int main(int argc, char* argv[]) {

	srand(time(NULL));

	mySdl::Screen screen;

	if(!screen.init()){
		std::cout << "couldn't initialize sdl";
	}

	mySdl::Swarm swarm;
	const int WIDTH = mySdl::Screen::SCREEN_WIDTH/2;
	const int HEIGHT = mySdl::Screen::SCREEN_HEIGHT/2;
	while(true){

		int elapsed = SDL_GetTicks();
		swarm.update(elapsed);
		unsigned char green = (unsigned char)((1+cos(elapsed * 0.0001)* 128));
		unsigned char red = (unsigned char)((1+cos(elapsed * 0.0002)* 128));
		unsigned char blue = (unsigned char)((1+cos(elapsed * 0.0001)* 128));

		const mySdl::Particle * pParticle = swarm.getParticles();

		for(int i =0; i<mySdl::Swarm::NPARTICLES; i++){
			mySdl::Particle particle = pParticle[i];

			int x = (particle.m_x +1) * WIDTH;
			int y = particle.m_y * WIDTH + HEIGHT;

			screen.setPixels(x, y, red, green, blue);
		}
		/*

		std::cout << (int)green << " " << (int)red << " " <<(int) blue << "\n";
		//unsigned char green = (unsigned char)((1 + sin(elapsed * 0.0001)) * 128);
		//unsigned char red = (unsigned char)((1 + sin(elapsed * 0.0002)) * 128);
		//unsigned char blue = (unsigned char)((1 + sin(elapsed * 0.0003)) * 128);


		for(int y =0; y< mySdl::Screen::SCREEN_HEIGHT; y++){
			for(int x=0; x<mySdl::Screen::SCREEN_WIDTH; x++){
				screen.setPixels(x,y,red,green,blue);
			}
		}*/

		screen.boxBlur();

		screen.screenUpdate();

		if(!screen.processEvents()){
			break;
		}
	}

	screen.close();
	return 0;
}
