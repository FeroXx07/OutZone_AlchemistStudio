#ifndef __PURPLE_MACHINE_H__
#define __PURPLE_MACHINE_H__

#include "Enemy.h"

class Enemy_PurpleMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation PurpleMachine;
	int count;
public:

	Enemy_PurpleMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__