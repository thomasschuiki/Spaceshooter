/*
 * Sprite.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#include "Sprite.h"


SDL_Surface* Sprite::Load(char* pFile) {
	//Temporary storage for the image that's loaded
	SDL_Surface* tempImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	//std::string path = "assets/img/" + filename;
	//Load the image
	tempImage = IMG_Load(pFile);

	//If nothing went wrong in loading the image
	if (tempImage != NULL) {
		//Create an optimized image
		optimizedImage = SDL_DisplayFormatAlpha(tempImage);

		//Free the old image
		SDL_FreeSurface(tempImage);

	} else {
		return NULL;
	}
//Return the optimized image
	return optimizedImage;
}

SDL_Surface* Sprite::Load(char* pFile, int r, int g, int b) {
	//Temporary storage for the image that's loaded
	SDL_Surface* tempImage = NULL;
	SDL_Surface* optimizedImage = NULL;

	//std::string path = "assets/img/" + filename;
	//Load the image
	tempImage = IMG_Load(pFile);

	//If nothing went wrong in loading the image
	if (tempImage != NULL) {
		//Create an optimized image
		optimizedImage = SDL_DisplayFormat(tempImage);

		//Free the old image
		SDL_FreeSurface(tempImage);

		if (optimizedImage != NULL) {
			//Map the color key
			Uint32 colorkey = SDL_MapRGB(optimizedImage->format, r, g, b);
			//Set all pixels of color to be transparent
			SDL_SetColorKey(optimizedImage, SDL_SRCCOLORKEY, colorkey);
		}
	} else {
		return NULL;
	}
//Return the optimized image
	return optimizedImage;
}
bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y) {
	if (dest == NULL || src == NULL) {
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;

	SDL_BlitSurface(src, NULL, dest, &destR);

	return true;
}
/**
 * @param x : x position on screen
 * @param y : y position on screen
 * @param x2 : x position on the sprite
 * @param y2 : y position on the sprite
 * width & height = rectangle from x2/y2 to draw
 * */
bool Sprite::Draw(SDL_Surface* dest, SDL_Surface* src, int x, int y, int x2,
		int y2, int width, int height) {
	if (dest == NULL || src == NULL) {
		return false;
	}

	SDL_Rect destR;

	destR.x = x;
	destR.y = y;

	SDL_Rect srcR;

	srcR.x = x2;
	srcR.y = y2;
	srcR.w = width;
	srcR.h = height;

	SDL_BlitSurface(src, &srcR, dest, &destR);

	return true;
}

