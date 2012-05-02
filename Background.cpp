/*
 * Background.cpp
 *
 *  Created on: Apr 30, 2012
 *      Author: thomas
 */

#include "Background.h"

Background::Background(char * sprite, float velX) {
	SetID(MISC);
	SetCollidable(false);

	GameObject::Load(sprite, "");
	m_frameWidth = GameObject::GetSpriteWidth();
	m_velX = velX;
	m_dirX = -1;
}

void Background::Draw() {

	GameObject::Draw();

	if ((m_posX + m_frameWidth) < WIDTH) {
		GameObject::Draw(m_posX+m_frameWidth,m_posY);
	}
}
void Background::Update() {
	GameObject::Update();

	if (m_posX + m_frameWidth <= 0) {
		m_posX = 0;
	}
}

