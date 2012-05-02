/*
 * GameObject.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#include "GameObject.h"
#include "File.h"

GameObject::GameObject() {
	m_posX = 0;
	m_posY = 0;

	m_velX = 0;
	m_velY = 0;

	m_dirX = 0;
	m_dirY = 0;

	m_boundX = 0;
	m_boundY = 0;

	m_curFrame = 0;
	m_frameWidth = 0;
	m_frameHeight = 0;
	m_frameCount = 0;
	m_frameDelay = 0;
	m_maxFrame = 0;
	m_animationColumns = 0;
	m_animationRow = 0;
	m_animationDirection = 0;

	m_pID = 0;
	m_pAlive = true;
	m_pCollidable = true;
	m_pSprite = NULL;
}

void GameObject::Load(char* sprite, char* properties) {
	m_pSprite = Sprite::Load(sprite);
	File file;
	file.Open(properties);
	file.GetFloat(&m_posX);
	file.GetFloat(&m_posY);
}

void GameObject::Load(char* sprite, char* properties, int r, int g, int b) {

	m_curFrame = 0;
	m_pSprite = Sprite::Load(sprite, r, g, b);
	File file;
	file.Open(properties);
	file.GetFloat(&m_posX);
	file.GetFloat(&m_posY);
}

void GameObject::Update() {
	m_posX += m_velX * m_dirX;
	m_posY += m_velY * m_dirY;
}

void GameObject::Draw(void) {
	this->Draw(m_posX,m_posY);
}

void GameObject::Draw(float x, float y) {
	Sprite::Draw(GameInst::Instance()->GetScreen(), m_pSprite, x, y);
}

void GameObject::Clean() {
	SDL_FreeSurface(m_pSprite);
	delete this;
}

void GameObject::DrawSprite() {
	int fx = (m_curFrame % m_animationColumns) * m_frameWidth;
	int fy = m_animationRow * m_frameHeight;

	int x = m_posX - m_frameWidth / 2;
	int y = m_posY - m_frameHeight / 2;

	Sprite::Draw(GameInst::Instance()->GetScreen(), m_pSprite, x, y, fx, fy,
			m_frameWidth, m_frameHeight);
}

bool GameObject::CheckCollisions(GameObject *otherObject) {
	float oX = otherObject->GetX();
	float oY = otherObject->GetY();

	int obX = otherObject->GetBoundX();
	int obY = otherObject->GetBoundY();

	return (m_posX + m_boundX > oX - obX && m_posX - m_boundX < oX + obX
			&& m_posY + m_boundY > oY - obY && m_posY - m_boundY < oY + obY);

}
void GameObject::Collided(int objectID) {
}
bool GameObject::Collidable() {
	return m_pAlive && m_pCollidable;
}
