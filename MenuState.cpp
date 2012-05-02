/*
 * MenuState.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */
#include <stdio.h>

#include <SDL/SDL.h>

#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"

MenuState MenuState::m_MenuState;

void MenuState::Init() {
	menuSprite = NULL;
	menuSprite = Sprite::Load("assets/img/menustate.bmp");
	printf("Menustate Init Successful\n");
}

void MenuState::Clean() {
	printf("Menustate Clean Successful\n");
}

void MenuState::Pause() {
	printf("Menustate Paused Successful\n");
}

void MenuState::Resume() {
	printf("Menustate Resumed Successful\n");
}

void MenuState::HandleEvents() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		switch (event.type) {
		case SDL_QUIT:
			GameInst::Instance()->Quit();
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym) {
			case SDLK_SPACE:
				GameInst::Instance()->ChangeState(PlayState::Instance());
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

void MenuState::Update() {
}

void MenuState::Draw() {
	Sprite::Draw(GameInst::Instance()->GetScreen(), menuSprite, 0, 0);
	SDL_Flip(GameInst::Instance()->GetScreen());
}

