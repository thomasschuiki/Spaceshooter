/*
 * GameObject.h
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "Game.h"
#include "Sprite.h"

class GameObject {
public:

	GameObject();
	virtual ~GameObject() {
	}

	virtual void Load(char* sprite, char* properties);
	virtual void Load(char* sprite, char* properties, int r, int g, int b);
	virtual void Update();
	virtual void Draw(void);
	virtual void Draw(float x, float y);
	virtual void DrawSprite();
	virtual void Clean();

	virtual float GetX() {
		return m_posX;
	}
	virtual float GetY() {
		return m_posY;
	}
	int GetBoundX() {
		return m_boundX;
	}
	int GetBoundY() {
		return m_boundY;
	}

	int GetID() {
		return m_pID;
	}
	void SetID(int id) {
		GameObject::m_pID = id;
	}
	bool GetAlive() {
		return m_pAlive;
	}
	void SetAlive(bool alive) {
		GameObject::m_pAlive = alive;
	}
	bool GetCollidable() {
		return m_pCollidable;
	}
	void SetCollidable(bool collidable) {
		GameObject::m_pCollidable = collidable;
	}

	void SetSprite(SDL_Surface *sprite) {
		m_pSprite = sprite;
	}
	int GetSpriteWidth(){
		return m_pSprite->w;
	}
	bool CheckCollisions(GameObject *otherObject);
	void virtual Collided(int objectID);
	bool Collidable();
protected:
	float m_posX;
	float m_posY;

	float m_velX;
	float m_velY;

	int m_dirX;
	int m_dirY;

	int m_boundX;
	int m_boundY;

	int m_curFrame;
	int m_frameWidth;
	int m_frameHeight;
	int m_frameCount;
	int m_frameDelay;
	int m_maxFrame;
	int m_animationColumns;
	int m_animationRow;
	int m_animationDirection;

private:
	int m_pID;
	bool m_pAlive;
	bool m_pCollidable;
	SDL_Surface* m_pSprite;
};

#endif /* GAMEOBJECT_H_ */
