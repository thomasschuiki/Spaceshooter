/*
 * Sprite.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef SPRITE_H_
#define SPRITE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

class Sprite {
public:
	static bool m_is_sprite;

	Sprite();
	static SDL_Surface* Load(char* pFile);
	static SDL_Surface* Load(char* pFile, int r, int g, int b);
	static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y);
	static bool Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2,
			int y2, int width, int height);
};

#endif /* SPRITE_H_ */
