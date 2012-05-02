/*
 * Game.cpp
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#include "Game.h"
#include "GameState.h"
#include <sstream>
Game::~Game() {

}

void Game::Init(const char* title, int width, int height, int bpp,
		bool fullscreen) {
	int flags = 0;
	std::stringstream window_title;

	//initialize SDL
	SDL_Init(SDL_INIT_EVERYTHING);

	SDL_initFramerate( &framemanager );

	// topframerate = 60
	SDL_setFramerate( &framemanager, 60 );

	TTF_Init();
	font18 = TTF_OpenFont("assets/font/FreeSans.ttf", 18);

	window_title << title << " FPS: " << SDL_getFramerate(&framemanager);
	//set titlebar
	SDL_WM_SetCaption(window_title.str().c_str(), title);

	if (fullscreen) {
		flags = SDL_FULLSCREEN;
	}

	//create the screen surface
	m_pScreen = SDL_SetVideoMode(width, height, bpp, flags);

	m_bFullscreen = fullscreen;

	m_bRunning = true;



	printf("Game Initialized Successfully\n");
}

void Game::HandleEvents() {
	//let the state handle events
	states.back()->HandleEvents();
}

void Game::Update() {
	//let the state update the game
	states.back()->Update();
}

void Game::Draw() {
	//let the state draw the screen
	states.back()->Draw();
	SDL_Flip(m_pScreen);
}

void Game::Clean() {
	while (!states.empty()) {
		states.back()->Clean();
		states.pop_back();
	}

	TTF_CloseFont( font18 );

	//shutdown SDL
	SDL_Quit();
	TTF_Quit();

}
void Game::ChangeState(GameState* state) {
	//cleanup the current state
	if (!states.empty()) {
		states.back()->Clean();
		states.pop_back();
	}

	//store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PushState(GameState* state) {
	//pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	//store and init the new state
	states.push_back(state);
	states.back()->Init();
}

void Game::PopState() {
	//cleanup the current state
	if (!states.empty()) {
		states.back()->Clean();
		states.pop_back();
	}

	//resume previous state
	if (!states.empty()) {
		states.back()->Resume();
	}
}

