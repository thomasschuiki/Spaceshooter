#include <iostream>

#include <SDL/SDL.h>
#include "Game.h"
#include "MenuState.h"
#include "PlayState.h"
#include "global.h"

int main(int argc, char *argv[]) {

	GameInst::Instance()->Init("Spaceshooter",WIDTH,HEIGHT,SCREEN_BPP,false);
	GameInst::Instance()->ChangeState(PlayState::Instance());
	srand(time(NULL));
	while (GameInst::Instance()->Running()) {
		GameInst::Instance()->HandleEvents();
		GameInst::Instance()->Update();
		GameInst::Instance()->Draw();
		GameInst::Instance()->StartFramemanager();
	}

	GameInst::Instance()->Clean();

	return 0;
}
