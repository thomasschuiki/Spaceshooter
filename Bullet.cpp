/*
 * Bullet.cpp
 *
 *  Created on: Apr 17, 2012
 *      Author: thomas
 */

#include "Bullet.h"

Bullet::Bullet(float x, float y,Player *p){

	GameObject();

	m_posX = x;
	m_posY = y;

	m_dirX = 1;
	m_dirY = 0;

	m_velX = 6;
	m_velY = 0;

	SetID(BULLET);
	Bullet::p = p;
}

void Bullet::Draw() {
	filledCircleRGBA(GameInst::Instance()->GetScreen(), m_posX, m_posY, 1, 255, 255,
			255, 255);
}

void Bullet::Update() {
	GameObject::Update();
	if (m_posX > WIDTH) {
		SetAlive(false);
	}
}

void Bullet::Clean(){
	delete this;
}

void Bullet::Collided(int objectID) {
	if (objectID == ENEMY || objectID == BORDER) {
		SetAlive(false);
	}

	if (objectID == ENEMY){
		Bullet::p->AddPoint();
	}
}


