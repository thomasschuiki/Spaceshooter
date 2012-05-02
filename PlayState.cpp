/*
 * PlayState.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#include <SDL/SDL.h>

#include "PlayState.h"
#include "PauseState.h"

bool keys[] = { false, false, false, false, false };
enum KEYS {
	UP, DOWN, LEFT, RIGHT, SPACE
};

PlayState PlayState::m_PlayState;

void PlayState::Init() {

	player = new Player();
	player->Load("assets/img/shipsprites.png", "gameobject.txt", 255, 0, 255);

	asteroid_sprite = Sprite::Load("assets/img/asteroid.bmp", 255, 0, 255);
	explosion_sprite = Sprite::Load("assets/img/blue_explosion.jpg", 0, 0, 0);

	bg = new Background("assets/img/starBG.png",1);
	mg = new Background("assets/img/starMG.png",3);
	fg = new Background("assets/img/starFG.png",5);

	GameObjects.push_back(bg);
	GameObjects.push_back(mg);
	GameObjects.push_back(fg);
	GameObjects.push_back(player);

	printf("PlayState Init Successful\n");
}

void PlayState::Clean() {

	SDL_FreeSurface(message);
	//cull the dead
	for (GOiter = GameObjects.begin(); GOiter != GameObjects.end();) {

		//(*GOiter)->Clean();
		delete (*GOiter);
		GOiter = GameObjects.erase(GOiter);

	}

	printf("PlayState Clean Successful\n");
}

void PlayState::Pause() {
	printf("PlayState Paused\n");
}

void PlayState::Resume() {
	printf("PlayState Resumed\n");
}

void PlayState::HandleEvents() {
	SDL_Event event;
	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;
			/*
			 * KEYDOWN
			 * */
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				keys[UP] = true;
				break;
			case SDLK_DOWN:
				keys[DOWN] = true;
				break;
			case SDLK_LEFT:
				keys[LEFT] = true;
				break;
			case SDLK_RIGHT:
				keys[RIGHT] = true;
				break;
			case SDLK_p:
				GameInst::Instance()->PushState(PauseState::Instance());
				break;
			case SDLK_SPACE:
				keys[SPACE] = true;
				bullet = new Bullet(player->GetX() + 17, player->GetY(),
						player);
				GameObjects.push_back(bullet);
				break;
			case SDLK_ESCAPE:
				GameInst::Instance()->Quit();
				break;
			default:
				break;
			}
			break;
			/*
			 * KEYUP
			 * */
		case SDL_KEYUP:
			switch (event.key.keysym.sym) {
			case SDLK_UP:
				keys[UP] = false;
				break;
			case SDLK_DOWN:
				keys[DOWN] = false;
				break;
			case SDLK_LEFT:
				keys[LEFT] = false;
				break;
			case SDLK_RIGHT:
				keys[RIGHT] = false;
				break;
			case SDLK_SPACE:
				keys[SPACE] = false;
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
	if (keys[UP])
		player->MoveUp();
	else if (keys[DOWN])
		player->MoveDown();
	else
		player->ResetAnimation(1);

	if (keys[LEFT])
		player->MoveLeft();
	else if (keys[RIGHT])
		player->MoveRight();
	else
		player->ResetAnimation(0);

	if (keys[SPACE]) {

	}

}

void PlayState::Update() {

	if (rand() % 100 == 0) {
		Asteroid * asteroid = new Asteroid(WIDTH, rand() % HEIGHT,
				asteroid_sprite, player);
		GameObjects.push_back(asteroid);
	}

	//do updates
	for (GOiter = GameObjects.begin(); GOiter < GameObjects.end(); ++GOiter) {
		(*GOiter)->Update();
	}
	//collisions
	for (GOiter = GameObjects.begin(); GOiter < GameObjects.end(); ++GOiter) {
		if (!(*GOiter)->Collidable()) {
			continue;
		}

		for (GOiter2 = GOiter; GOiter2 != GameObjects.end(); ++GOiter2) {
			if (!(*GOiter2)->Collidable()) {
				continue;
			}
			if ((*GOiter)->GetID() == (*GOiter2)->GetID()) {
				continue;
			}

			if ((*GOiter)->CheckCollisions((*GOiter2))) {
				(*GOiter)->Collided((*GOiter2)->GetID());
				(*GOiter2)->Collided((*GOiter)->GetID());

				explosion = new Explosion(
						((*GOiter)->GetX() + (*GOiter2)->GetX()) / 2,
						((*GOiter)->GetY() + (*GOiter2)->GetY()) / 2,
						explosion_sprite);
				GameObjects.push_back(explosion);
			}
		}
	}

	//cull the dead
	for (GOiter = GameObjects.begin(); GOiter != GameObjects.end();) {
		if (!(*GOiter)->GetAlive()) {
			//(*GOiter)->Clean();
			delete (*GOiter);
			GOiter = GameObjects.erase(GOiter);
		} else {
			GOiter++;
		}
	}

}

void PlayState::Draw() {
	SDL_FillRect(GameInst::Instance()->GetScreen(), NULL, 0x000000);

	for (GOiter = GameObjects.begin(); GOiter < GameObjects.end(); ++GOiter) {
		(*GOiter)->Draw();
	}

	SDL_Flip(GameInst::Instance()->GetScreen());
}

