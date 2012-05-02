/*
 * Background.h
 *
 *  Created on: Apr 30, 2012
 *      Author: thomas
 */

#ifndef BACKGROUND_H_
#define BACKGROUND_H_

#include "GameObject.h"

class Background: public GameObject {
public:
	Background(char *sprite,float velX);

	void Update();
	using GameObject::Draw;
	void Draw();
};

#endif /* BACKGROUND_H_ */
