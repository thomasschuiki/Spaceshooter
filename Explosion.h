/*
 * Explosion.h
 *
 *  Created on: Apr 27, 2012
 *      Author: thomas
 */

#ifndef EXPLOSION_H_
#define EXPLOSION_H_

#include "GameObject.h"

class Explosion: public GameObject {
public:
	Explosion(float x,float y,SDL_Surface *sprite);
	void Destroy();
	void Update();
	void Draw();
};

#endif /* EXPLOSION_H_ */
