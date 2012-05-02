/*
 * PauseState.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef PAUSESTATE_H_
#define PAUSESTATE_H_

#include <SDL/SDL.h>
#include "GameState.h"
#include "Sprite.h"

class PauseState: public GameState {
public:
	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	// Implement Singleton Pattern
	static PauseState* Instance() {
		return &m_PauseState;
	}

protected:

	PauseState() {
	}

private:
	static PauseState m_PauseState;

	SDL_Surface* pauseSprite;

};

#endif /* PAUSESTATE_H_ */
