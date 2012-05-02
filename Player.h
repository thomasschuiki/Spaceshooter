/*
 * Player.h
 *
 *  Created on: Apr 11, 2012
 *      Author: thomas
 */

#ifndef PLAYER_H_
#define PLAYER_H_

#include "GameObject.h"

class Player: public GameObject {
public:
	Player();
	~Player(){};

	void Load(char* sprite, char* properties, int r, int g, int b);
	void Update();
	void Draw();
	void Clean();

	void MoveUp();
	void MoveDown();
	void MoveLeft();
	void MoveRight();

	void ResetAnimation(int position);
	int GetLives() {return m_pLives;}
	int GetScore() {return m_pScore;}

	void LoseLife() {m_pLives--;printf("Lives: %d \n",m_pLives);}
	void AddPoint() {m_pScore++;printf("Score: %d \n",m_pScore);}
private:
	int m_pLives;
	int m_pScore;
	SDL_Surface* m_pSprite;
};

#endif /* PLAYER_H_ */
