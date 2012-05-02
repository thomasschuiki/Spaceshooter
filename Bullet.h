/*
 * Bullet.h
 *
 *  Created on: Apr 17, 2012
 *      Author: thomas
 */

#ifndef BULLET_H_
#define BULLET_H_

#include "GameObject.h"
#include "Player.h"
#include <SDL/SDL_gfxPrimitives.h>

class Bullet: public GameObject {
public:
	Bullet(float x, float y,Player *p);
	~Bullet(){};

	void Draw();
	void Update();
	void Clean();

	void Collided(int objectID);
private:
	Player *p;
};

#endif /* BULLET_H_ */
