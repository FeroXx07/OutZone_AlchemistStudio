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
	Animation Turret3__0;
	Animation Turret3__22_5;
	Animation Turret3__45;
	Animation Turret3__67_5;
	Animation Turret3__90;
	Animation Turret3__112_5;
	Animation Turret3__135;
	Animation Turret3__157_5;
	Animation Turret3__180;
	Animation Turret3__202_5;
	Animation Turret3__225;
	Animation Turret3__247_5;
	Animation Turret3__270;
	Animation Turret3__292_5;
	Animation Turret3__315;
	Animation Turret3__337_5;

public:

	Enemy_Turret3(int x, int y);

	void Move();
	void Shoot();
};

#endif // __ENEMY_TURRET1_H__