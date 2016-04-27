#ifndef __ENEMY_DOOR_H__
#define __ENEMY_DOOR_H__

#include "Enemy.h"

class Enemy_Door : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;

	Animation Door;

public:

	Enemy_Door(int x, int y);

	void Move();

};

#endif // __ENEMY_DOOR_H__