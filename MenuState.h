/*
 * MenuState.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef MENUSTATE_H_
#define MENUSTATE_H_

#include <SDL/SDL.h>
#include "GameState.h"
#include "Sprite.h"

class MenuState: public GameState {
public:
	void Init();
	void Clean();

	void Pause();
	void Resume();

	void HandleEvents();
	void Update();
	void Draw();

	//Implement Singleton Pattern
	static MenuState* Instance() {
		return &m_MenuState;
	}
protected:
	MenuState() {
	}
	;
private:
	static MenuState m_MenuState;
	SDL_Surface* menuSprite;
};

#endif /* MENUSTATE_H_ */
