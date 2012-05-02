/*
 * PauseState.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#include <stdio.h>

#include <SDL/SDL.h>
#include "Game.h"
#include "PauseState.h"

PauseState PauseState::m_PauseState;

void PauseState::Init() {
	pauseSprite = NULL;
	pauseSprite = Sprite::Load("assets/img/paused.bmp");

	printf("PauseState Init Successful\n");
}

void PauseState::Clean() {
	printf("PauseState Clean Successful\n");
}

void PauseState::Resume() {
	printf("PauseState Resume Successful\n");
}

void PauseState::Pause() {
	printf("PauseState Pause Successful\n");
}

void PauseState::HandleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				GameInst::Instance()->PopState();
				break;
			default:
				break;
			}
			break;
		default:
			break;
		}
	}
}

void PauseState::Update() {
}

void PauseState::Draw() {
	Sprite::Draw(GameInst::Instance()->GetScreen(), pauseSprite, 0, 0);
	SDL_Flip(GameInst::Instance()->GetScreen());
}

