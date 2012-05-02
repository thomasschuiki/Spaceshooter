/*
 * Asteroid.cpp
 *
 *  Created on: Apr 18, 2012
 *      Author: thomas
 */

#include "Asteroid.h"

Asteroid::Asteroid(int x, int y, SDL_Surface *sprite, Player *p) {
	GameObject();

	m_posX = x;
	m_posY = y;

	m_velX = 1;
	m_velY = 0;

	m_dirX = -1;
	m_dirY = 0;

	m_boundX = 35;
	m_boundY = 35;

	m_curFrame = 0;
	m_frameWidth = 64;
	m_frameHeight = 64;

	m_frameCount = 0;
	m_frameDelay = 3;

	m_maxFrame = 64;
	m_animationColumns = 8;
	m_animationRow = 0;
	m_animationDirection = 1;

	SetSprite(sprite);
	SetID(ENEMY);
	Asteroid::p=p;
}

void Asteroid::Update() {
	GameObject::Update();
	if (++m_frameCount >= m_frameDelay) {
		m_curFrame += m_animationDirection;
		if ((m_curFrame * m_animationRow) >= m_maxFrame-m_animationColumns) {
			m_curFrame = 0;
			m_animationRow = 0;
		} else if (m_curFrame >= m_animationColumns) {
			m_animationRow += m_animationDirection;
			m_curFrame = 0;
		}
		/*
		 else if (m_curFrame <= 0){
		 m_curFrame = m_maxFrame;
		 }
		 */
		m_frameCount = 0;
	}

	if (m_posX + m_frameWidth < 0) {
		Collided(BORDER);
	}
}

void Asteroid::Draw() {
	GameObject::DrawSprite();
}

void Asteroid::Collided(int objectID) {
	if (objectID == BORDER) {
		Asteroid::p->LoseLife();
	} else {
		//printf("asteroid collided with: %d \n", objectID);
	}

	if (objectID != ENEMY) {
		SetAlive(false);
	}
}

