#ifndef __RED_MACHINE_H__
#define __RED_MACHINE_H__

#include "Enemy.h"

class Enemy_RedMachine : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;

	Animation RedMachine;

public:

	Enemy_RedMachine(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__