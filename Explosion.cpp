/*
 * Explosion.cpp
 *
 *  Created on: Apr 27, 2012
 *      Author: thomas
 */

#include "Explosion.h"

Explosion::Explosion(float x, float y, SDL_Surface *sprite) {
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
	m_frameWidth = 120;
	m_frameHeight = 120;

	m_frameCount = 0;
	m_frameDelay = 1;

	m_maxFrame = 12;
	m_animationColumns = 3;
	m_animationRow = 0;
	m_animationDirection = 1;

	SetSprite (sprite);
	SetID(EXPLOSION);
	SetCollidable(false);
}

void Explosion::Update() {
	GameObject::Update();
	if (++m_frameCount >= m_frameDelay) {
		m_curFrame += m_animationDirection;

		if ((m_curFrame * m_animationRow) >= m_maxFrame - m_animationColumns) {
			m_curFrame = 0;
			m_animationRow = 0;
			SetAlive(false);
		} else if (m_curFrame >= m_animationColumns) {
			m_animationRow += m_animationDirection;
			m_curFrame = 0;
		}
		m_frameCount = 0;
	}
}
void Explosion::Draw() {
	GameObject::DrawSprite();
}
