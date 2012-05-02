/*
 * Player.cpp
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#include "Player.h"

Player::Player() {
	GameObject();
	m_pLives = 3;
	m_pScore = 0;

	m_dirX = 0;
	m_dirY = 0;

	m_velX = 6;
	m_velY = 6;

	m_boundX = 10;
	m_boundY = 12;

	m_frameWidth = 43;
	m_frameHeight = 43;
	m_animationColumns = 3;
	m_animationDirection = 1;
	m_animationRow = 1;

	SetID(PLAYER);
}

void Player::Load(char* sprite, char* properties, int r, int g, int b) {
	GameObject::Load(sprite, properties, r, g, b);
}

void Player::Update() {
	GameObject::Update();

	if (m_posX < 0 + m_frameWidth / 2)
		m_posX = 0 + m_frameWidth / 2;
	else if (m_posX > WIDTH - m_frameWidth / 2)
		m_posX = WIDTH - m_frameWidth / 2;

	if (m_posY < 0 + m_frameHeight / 2)
		m_posY = 0 + m_frameHeight / 2;
	else if (m_posY > HEIGHT - m_frameHeight / 2)
		m_posY = HEIGHT - m_frameHeight / 2;
}

void Player::Draw() {
	GameObject::DrawSprite();
}

void Player::Clean() {
	GameObject::Clean();
}

void Player::MoveUp() {
	m_animationRow = 0;
	m_dirY = -1;
}
void Player::MoveDown() {
	m_animationRow = 2;
	m_dirY = 1;
}
void Player::MoveLeft() {
	m_curFrame = 2;
	m_dirX = -1;
}
void Player::MoveRight() {
	m_curFrame = 1;
	m_dirX = 1;
}

void Player::ResetAnimation(int position) {
	if (position == 1) {
		m_animationRow = 1;
		m_dirY = 0;
	} else {
		m_curFrame = 0;
		m_dirX = 0;
	}
}
