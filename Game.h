/*
 * Game.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef GAME_H_
#define GAME_H_

#include <SDL/SDL.h>
#include <SDL/SDL_framerate.h>
#include <SDL/SDL_ttf.h>
#include "Sprite.h"
#include "Singleton.h"
#include "global.h"

#include <vector>

class GameState;

class Game {
public:
	~Game();
	void Init(const char* title, int width, int height, int bpp,
			bool fullscreen);
	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();
	void HandleEvents();
	void Update();
	void Draw();
	void Clean();
	bool Running() {
		return m_bRunning;
	}
	void Quit() {
		m_bRunning = false;
	}
	void StartFramemanager(){
		SDL_framerateDelay( &framemanager );
	}
	SDL_Surface* GetScreen() {
		return m_pScreen;
	}
	TTF_Font * Font(){
		return font18;
	}
private:
	Game() {}
	friend class Singleton<Game> ;

	bool m_bRunning;
	bool m_bFullscreen;

	FPSmanager framemanager;
	SDL_Surface* m_pScreen;
	TTF_Font *font18;

	std::vector<GameState*> states;

};
//typedef the game instance so you don't have to type all
//that whenever you want to use it
typedef Singleton<Game> GameInst;

#endif /* GAME_H_ */
