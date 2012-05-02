/*
 * PlayState.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef PLAYSTATE_H_
#define PLAYSTATE_H_

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

#include "GameState.h"
#include "GameObject.h"
#include "Player.h"
#include "Bullet.h"
#include "Asteroid.h"
#include "Explosion.h"
#include "Background.h"

#include <vector>
#include <sstream>

class PlayState: public GameState {
public:
	std::vector<GameObject*> GameObjects; //vector of pointers to gameobjects
	std::vector<GameObject*>::iterator GOiter; //GameObject iterator
	std::vector<GameObject*>::iterator GOiter2; //GameObject iterator helper

	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

// Implement Singleton Pattern
	static PlayState* Instance() {
		return &m_PlayState;
	}
protected:
	PlayState() {
	}

private:
	static PlayState m_PlayState;
	Player * player;
	Bullet * bullet;
	Explosion * explosion;
	Background * bg;
	Background * mg;
	Background * fg;
	SDL_Surface * asteroid_sprite;
	SDL_Surface * explosion_sprite;
	SDL_Surface * message;

	std::stringstream score;
};

#endif /* PLAYSTATE_H_ */
