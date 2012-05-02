/*
 * Asteroid.h
 *
 *  Created on: Apr 18, 2012
 *      Author: thomas
 */

#ifndef ASTEROID_H_
#define ASTEROID_H_

#include "GameObject.h"
#include "Player.h"

class Asteroid: public GameObject {
public:
	Asteroid(int x,int y,SDL_Surface *sprite,Player *p);

	void Update();
	void Draw();
	void Collided(int objectID);
private:
	Player *p;
};

#endif /* ASTEROID_H_ */
