#ifndef __TURRET3_H__
#define __TURRET3_H__

#include "Enemy.h"

class Enemy_Turret3 : public Enemy
{

private:

	float wave = -1.0f;
	bool going_up = true;
	int original_y = 0;
	int original_x = 0;
	unsigned int lastTime = 0;
	Animation Turret3;

public:

	Enemy_Turret3(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__