/*
 * Screen.h
 *
 *  Created on: 10 dic 2019
 *      Author: tropi
 */

#ifndef SCREEN_H_
#define SCREEN_H_

#include <SDL2/SDL.h>

namespace mySdl{

class Screen {
public:
	const static int SCREEN_HEIGHT = 600;
	const static int SCREEN_WIDTH = 800;
private:
	SDL_Window * m_window;
	SDL_Renderer * m_renderer;
	SDL_Texture * m_texture;
	Uint32 * m_buffer1;
	Uint32 * m_buffer2;
public:
	Screen();
	bool init();
	bool processEvents();
	void setPixels(int x, int y, Uint8 red, Uint8 green, Uint8 blue);
	void screenUpdate();
	void boxBlur();
	void close();
};

}//namespace mySdl
#endif /* SCREEN_H_ */
