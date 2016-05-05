#ifndef __ENEMY_TURRET2_H__
#define __ENEMY_TURRET2_H__

#include "Enemy.h"

class Enemy_Turret2 : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;

	Animation turret2;

public:

	Enemy_Turret2(int x, int y);

	void Move();
	void Shoot();

};

#endif // __ENEMY_TURRET1_H__