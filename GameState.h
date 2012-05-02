/*
 * GameState.h
 *
 *  Created on: Apr 10, 2012
 *      Author: thomas
 */

#ifndef GAMESTATE_H_
#define GAMESTATE_H_

#include "Game.h"

class GameState {
public:

	virtual void Init() = 0;
	virtual void Clean() = 0;

	virtual void Pause() = 0;
	virtual void Resume() = 0;

	virtual void HandleEvents() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;

	void ChangeState(GameState* state){
		GameInst::Instance()->ChangeState(state);
	}
protected:
	GameState(){}
};

#endif /* GAMESTATE_H_ */
