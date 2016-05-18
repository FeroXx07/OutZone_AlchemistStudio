#ifndef __BLUE_MACHINE_H__
#define __BLUE_MACHINE_H__

#include "Enemy.h"

class Enemy_BlueMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation BlueMachine;

public:

	Enemy_BlueMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__